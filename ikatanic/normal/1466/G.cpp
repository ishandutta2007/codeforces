#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
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

namespace Hash {

using Mod1 = ModInt_t<1000000007>;
using Mod2 = ModInt_t<1000000003>;

constexpr int H = 9973;
constexpr auto HM1 = Mod1{H};
constexpr auto HM2 = Mod2{H};

// this is necessary for offset function
const auto HI1 = Mod1::inverse(HM1 - Mod1{1});
const auto HI2 = Mod2::inverse(HM2 - Mod2{1});

const int MAX = 3e6;

static Mod1 pw1[MAX];
static Mod2 pw2[MAX];

void init() {
  pw1[0] = Mod1{1};
  pw2[0] = Mod2{1};
  for (int i = 1; i < MAX; ++i) {
    pw1[i] = pw1[i - 1] * HM1;
    pw2[i] = pw2[i - 1] * HM2;
  }
}

struct t {
  Mod1 h1;
  Mod2 h2;
  int len;
  friend bool operator<(const t& a, const t& b) {
    return std::tie(a.len, a.h1.value, a.h2.value) <
           std::tie(b.len, b.h1.value, b.h2.value);
  }
  friend bool operator==(const t& a, const t& b) {
    return std::tie(a.len, a.h1.value, a.h2.value) ==
           std::tie(b.len, b.h1.value, b.h2.value);
  }
};

t empty() { return {.h1 = Mod1{0}, .h2 = Mod2{0}, .len = 0}; }

t singleton(i64 c) { return {.h1 = Mod1{c}, .h2 = Mod2{c}, .len = 1}; }

t append(t h, i64 c) {
  h.h1 = h.h1 * HM1 + Mod1{c};
  h.h2 = h.h2 * HM2 + Mod2{c};
  h.len++;
  return h;
}

t concat(t a, t b) {
  a.h1 = a.h1 * pw1[b.len] + b.h1;
  a.h2 = a.h2 * pw2[b.len] + b.h2;
  a.len += b.len;
  return a;
}

t chop_prefix(t a, t b) {
  a.h1 -= b.h1 * pw1[a.len - b.len];
  a.h2 -= b.h2 * pw2[a.len - b.len];
  a.len -= b.len;
  return a;
}

t offset(t a, i64 c) {  // offset all elements by c
  auto sumPw1 = (pw1[a.len] - Mod1{1}) * HI1;
  auto sumPw2 = (pw2[a.len] - Mod2{1}) * HI2;
  a.h1 += Mod1{c} * sumPw1;
  a.h2 += Mod2{c} * sumPw2;
  return a;
}
};  // namespace Hash

struct SubstringHash {
  SubstringHash(const std::string& s) {
    int m = s.size();
    pref.resize(m + 1);
    pref[0] = Hash::empty();
    for (int i = 0; i < m; ++i) {
      pref[i + 1] = Hash::append(pref[i], s[i]);
    }
  };

  Hash::t substring(int a, int b) {
    return Hash::chop_prefix(pref[b], pref[a]);
  }

  vector<Hash::t> pref;
};

int main() {
  ios_base::sync_with_stdio(false);

  Hash::init();

  int n, q;
  cin >> n >> q;
  string s0, t;
  cin >> s0 >> t;

  using ModInt = ModInt_t<1000000007>;

  vector<ModInt> ws(n + 1);
  vector<ModInt> iws(n + 1);
  ws[0] = ModInt{1};
  iws[0] = ModInt{1};
  ModInt inv2 = ModInt::inverse(ModInt{2});
  for (int j = 0; j < n; ++j) {
    ws[j + 1] = ws[j] * ModInt{2};
    iws[j + 1] = iws[j] * inv2;
  }

  vector<vector<ModInt>> sumw(26);
  for (int c = 0; c < 26; ++c) {
    sumw[c].resize(n + 1);
    sumw[c][0] = ModInt{0};
    for (int i = 1; i <= n; ++i) {
      sumw[c][i] = sumw[c][i - 1];
      if (t[i - 1] - 'a' == c) {
        sumw[c][i] += iws[i];
      }
    }
  }

  auto solve = [&](int qi, const std::string& w) -> ModInt {
    string s = s0;

    int clen = s.size();
    int ci = 0;

    while (ci < n && clen < w.size()) {
      s.resize(2 * clen + 1);
      s[clen] = t[ci];
      std::copy(s.begin(), s.begin() + clen, s.begin() + clen + 1);
      clen = clen * 2 + 1;
      ci++;
    }
    if (qi < ci) return ModInt{0};

    SubstringHash hs(s);
    SubstringHash hq(w);

    int m = w.size();
    int zero_cnt = 0;
    for (int i = 0; i + m <= clen; ++i) {
      if (hs.substring(i, i + m) == hq.substring(0, m)) zero_cnt++;
    }

    auto ans = ModInt{zero_cnt} * iws[ci];

    for (int k = 0; k < m; ++k) {
      if (k <= clen && hq.substring(0, k) == hs.substring(clen - k, clen) &&
          hq.substring(k + 1, m) == hs.substring(0, m - k - 1)) {
        int c = w[k] - 'a';
        ans += sumw[c][qi] - sumw[c][ci];
      }
    }

    ans *= ws[qi];
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    int x;
    std::string w;
    cin >> x >> w;

    auto ans = solve(x, w);
    cout << ans << '\n';
  }
  return 0;
}