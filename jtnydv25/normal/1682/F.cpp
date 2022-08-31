#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

// ModInt source: https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp
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

constexpr int md = 1000000007;
using mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// 0-indexed
template<class T>
struct segtree{
	int n;
	vector<T> t;
	T def;
	inline T combine(T a, T b){
		return a + b;
	}
	segtree(vector<T> inp) : n(sz(inp)){
		def = mint(0);
		t.resize(2 * n, def);
		for(int i = 0; i < n; i++) t[n + i] = inp[i];
		for(int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
	}

	void modify(int p, T value) { // modify a[p] = value
		value = combine(value, t[p + n]); // if a[p] = combine(a[p], value)
		for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
	}

	T query(int l, int r) {  // compute on interval [l, r]
	r++;
		T resl = def, resr = def;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = combine(resl, t[l++]);
			if (r&1) resr = combine(t[--r], resr);
		}
		return combine(resl, resr);
	}
};
const int mod = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, q; cin >> n >> q;
	vector<ll> a(n+1), b(n+1);
	vector<ll> x(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i > 1) x[i - 1] = a[i] - a[i - 1];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		b[i] += b[i - 1];
	}
	vector<int> perm(n + 1);
	iota(all(perm), 0);
	sort(all(perm), [&](int i, int j){return b[i] < b[j];});
	vector<mint> pref_xb(n+1), pref_x(n+1);
	for(int i = 1; i <= n; i++){
		pref_x[i] = pref_x[i - 1] + mint(x[i] % mod);
		pref_xb[i] = pref_xb[i - 1] + mint(x[i] % mod) * mint(b[i] % mod);
	}
	vector<mint> ans(q);
	vector<int> L(q), R(q);
	vector<vector<int>> at(n + 1);
	for(int i = 0; i < q; i++){
		cin >> L[i] >> R[i];
		R[i]--;
		
		at[L[i] - 1].push_back(i);
		ans[i] += pref_xb[R[i]] - pref_xb[L[i] - 1] - mint(b[L[i] - 1] % mod) * (pref_x[R[i]] - pref_x[L[i] - 1]);
	}

	segtree<mint> A(vector<mint>(n + 1));
	segtree<mint> B(vector<mint>(n + 1));
	// sum xi * |pi - p_{l-1}| i in [L, R]
	for(int i = 0; i <= n; i++){
		int j = perm[i];
		A.modify(j, x[j]);
		B.modify(j, mint(x[j] % mod) * mint(b[j] % mod));
		for(int r: at[j]){
			ans[r] += mint(2) * (mint(b[L[r] - 1] % mod) * A.query(L[r], R[r]) - B.query(L[r], R[r]));
		}
	}

	for(int i = 0; i < q; i++) cout << ans[i] << endl;
}