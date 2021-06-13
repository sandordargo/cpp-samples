#include <iostream>

class Num {
public:
  Num(int a) : m_a(a) {}
  friend std::ostream& operator<<(std::ostream& os, const Num& num) {
    os << num.m_a;
    return os;
  }
  Num operator++(int) {
      Num nm = *this;
      nm.m_a += 1;
      return m_a;
  }
  
  Num& operator++() {
      m_a += 1;
      return *this;
  }
private:
  int m_a;
};


class A {
public:
  Num* const func() const {
    Num* a = new Num{42};
    return a;
  }
};

int main() {
    A a;
    auto* num = a.func();
    std::cout << *num << '\n';
    ++(*num);
    std::cout << *num << '\n';
    num = new Num{666};
    std::cout << *num << '\n';
}
