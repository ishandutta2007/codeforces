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
ModInt_t<P> operator/(const ModInt_t<P>& a, const ModInt_t<P>& b) {
  return a * ModInt_t<P>::inverse(b);
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

namespace FWHT {

template <typename value_t>
void Transform(value_t* A, int n) {
  for (int i = 0; i < n; ++i) {
    for (int x = 0; x < (1 << n); ++x) {
      if (x & (1 << i)) continue;
      auto a = A[x];
      auto b = A[x | (1 << i)];
      A[x] = a + b;
      A[x | (1 << i)] = a - b;
    }
  }
}

template <typename value_t>
void InverseTransform(value_t* A, int n) {
  Transform(A, n);
  for (int i = 0; i < (1 << n); ++i) {
    A[i] = A[i] / value_t(1 << n);
  }
}

};  // namespace FWHT

const int MAX = 100100;

vector<int> E[MAX];
bool visited[MAX];
int g[MAX];
int h[MAX];
int cookie;

void dfs(int x) {
  if (visited[x]) return;
  visited[x] = true;

  for (int y : E[x]) {
    dfs(y);
  }

  cookie++;
  for (int y : E[x]) {
    h[g[y]] = cookie;
  }

  g[x] = 0;
  while (h[g[x]] == cookie) g[x]++;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
  }

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  int k = 0;
  while ((1 << k) < n) k++;

  vector<int> cnt(1 << k, 0);
  for (int i = 0; i < n; ++i) {
    assert(g[i] < (1 << k));
    cnt[g[i]]++;
  }

  vector<ModInt> x(1 << k);
  for (int i = 0; i < (1 << k); ++i) {
    x[i] = ModInt{cnt[i]};
  }

  FWHT::Transform(x.data(), k);
  for (int i = 0; i < (1 << k); ++i) {
    x[i] = ModInt::inverse(ModInt{n + 1} - x[i]);
  }
  FWHT::InverseTransform(x.data(), k);

  auto ans = ModInt{1} - x[0];
  cout << ans << '\n';
  return 0;
}