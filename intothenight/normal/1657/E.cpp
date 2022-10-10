#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<typename T>
struct modular_base{
	using Type = typename decay<decltype(T::value)>::type;
	template<class U>
	static vector<modular_base<T>> precalc_power(U base, size_t SZ){
		vector<modular_base<T>> res(SZ + 1, 1);
		for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
		return res;
	}
	static vector<Type> _INV;
	static void precalc_inverse(size_t SZ){
		if(_INV.empty()) _INV.assign(2, 1);
		for(auto x = (int)_INV.size(); x <= SZ; ++ x) _INV.push_back((mod() - 1LL * mod() / x * _INV[mod() % x]) % mod());
	}
	// mod must be a prime
	static Type _primitive_root;
	static modular_base<T> primitive_root(){
		if(_primitive_root) return _primitive_root;
		if(mod() == 2) return _primitive_root = 1;
		if(mod() == 998244353) return _primitive_root = 3;
		Type divs[20] = {};
		divs[0] = 2;
		int cnt = 1;
		Type x = (mod() - 1) / 2;
		while(x % 2 == 0) x /= 2;
		for(auto i = 3; 1LL * i * i <= x; i += 2){
			if(x % i == 0){
				divs[cnt ++] = i;
				while(x % i == 0) x /= i;
			}
		}
		if(x > 1) divs[cnt ++] = x;
		for(auto g = 2; ; ++ g){
			bool ok = true;
			for(auto i = 0; i < cnt; ++ i){
				if((modular_base<T>(g) ^ (mod() - 1) / divs[i]) == 1){
					ok = false;
					break;
				}
			}
			if(ok) return _primitive_root = g;
		}
	}
	constexpr modular_base(): value(){ }
	modular_base(const double &x){ value = normalize(llround(x)); }
	modular_base(const long double &x){ value = normalize(llround(x)); }
	template<typename U> modular_base(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return value; }
	constexpr static Type mod(){ return T::value; }
	modular_base &operator+=(const modular_base &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	modular_base &operator-=(const modular_base &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> modular_base &operator+=(const U &otr){ return *this += modular_base(otr); }
	template<typename U> modular_base &operator-=(const U &otr){ return *this -= modular_base(otr); }
	modular_base &operator++(){ return *this += 1; }
	modular_base &operator--(){ return *this -= 1; }
	modular_base operator++(int){ modular_base result(*this); *this += 1; return result; }
	modular_base operator--(int){ modular_base result(*this); *this -= 1; return result; }
	modular_base operator-() const{ return modular_base(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename modular_base<U>::Type, int>::value, modular_base>::type &operator*=(const modular_base& rhs){
		#ifdef _WIN32
		unsigned long long x = static_cast<long long>(value) * static_cast<long long>(rhs.value);
		unsigned int xh = static_cast<unsigned int>(x >> 32), xl = static_cast<unsigned int>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		#else
		value = normalize(static_cast<long long>(value) * static_cast<long long>(rhs.value));
		#endif
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename modular_base<U>::Type, long long>::value, modular_base>::type &operator*=(const modular_base &rhs){
		long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename modular_base<U>::Type>::value, modular_base>::type &operator*=(const modular_base &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	template<typename U>
	modular_base &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		modular_base res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	modular_base operator^(U e) const{
		return modular_base(*this) ^= e;
	}
	modular_base &operator/=(const modular_base &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)_INV.size()) return *this *= _INV[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	Type value;
};
template<typename T>
vector<typename std::decay<decltype (T::value)>::type> modular_base<T>::_INV;
template<typename T>
typename std::decay<decltype (T::value)>::type modular_base<T>::_primitive_root;
template<typename T> bool operator==(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const modular_base<T>& lhs, U rhs){ return lhs == modular_base<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) == rhs; }
template<typename T> bool operator!=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const modular_base<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> modular_base<T> operator+(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(const modular_base<T> &lhs, U rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T> modular_base<T> operator-(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T> modular_base<T> operator*(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T> modular_base<T> operator/(const modular_base<T> &lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(const modular_base<T>& lhs, U rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(U lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, modular_base<T> &number){
	typename common_type<typename modular_base<T>::Type, long long>::type x;
	in >> x;
	number.value = modular_base<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const modular_base<T> &number){ return out << number(); }

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using modular = modular_base<VarMod>;
*/

// constexpr int mod = 1e9 + 7; // 1000000007
constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using modular = modular_base<integral_constant<decay<decltype(mod)>::type, mod>>;

template<class T>
struct combinatorics{
	int SZ = 0;
	vector<T> inv, fact, invfact;
	combinatorics(){ }
	// O(n * m)
	vector<vector<T>> precalc_C(int n, int m) const{
		vector<vector<T>> c(n + 1, vector<T>(m + 1));
		for(auto i = 0; i <= n; ++ i) for(auto j = 0; j <= min(i, m); ++ j) c[i][j] = i && j ? c[i - 1][j - 1] + c[i - 1][j] : 1;
		return c;
	}
	// O(SZ)
	combinatorics(int SZ): SZ(SZ), inv(SZ + 1, 1), fact(SZ + 1, 1), invfact(SZ + 1, 1){
		for(auto i = 1; i <= SZ; ++ i) fact[i] = fact[i - 1] * i;
		invfact[SZ] = 1 / fact[SZ];
		for(auto i = SZ - 1; i >= 0; -- i){
			invfact[i] = invfact[i + 1] * (i + 1);
			inv[i + 1] = invfact[i + 1] * fact[i];
		}
	}
	// O(1)
	T C(int n, int k) const{
		return n < 0 ? C(-n + k - 1, k) * (k & 1 ? -1 : 1) : n < k || k < 0 ? 0 : fact[n] * invfact[k] * invfact[n - k];
	}
	// O(1)
	T P(int n, int k) const{
		return n < k ? 0 : fact[n] * invfact[n - k];
	}
	// O(1)
	T H(int n, int k) const{
		return C(n + k - 1, k);
	}
	// O(min(k, n - k))
	T naive_C(long long n, long long k) const{
		if(n < k) return 0;
		T res = 1;
		k = min(k, n - k);
		for(auto i = n; i > n - k; -- i) res *= i;
		return res * invfact[k];
	}
	// O(k)
	T naive_P(long long n, int k) const{
		if(n < k) return 0;
		T res = 1;
		for(auto i = n; i > n - k; -- i) res *= i;
		return res;
	}
	// O(k)
	T naive_H(long long n, int k) const{
		return naive_C(n + k - 1, k);
	}
	// O(1)
	bool parity_C(long long n, long long k) const{
		return n < k ? 0 : (n & k) == k;
	}
	// Number of ways to place n '('s and k ')'s starting with m copies of '(' such that in each prefix, number of '(' is equal or greater than ')'
	// Catalan(n, n, 0): n-th catalan number
	// O(1)
	T Catalan(int n, int k, int m = 0) const{
		assert(0 <= min({n, k, m}));
		return k <= m ? C(n + k, n) : k <= n + m ? C(n + k, n) - C(n + k, k - m - 1) : 0;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<vector<modular>> power(k + 1);
	for(auto w = 1; w <= k; ++ w){
		power[w] = modular::precalc_power(w, n * (n + 1) / 2);
	}
	combinatorics<modular> C(n + k);
	vector<vector<modular>> dp(n, vector<modular>(k + 1));
	vector<vector<modular>> pref(n, vector<modular>(k + 2));
	dp[0][0] = 1;
	ranges::fill(pref[0] | ranges::views::drop(1), 1);
	for(auto i1 = 1; i1 < n; ++ i1){
		for(auto j1 = 1; j1 <= k; ++ j1){
			for(auto i2 = 0; i2 < i1; ++ i2){
				dp[i1][j1] +=
					pref[i2][j1] *
					C.C(i1, i2) *
					power[k + 1 - j1][i2 * (i1 - i2) + (i1 - i2) * (i1 - i2 - 1) / 2];
			}
			pref[i1][j1 + 1] = pref[i1][j1] + dp[i1][j1];
		}
	}
	cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), modular(0)) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////