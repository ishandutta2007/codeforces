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

int rec_count(int sum, int maxSum, vector<int>& curr, int n, int k) {
  int ret = 0;
  if (sum > 0) {
    vector<int> a = curr, b;
    int aSum = sum;
    for (int i = 0; i < k - 1 && aSum <= n; ++i) {
      b.clear();
      aSum = 0;
      int c = 1;
      for (int j = (int)a.size() - 1; j >= 0; --j) {
        for (int cnt = 0; cnt < a[j]; ++cnt) {
          b.emplace_back(c);
        }
        aSum += a[j] * c;
        c++;
      }
      a.swap(b);
    }

    if (aSum > n) return 0;
    ret++;
  }

  int start = curr.size() ? curr.back() : 1;
  curr.emplace_back(0);
  for (int x = start; sum + x <= maxSum; ++x) {
    curr.back() = x;
    int rc = rec_count(sum + x, maxSum, curr, n, k);
    if (rc == 0) break;
    ret += rc;
  }
  curr.pop_back();
  return ret;
}

ModInt solve(int n, int k) {
  constexpr static int MAX = 64;

  if (k >= 10) return ModInt{1};

  if (k == 1) {
    vector<ModInt> f(n + 1, ModInt{0});
    f[0] = ModInt{1};
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j + i <= n; ++j) {
        f[i + j] += f[j];
      }
    }
    auto ret = accumulate(f.begin(), f.end(), ModInt{0}) - ModInt{1};
    return ret;
  }

  if (k == 2) {
    vector<ModInt> f(n + 1, ModInt{0});
    f[0] = ModInt{1};
    for (int i = 1; i <= n; ++i) {
      int k = i * (i + 1) / 2;
      for (int j = 0; j + k <= n; ++j) {
        f[k + j] += f[j];
      }
    }
    auto ret = accumulate(f.begin(), f.end(), ModInt{0}) - ModInt{1};
    return ret;
  }

  assert(k >= 3);
  vector<int> v;
  return ModInt{rec_count(0, MAX, v, n, k)};
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  cout << solve(n, k).value << "\n";
  return 0;
}