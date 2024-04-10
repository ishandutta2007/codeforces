#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;
template <int32_t P>
struct ModInt_t {
  constexpr static auto mod = P;

  int32_t value;

  static_assert(P < (1 << 30) - 1, "2xP must fit into 32-bit signed integer");

  ModInt_t() : value{0} {};

  constexpr explicit ModInt_t(int32_t v) : value(v) {
    if (value >= P || value <= -P) value %= P;
    if (value < 0) value += P;
  };

  constexpr explicit ModInt_t(int64_t v) {
    v %= P;
    if (v < 0) v += P;
    value = v;
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
bool operator==(const ModInt_t<P>& a, const ModInt_t<P>& b) {
  return a.value == b.value;
};

template <int32_t P>
std::ostream& operator<<(std::ostream& os, const ModInt_t<P>& a) {
  os << a.value;
  return os;
}

template <typename T>
struct MulMonoid {
  using value_type = T;
  constexpr static T identity() { return T{1}; }
  constexpr static T op(const T& a, const T& b) { return a * b; }
};

template <typename T, typename U, typename Monoid = MulMonoid<T>>
T power(T a, U n) {
  T r{Monoid::identity()};
  while (n > 0) {
    if (n % 2) r = Monoid::op(r, a);
    a = Monoid::op(a, a);
    n /= 2;
  }
  return r;
}

using ModInt = ModInt_t<998244353>;

namespace NTT {

constexpr int mod = 998244353;  // 2 ^ 23 * 17 * 7
using T = ModInt_t<mod>;

int g = 0;  // !

void findPrimitiveRoot() {
  if (g) return;

  vector<int> d;
  for (int i = 2; i * i <= mod - 1; ++i)
    if ((mod - 1) % i == 0) d.push_back(i), d.push_back((mod - 1) / i);
  for (g = 2;; g++) {
    bool ok = true;
    for (int x : d) ok &= !(power(T{g}, x) == T{1});
    if (ok) break;
  }
}

void transform(const T* a, T* z, const T* omega, int m, int N) {
  if (m == 1) {
    z[0] = a[0];
  } else {
    int s = N / m;
    m /= 2;

    transform(a, z, omega, m, N);
    transform(a + s, z + m, omega, m, N);

    for (int i = 0; i < m; ++i) {
      T c = omega[s * i] * z[m + i];
      z[m + i] = z[i] - c;
      z[i] = z[i] + c;
    }
  }
}

vector<T> fft(const vector<T>& a) {
  findPrimitiveRoot();

  int N = a.size();
  T w = power(T{g}, (mod - 1) / N);
  vector<T> omega(N);
  omega[0] = T{1};
  for (int i = 1; i < N; ++i) omega[i] = omega[i - 1] * w;

  vector<T> z(N);
  transform(a.data(), z.data(), omega.data(), N, N);
  return z;
}

vector<T> ifft(const vector<T>& a) {
  findPrimitiveRoot();

  int N = a.size();
  T wi = power(power(T{g}, (mod - 1) / N), mod - 2);
  vector<T> omega(N);
  omega[0] = T{1};
  for (int i = 1; i < N; ++i) omega[i] = omega[i - 1] * wi;

  vector<T> z(N);
  transform(a.data(), z.data(), omega.data(), N, N);

  T invN = power(T{N}, mod - 2);
  for (int i = 0; i < N; ++i) z[i] *= invN;
  return z;
}

vector<T> mult(vector<T> a, vector<T> b) {
  int N = a.size() + b.size();
  while (N & (N - 1)) ++N;

  a.resize(N);
  b.resize(N);

  vector<T> ta = fft(a);
  vector<T> tb = fft(b);
  for (int i = 0; i < N; ++i) ta[i] = ta[i] * tb[i];
  return ifft(ta);
}

void mult(const T* a, const T* b, T* c, int n) {
  vector<T> va(a, a + n);
  vector<T> vb(b, b + n);

  vector<T> cc = mult(std::move(va), std::move(vb));
  assert(cc.size() >= 2 * n - 1);
  std::copy(cc.begin(), cc.begin() + 2 * n - 1, c);
}

};  // namespace NTT

struct ModInverses {
  vector<ModInt> inv;

  ModInverses(int n) : inv(n, ModInt{0}) {
    auto mod = ModInt::mod;
    assert(n < mod);

    inv[1] = ModInt{1};
    for (int i = 2; i < n; ++i) {
      inv[i] = ModInt{0} - ModInt{mod / i} * inv[mod % i];
    }
  };
};

struct Factorial {
  vector<ModInt> fact;
  vector<ModInt> invfact;

  ModInt choose(int n, int k) { return fact[n] * invfact[k] * invfact[n - k]; }

  Factorial(int n) : fact(n, ModInt{0}), invfact(n, ModInt{0}) {
    ModInverses inv(n);

    fact[0] = invfact[0] = ModInt{1};
    for (int i = 1; i < n; ++i) {
      fact[i] = fact[i - 1] * ModInt{i};
      invfact[i] = invfact[i - 1] * inv.inv[i];
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  string a;
  cin >> a;

  Factorial f(n + 1);

  int co = 0, ce = 0;
  int no = 0, ne = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '?') {
      if (i % 2)
        no++;
      else
        ne++;
    } else if (a[i] == 'b') {
      if (i % 2)
        co++;
      else
        ce++;
    }
  }

  vector<ModInt> A(n + 1, ModInt{0});
  vector<ModInt> B(n + 1, ModInt{0});
  for (int x = 0; x <= no; ++x) {
    A[x] = f.choose(no, x);
  }
  for (int y = 0; y <= ne; ++y) {
    B[n - y] = f.choose(ne, y);
  }

  vector<ModInt> C = NTT::mult(A, B);
  ModInt num{0}, denom{0};
  for (int d = 0; d < 2 * n; ++d) {
    if (C[d].value) {
      int ad = abs(d + co - ce - n);
      if (ad % 2) continue;

      num += ModInt{ad / 2} * C[d];
      denom += C[d];
    }
  }

  cout << num * ModInt::inverse(denom) << '\n';
  return 0;
}