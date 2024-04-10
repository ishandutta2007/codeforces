#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<unsigned int mod>
struct modular_fixed_base{
	template<class T>
	static vector<modular_fixed_base> precalc_power(T base, int SZ){
		vector<modular_fixed_base> res(SZ + 1, 1);
		for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
		return res;
	}
	static vector<modular_fixed_base> _INV;
	static void precalc_inverse(int SZ){
		if(_INV.empty()) _INV.assign(2, 1);
		for(auto x = _INV.size(); x <= SZ; ++ x) _INV.push_back(mod / x * -_INV[mod % x]);
	}
	// mod must be a prime
	static unsigned int _primitive_root;
	static unsigned int primitive_root(){
		if(_primitive_root) return _primitive_root;
		if(mod == 2) return _primitive_root = 1;
		if(mod == 998244353) return _primitive_root = 3;
		unsigned int divs[20] = {};
		divs[0] = 2;
		int cnt = 1;
		unsigned int x = (mod - 1) / 2;
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
				if((modular_fixed_base(g) ^ (mod - 1) / divs[i]) == 1){
					ok = false;
					break;
				}
			}
			if(ok) return _primitive_root = g;
		}
	}
	constexpr modular_fixed_base(): data(){ }
	modular_fixed_base(const double &x){ data = normalize(llround(x)); }
	modular_fixed_base(const long double &x){ data = normalize(llround(x)); }
	template<class T> modular_fixed_base(const T &x){ data = normalize(x); }
	template<class T> static unsigned int normalize(const T &x){
		int sign = x >= 0 ? 1 : -1;
		unsigned int v =  mod <= sign * x ? sign * x % mod : sign * x;
		if(sign == -1 && v) v = mod - v;
		return v;
	}
	const unsigned int &operator()() const{ return data; }
	template<class T> operator T() const{ return data; }
	modular_fixed_base &operator+=(const modular_fixed_base &otr){ if((data += otr.data) >= mod) data -= mod; return *this; }
	modular_fixed_base &operator-=(const modular_fixed_base &otr){ if((data += mod - otr.data) >= mod) data -= mod; return *this; }
	template<class T> modular_fixed_base &operator+=(const T &otr){ return *this += modular_fixed_base(otr); }
	template<class T> modular_fixed_base &operator-=(const T &otr){ return *this -= modular_fixed_base(otr); }
	modular_fixed_base &operator++(){ return *this += 1; }
	modular_fixed_base &operator--(){ return *this += mod - 1; }
	modular_fixed_base operator++(int){ modular_fixed_base result(*this); *this += 1; return result; }
	modular_fixed_base operator--(int){ modular_fixed_base result(*this); *this += mod - 1; return result; }
	modular_fixed_base operator-() const{ return modular_fixed_base(mod - data); }
	modular_fixed_base &operator*=(const modular_fixed_base &rhs){
		data = normalize((unsigned long long)data * rhs.data);
		return *this;
	}
	template<class T>
	modular_fixed_base &operator^=(T e){
		if(e < 0) *this = 1 / *this, e = -e;
		modular_fixed_base res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<class T>
	modular_fixed_base operator^(T e) const{
		return modular_fixed_base(*this) ^= e;
	}
	modular_fixed_base &operator/=(const modular_fixed_base &otr){
		int a = otr.data, m = mod, u = 0, v = 1;
		if(a < _INV.size()) return *this *= _INV[a];
		while(a){
			int t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	unsigned int data;
};
template<unsigned int mod>
vector<modular_fixed_base<mod>> modular_fixed_base<mod>::_INV;
template<unsigned int mod>
unsigned int modular_fixed_base<mod>::_primitive_root;
template<unsigned int mod> bool operator==(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return lhs.data == rhs.data; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> bool operator==(const modular_fixed_base<mod> &lhs, T rhs){ return lhs == modular_fixed_base<mod>(rhs); }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> bool operator==(T lhs, const modular_fixed_base<mod> &rhs){ return modular_fixed_base<mod>(lhs) == rhs; }
template<unsigned int mod> bool operator!=(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return !(lhs == rhs); }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> bool operator!=(const modular_fixed_base<mod> &lhs, T rhs){ return !(lhs == rhs); }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> bool operator!=(T lhs, const modular_fixed_base<mod> &rhs){ return !(lhs == rhs); }
template<unsigned int mod> bool operator<(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return lhs.data < rhs.data; }
template<unsigned int mod> bool operator>(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return lhs.data > rhs.data; }
template<unsigned int mod> bool operator<=(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return lhs.data <= rhs.data; }
template<unsigned int mod> bool operator>=(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return lhs.data >= rhs.data; }
template<unsigned int mod> modular_fixed_base<mod> operator+(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return modular_fixed_base<mod>(lhs) += rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator+(const modular_fixed_base<mod> &lhs, T rhs){ return modular_fixed_base<mod>(lhs) += rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator+(T lhs, const modular_fixed_base<mod> &rhs){ return modular_fixed_base<mod>(lhs) += rhs; }
template<unsigned int mod> modular_fixed_base<mod> operator-(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return modular_fixed_base<mod>(lhs) -= rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator-(const modular_fixed_base<mod> &lhs, T rhs){ return modular_fixed_base<mod>(lhs) -= rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator-(T lhs, const modular_fixed_base<mod> &rhs){ return modular_fixed_base<mod>(lhs) -= rhs; }
template<unsigned int mod> modular_fixed_base<mod> operator*(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs){ return modular_fixed_base<mod>(lhs) *= rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator*(const modular_fixed_base<mod> &lhs, T rhs){ return modular_fixed_base<mod>(lhs) *= rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator*(T lhs, const modular_fixed_base<mod> &rhs){ return modular_fixed_base<mod>(lhs) *= rhs; }
template<unsigned int mod> modular_fixed_base<mod> operator/(const modular_fixed_base<mod> &lhs, const modular_fixed_base<mod> &rhs) { return modular_fixed_base<mod>(lhs) /= rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator/(const modular_fixed_base<mod> &lhs, T rhs) { return modular_fixed_base<mod>(lhs) /= rhs; }
template<unsigned int mod, class T, enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<mod> operator/(T lhs, const modular_fixed_base<mod> &rhs) { return modular_fixed_base<mod>(lhs) /= rhs; }
template<unsigned int mod> istream &operator>>(istream &in, modular_fixed_base<mod> &number){
	long long x;
	in >> x;
	number.data = modular_fixed_base<mod>::normalize(x);
	return in;
}
// #define _PRINT_AS_FRACTION
template<unsigned int mod> ostream &operator<<(ostream &out, const modular_fixed_base<mod> &number){
#ifdef LOCAL
#ifdef _PRINT_AS_FRACTION
	for(auto d = 1; ; ++ d){
		if((number * d).data <= 1000000){
			out << (number * d).data << "/" << d;
			break;
		}
		else if((-number * d).data <= 1000000){
			out << "-" << (-number * d).data << "/" << d;
			break;
		}
	}
	return out;
#else
	return out << number();
#endif
#else
	return out << number();
#endif
}
#undef _PRINT_AS_FRACTION

// const unsigned int mod = 1e9 + 7; // 1000000007
const unsigned int mod = (119 << 23) + 1; // 998244353
// const unsigned int mod = 1e9 + 9; // 1000000009
using modular = modular_fixed_base<mod>;

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
		return n < 0 ? C(-n + k - 1, k) * (k & 1 ? -1 : 1) : n < k || k < 0 ? T() : fact[n] * invfact[k] * invfact[n - k];
	}
	// O(1)
	T P(int n, int k) const{
		return n < k ? T() : fact[n] * invfact[n - k];
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
		return n < k ? false : (n & k) == k;
	}
	// Number of ways to place n '('s and k ')'s starting with m copies of '(' such that in each prefix, number of '(' is equal or greater than ')'
	// Catalan(n, n, 0): n-th catalan number
	// O(1)
	T Catalan(int n, int k, int m = 0) const{
		assert(0 <= min({n, k, m}));
		return k <= m ? C(n + k, n) : k <= n + m ? C(n + k, n) - C(n + k, k - m - 1) : T();
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		combinatorics<modular> C(n);
		auto pow = modular::precalc_power(2, n);
		vector<modular> dp(n + 1);
		dp[0] = dp[1] = 1;
		for(auto x = 2; x <= n; ++ x){
			dp[x] = dp[x - 1] + dp[x - 2] * (x - 1);
		}
		modular res = 0, pref = 1;
		for(auto x = 0; x << 2 <= n; ++ x){
			res += pow[x] * dp[n - x * 4] * C.C(n - x * 2, x * 2) * pref;
			pref *= 2 * x + 1;
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////