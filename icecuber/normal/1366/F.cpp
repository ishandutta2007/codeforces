#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// Modular template copied from tourist

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

const int nax = 2e3+10;
ll dp[nax][nax];

vector<tuple<int,int,int>> node[nax];

void self_max(ll&a, ll b) {
  a = max(a, b);
}

ll eval(array<ll,2> line, ll x) {
  return line[0]*x+line[1];
}

ll firstBetter(array<ll,2> a, array<ll,2> b) {
  assert(a[0] < b[0]);
  ll pass = 2e12, fail = -2e12;
  while (pass-fail > 1) {
    ll mid = (pass+fail)/2;
    if (eval(a, mid) < eval(b, mid)) pass = mid;
    else fail = mid;
  }
  return pass;
}

int check(array<ll,2> a, array<ll,2> b, array<ll,2> c) {
  return firstBetter(a, b) < firstBetter(b, c);
}

Mint sum(ll s, ll e, Mint a, Mint b) {
  return Mint(e-s+1)*(b+(s+e)*a/2);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;

  int maxd = n;
  vector<ll> ans(maxd+1), score(m, -1e18);
  vector<int> ind(m), slope(m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].emplace_back(b, c, i);
    node[b].emplace_back(a, c, i);
    slope[i] = c;
  }

  auto add = [&](int ei, int l, ll base) {
    while (ind[ei] < l) {
      self_max(ans[ind[ei]], score[ei]);
      score[ei] += slope[ei];
      ind[ei]++;
    }
    self_max(score[ei], base);
    self_max(ans[ind[ei]], score[ei]);
  };

  fill_n(dp[0], n, -1e18);
  dp[0][0] = 0;
  for (int l = 1; l <= maxd; l++) {
    for (int i = 0; i < n; i++) {
      dp[l][i] = -1e18;
      for (auto [j, c, ei] : node[i]) {
	self_max(dp[l][i], dp[l-1][j]+c);
      }
    }
    for (int i = 0; i < n; i++) {
      for (auto [j, c, ei] : node[i]) {
	add(ei, l, dp[l][j]);
      }
    }
  }

  Mint total = 0;
  for (int i = 1; i <= min(maxd, q); i++) {
    total += ans[i];
  }

  vector<array<ll,2>> line;
  for (int i = 0; i < m; i++) {
    assert(ind[i] == maxd);
    line.push_back({slope[i], score[i]});
  }
  sort(line.begin(), line.end());
  vector<array<ll,2>> filtered;
  for (auto [a,b] : line) {
    while ((filtered.size() && filtered.back()[0] == a) ||
	   ((int)filtered.size() >= 2 && !check(filtered.end()[-2], filtered.end()[-1], {a,b})))
      filtered.pop_back();
    filtered.push_back({a,b});
  }

  ll x = 0;
  int j = 0;
  while (x < q-maxd) {
    while (j+1 < (int)filtered.size() && eval(filtered[j+1], x+1) >= eval(filtered[j], x+1)) j++;
    ll nx = q-maxd;
    if (j+1 < (int)filtered.size())
      nx = min(nx, firstBetter(filtered[j], filtered[j+1])-1);
    total += sum(x+1, nx, filtered[j][0], filtered[j][1]);
    //for (ll i = x+1; i <= nx; i++)
    //  total += eval(filtered[j], i);
    x = nx;
  }
  /*for (int i = maxd+1; i <= q; i++) {
    total += ans[i];
    }*/
  cout << total << endl;
}