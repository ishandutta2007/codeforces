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

vector<string> brute(string s) {
  set<string> r = {string(1,s[0])};
  for (int si = 1; si < (int)s.size(); si++) {
    char c = s[si];
    set<string> nr;
    for (string i : r) {
      nr.insert(i+c);
      if (c == '0')
	nr.insert(i);
      else {
	i.back() = '1';
	nr.insert(i);
      }
    }
    r = nr;
  }
  vector<string> ret;
  for (string i : r) {
    //if (i.size() > 1)
    ret.push_back(i);
  }
  return ret;
}

Mint solve(string s) {
  Mint last0 = 0, last1 = 1;
  ll streak = 1e9;
  vector<tuple<ll,Mint,Mint>> mem = {{(ll)1e18, 0, 1}};
  Mint prev = 0;
  for (char c : s) {
    Mint pred;
    if (c == '0') {
      pred = prev+last1;
      streak++;
    } else {
      while (get<0>(mem.back()) < streak) mem.pop_back();
      auto [m0, m1, m2] = mem.back();
      pred = prev+m1*streak+m2;
      if (streak <= m0)
	mem.push_back({streak,-last0,pred});
      streak = 1;
      last0 = last1 = pred;
    }
    prev = pred;
  }
  return prev;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  cout << solve(s) << endl;

  return 0;
  for (int it = 0; it < 1000; it++) {
    string s;// = "00101100011100";//"0101";
    mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < 10; i++)
      s.push_back('0'+(mrand()%2 && i));
    assert((int)brute(s).size() == solve(s));
    continue;
    vector<ll> dp(1);
  ll last = 0, last1 = 1;
  ll streak = 1e9;
  vector<array<ll,3>> mem = {{(ll)1e18, 0, 1}};
  for (int i = 1; i <= (int)s.size(); i++) {
    auto st = brute(s.substr(0,i));
    //cout << i << ' ' << s[i-1] << ' ' << st.size();
    //if (s[i-1] == '1') cout << ' ' << st.size()-prev << ' ' << st.size()-last;

    ll pred;
    if (s[i-1] == '0') {
      pred = dp[i-1]+last1;
      //assert(dp[i] == dp[i-1]+last1);
      streak++;
    } else {
      while (mem.back()[0] < streak) mem.pop_back();
      ll val = dp[i-1]+mem.back()[1]*streak+mem.back()[2];
      pred = val;
      //assert(dp[i] == val);
      //cout << " | " << val-dp[i-1] << ' ' << dp[i]-dp[i-1];
      if (streak <= mem.back()[0])
	mem.push_back({streak, -last, val});
      streak = 1;
      //if (i > 2)
      //	assert(dp[i-1] == dp[i-2]+dp[i-3]-last);
      last = pred;
      last1 = pred;
    }
    //cout << endl;
    assert(pred == (int)st.size());

    dp.push_back(st.size());

      /*for (string r : st)
      cout << r << ' ';
      cout << endl;*/
  }
  }
  return 0;
  /*
  cin >> s;
  Mint last = 0;
  Mint f0 = 0, f1 = 1;
  for (char c : s) {
    if (c == '0') {
      tie(f0, f1) = make_pair(f0+f1,f1);
    } else {
      Mint tmp = f1;
      tie(f0, f1) = make_pair(0,f1*2+f0-last);
      last = tmp;
    }
  }
  cout << f0+f1-1 << endl;*/
}