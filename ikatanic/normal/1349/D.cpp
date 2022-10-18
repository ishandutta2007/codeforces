#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

template <int32_t P>
struct ModInt_t {
  int32_t value;

  static_assert(P < (1 << 30) - 1, "2xP must fit into 32-bit signed integer");

  ModInt_t() : value{0} {};

  explicit ModInt_t(int32_t v) : value(v) {
    if (value >= P || value <= -P) value %= P;
    if (value < 0) value += P;
  };

  explicit operator bool() const { return value != 0; }
  explicit operator int32_t() const { return value; }

  ModInt_t& operator+=(const ModInt_t& other) {
    value += other.value;
    if (value >= P) value -= P;
    return *this;
  }

  ModInt_t& operator-=(const ModInt_t& other) {
    value -= other.value;
    if (value < 0) value += P;
    return *this;
  }

  ModInt_t& operator*=(const ModInt_t& other) {
    int64_t result = static_cast<int64_t>(value) * other.value;
    value = static_cast<int32_t>(result % P);
    return *this;
  }

  ModInt_t& operator/=(const ModInt_t& other) {
    return *this *= inverse(other);
  }
  static ModInt_t inverse(ModInt_t x) { return ModInt_t{inverse(x.value)}; }

 private:
  static int32_t inverse(int32_t a) {
    int32_t b = P, x = 1, y = 0;
    while (b != 0) {
      auto k = a / b;
      a -= k * b;
      std::swap(a, b);
      x -= k * y;
      std::swap(x, y);
    }
    assert(a == 1);
    if (x < 0) x += P;
    return x;
  }
};

template <int32_t P>
ModInt_t<P> operator+(const ModInt_t<P>& a, const ModInt_t<P>& b) {
  auto res = a;
  return res += b;
};

template <int32_t P>
ModInt_t<P> operator-(const ModInt_t<P>& a, const ModInt_t<P>& b) {
  auto res = a;
  return res -= b;
};

template <int32_t P>
ModInt_t<P> operator*(const ModInt_t<P>& a, const ModInt_t<P>& b) {
  auto res = a;
  return res *= b;
};

template <int32_t P>
ModInt_t<P> operator/(const ModInt_t<P>& a, const ModInt_t<P>& b) {
  auto res = a;
  return res /= b;
};

template <int32_t P>
bool operator==(const ModInt_t<P>& a, const ModInt_t<P>& b) {
  return a.value == b.value;
};

template <int32_t P>
std::ostream& operator<<(std::ostream& os, const ModInt_t<P>& a) {
  os << a.value;
  return os;
}

using ModInt = ModInt_t<998244353>;

template <typename T>
T solve(vector<int>& A) {
  int N = A.size();
  int S = accumulate(A.begin(), A.end(), 0);

  vector<T> f(S + 1);
  f[0] = T{N - 1};
  for (int m = 1; m < S; ++m) {
    auto s = T{S};
    auto mm = T{m};
    auto p = (s - mm) / s / T{N - 1};
    auto r = mm / s;
    f[m] = (T{1} + r * f[m - 1]) / p;
  }

  vector<T> g(S + 1);
  g[S] = T{0};
  for (int i = S - 1; i >= 0; --i) {
    g[i] = g[i + 1] + f[i];
  }

  auto C = g[0];
  auto total = T{0};
  for (int x : A) {
    total += g[x];
  }

  auto ret = (total - T{N - 1} * C) / T{N};
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  auto ret = solve<ModInt>(A);
  cout << ret << '\n';
  return 0;
}