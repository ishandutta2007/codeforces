#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


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


const int nax = 1e5+10;
vector<pair<int,int>> node[nax];

int depth[nax], xat[nax], rem[nax], mate[nax], out[nax], mout[nax];
vector<int> has[nax];

void dfs(vector<int>&v, int p, int par = -1, int d = 1, int x = 0) {
  //cout << p+1 << ' ' << par+1 << endl;
  if (rem[p]) return;
  if (depth[p]) {
    if (d > depth[p])
      v.push_back(x^xat[p]);
    return;
  }
  xat[p] = x;
  depth[p] = d;
  for (auto [i,w] : node[p]) {
    if (i == par || rem[i]) continue;
    dfs(v, i, p, d+1, x^w);
  }
}


struct Reduced {
  vector<int> row;
  Reduced operator+(int m) const {
    if (row == vector<int>({0})) return {{0}};
    Reduced r = {row};
    for (int v : row) {
      int first = 31-__builtin_clz(v);
      if (m>>first&1)
	m ^= v;
    }
    if (!m) return {{0}};
    {
      int first = 31-__builtin_clz(m);
      for (int&v : r.row) {
	if (v>>first&1)
	  v ^= m;
      }
      r.row.push_back(m);
    }
    sort(r.row.rbegin(), r.row.rend());
    return r;
  }
  bool operator<(const Reduced&other) const {
    return row < other.row;
  }
};
ostream& operator<<(ostream&cout, const Reduced&r) {
  for (int v : r.row)
    cout << bitset<5>(v) << endl;
  return cout;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].emplace_back(b, c);
    node[b].emplace_back(a, c);
  }

  vector<int> adj0(n);
  for (auto [i,w] : node[0]) {
    adj0[i] = 1;
    out[i] = w;
  }

  rem[0] = 1;
  for (auto [i,w] : node[0]) {
    assert(out[i] == w);
    mate[i] = -1;
    for (auto [j,c] : node[i])
      if (adj0[j]) {
	assert(mate[i] == -1);
	mate[i] = j;
	mout[i] = c;
      }

    if (mate[i] != -1)
      rem[mate[i]] = 1;
    dfs(has[i], i);
    //cout << has[i].size() << endl;
    if (mate[i] != -1)
      rem[mate[i]] = 0;
  }

  map<Reduced,int> comp;
  vector<Reduced> y;
  comp[{}];
  queue<Reduced> q;
  q.push({});
  while (q.size()) {
    Reduced r = q.front();
    q.pop();
    for (int v = 0; v < 32; v++) {
      Reduced i = r+v;
      if (!comp.count(i)) {
	comp[i];
	q.push(i);
      }
    }
  }
  int equivs = 0;
  for (auto&[p,i] : comp) {
    y.push_back(p);
    i = equivs++;
  }

  /*cout << equivs << endl;
  for (int i = 0; i < 10; i++)
  cout << y[i] << endl;*/

  vector<vector<int>> mem(equivs, vector<int>(32, -1));
  auto merge = [&](int i, int j) {
    if (mem[i][j] == -1) {
      mem[i][j] = comp[y[i]+j];
    }
    return mem[i][j];
  };

  auto add = [&](int i, vector<int>&v) {
    for (int j : v) {
      i = merge(i, j);
    }
    return i;
  };

  vector<Mint> dp(equivs);
  dp[comp[{}]] = 1;
  for (int i = 0; i < n; i++) {
    vector<Mint> ndp = dp;
    if (adj0[i]) {
      if (mate[i] == -1) {
	for (int k = 0; k < equivs; k++) {
	  /*if (dp[k] && has[i].size()) {
	    cout << ": " << endl;
	    cout << y[k] << endl;
	    cout << (y[k]+has[i][0]) << endl;
	    cout << y[add(k, has[i])] << endl;
	    }*/
	  ndp[add(k, has[i])] += dp[k];
	}
      } else if (i < mate[i]) {
	assert(mate[mate[i]] == i);
	vector<int>&a = has[i];
	vector<int>&b = has[mate[i]];
	int t = out[i] ^ out[mate[i]] ^ mout[i];

	for (int k = 0; k < equivs; k++) {
	  int sum = add(add(k, a), b);
	  ndp[sum] += dp[k]*2;
	  ndp[merge(sum, t)] += dp[k];
	}
      }
    }
    swap(dp, ndp);
  }
  Mint ans = 0;
  for (int i = 0; i < equivs; i++) {
    if (merge(i, 0) != i)
      ans += dp[i];
  }
  cout << ans << endl;
}