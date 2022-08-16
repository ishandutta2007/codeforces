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

constexpr int md = 998244353;
using mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

const int N = 1000006;
mint fact[N], invfact[N];

void pre(){
	fact[0] = 1;
	for(int i = 1; i < N; i++){
		fact[i] = i * fact[i - 1];
	}
	invfact[N - 1] = 1 / fact[N - 1];
	for(int i = N - 2; i >= 0; i--){
		invfact[i] = (i + 1) * invfact[i + 1];
	}
	assert(invfact[0] == 1);
}

mint C(int n, int k){
	if(n < k || k < 0) return 0;
	return fact[n] * invfact[k] * invfact[n - k];
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	pre();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<mint> num(n + 1);
		vector<int> freq(n);
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			freq[--a[i]]++;
		}
		vector<int> non_zero;
		int g_non_zero = n;
		for(int i = 0; i < n; i++) if(freq[i]){
			non_zero.push_back(i);
			g_non_zero = __gcd(g_non_zero, freq[i]);
		}
		if(sz(non_zero) == 1){
			cout << 1 << endl;
			continue;
		}
		mint sum = 0;
		mint total = 0;
		for(int d = 0; d < n; d++){
			int g = __gcd(d, n);
			// trace(d, n, g);
			if(g == 1) continue;
			int r = n / g;
			if(g_non_zero % r == 0){
				mint ways = fact[g];
				mint sm = 0;
				for(int h: non_zero){
					int f = freq[h] / r;
					ways *= invfact[f];
					sm += mint(f) * (f - 1);
				}
				sm *= ways;
				sm /= (mint(g) * mint(g - 1));
				sum += ways * n - sm * n;
				total += ways;
			}
		}
		// trace(total, sum);
		cout << (sum / total) << endl;
	}
}