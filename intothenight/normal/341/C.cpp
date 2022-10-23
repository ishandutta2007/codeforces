#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

using uint = unsigned int;
template<uint _mod>
struct modular_fixed_base{
	static constexpr uint mod(){
		return _mod;
	}
	template<class T>
	static vector<modular_fixed_base> precalc_power(T base, int SZ){
		vector<modular_fixed_base> res(SZ + 1, 1);
		for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
		return res;
	}
	static vector<modular_fixed_base> _INV;
	static void precalc_inverse(int SZ){
		if(_INV.empty()) _INV.assign(2, 1);
		for(auto x = _INV.size(); x <= SZ; ++ x) _INV.push_back(_mod / x * -_INV[_mod % x]);
	}
	// _mod must be a prime
	static modular_fixed_base _primitive_root;
	static modular_fixed_base primitive_root(){
		if(_primitive_root) return _primitive_root;
		if(_mod == 2) return _primitive_root = 1;
		if(_mod == 998244353) return _primitive_root = 3;
		uint divs[20] = {};
		divs[0] = 2;
		int cnt = 1;
		uint x = (_mod - 1) / 2;
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
				if((modular_fixed_base(g) ^ (_mod - 1) / divs[i]) == 1){
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
	template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base(const T &x){ data = normalize(x); }
	template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> static uint normalize(const T &x){
		int sign = x >= 0 ? 1 : -1;
		uint v =  _mod <= sign * x ? sign * x % _mod : sign * x;
		if(sign == -1 && v) v = _mod - v;
		return v;
	}
	const uint &operator()() const{ return data; }
	template<class T> operator T() const{ return data; }
	modular_fixed_base &operator+=(const modular_fixed_base &otr){ if((data += otr.data) >= _mod) data -= _mod; return *this; }
	modular_fixed_base &operator-=(const modular_fixed_base &otr){ if((data += _mod - otr.data) >= _mod) data -= _mod; return *this; }
	template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base &operator+=(const T &otr){ return *this += modular_fixed_base(otr); }
	template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base &operator-=(const T &otr){ return *this -= modular_fixed_base(otr); }
	modular_fixed_base &operator++(){ return *this += 1; }
	modular_fixed_base &operator--(){ return *this += _mod - 1; }
	modular_fixed_base operator++(int){ modular_fixed_base result(*this); *this += 1; return result; }
	modular_fixed_base operator--(int){ modular_fixed_base result(*this); *this += _mod - 1; return result; }
	modular_fixed_base operator-() const{ return modular_fixed_base(_mod - data); }
	modular_fixed_base &operator*=(const modular_fixed_base &rhs){
		data = (unsigned long long)data * rhs.data % _mod;
		return *this;
	}
	template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr>
	modular_fixed_base &operator^=(T e){
		if(e < 0) *this = 1 / *this, e = -e;
		modular_fixed_base res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<class T, typename enable_if<is_integral<T>::value>::type* = nullptr>
	modular_fixed_base operator^(T e) const{
		return modular_fixed_base(*this) ^= e;
	}
	modular_fixed_base &operator/=(const modular_fixed_base &otr){
		int a = otr.data, m = _mod, u = 0, v = 1;
		if(a < _INV.size()) return *this *= _INV[a];
		while(a){
			int t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	uint data;
};
template<uint _mod> vector<modular_fixed_base<_mod>> modular_fixed_base<_mod>::_INV;
template<uint _mod> modular_fixed_base<_mod> modular_fixed_base<_mod>::_primitive_root;
template<uint _mod> bool operator==(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return lhs.data == rhs.data; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> bool operator==(const modular_fixed_base<_mod> &lhs, T rhs){ return lhs == modular_fixed_base<_mod>(rhs); }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> bool operator==(T lhs, const modular_fixed_base<_mod> &rhs){ return modular_fixed_base<_mod>(lhs) == rhs; }
template<uint _mod> bool operator!=(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return !(lhs == rhs); }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> bool operator!=(const modular_fixed_base<_mod> &lhs, T rhs){ return !(lhs == rhs); }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> bool operator!=(T lhs, const modular_fixed_base<_mod> &rhs){ return !(lhs == rhs); }
template<uint _mod> bool operator<(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return lhs.data < rhs.data; }
template<uint _mod> bool operator>(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return lhs.data > rhs.data; }
template<uint _mod> bool operator<=(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return lhs.data <= rhs.data; }
template<uint _mod> bool operator>=(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return lhs.data >= rhs.data; }
template<uint _mod> modular_fixed_base<_mod> operator+(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return modular_fixed_base<_mod>(lhs) += rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator+(const modular_fixed_base<_mod> &lhs, T rhs){ return modular_fixed_base<_mod>(lhs) += rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator+(T lhs, const modular_fixed_base<_mod> &rhs){ return modular_fixed_base<_mod>(lhs) += rhs; }
template<uint _mod> modular_fixed_base<_mod> operator-(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return modular_fixed_base<_mod>(lhs) -= rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator-(const modular_fixed_base<_mod> &lhs, T rhs){ return modular_fixed_base<_mod>(lhs) -= rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator-(T lhs, const modular_fixed_base<_mod> &rhs){ return modular_fixed_base<_mod>(lhs) -= rhs; }
template<uint _mod> modular_fixed_base<_mod> operator*(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs){ return modular_fixed_base<_mod>(lhs) *= rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator*(const modular_fixed_base<_mod> &lhs, T rhs){ return modular_fixed_base<_mod>(lhs) *= rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator*(T lhs, const modular_fixed_base<_mod> &rhs){ return modular_fixed_base<_mod>(lhs) *= rhs; }
template<uint _mod> modular_fixed_base<_mod> operator/(const modular_fixed_base<_mod> &lhs, const modular_fixed_base<_mod> &rhs) { return modular_fixed_base<_mod>(lhs) /= rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator/(const modular_fixed_base<_mod> &lhs, T rhs) { return modular_fixed_base<_mod>(lhs) /= rhs; }
template<uint _mod, class T, typename enable_if<is_integral<T>::value>::type* = nullptr> modular_fixed_base<_mod> operator/(T lhs, const modular_fixed_base<_mod> &rhs) { return modular_fixed_base<_mod>(lhs) /= rhs; }
template<uint _mod> istream &operator>>(istream &in, modular_fixed_base<_mod> &number){
	long long x;
	in >> x;
	number.data = modular_fixed_base<_mod>::normalize(x);
	return in;
}
// #define _PRINT_AS_FRACTION
template<uint _mod> ostream &operator<<(ostream &out, const modular_fixed_base<_mod> &number){
#ifdef LOCAL
#ifdef _PRINT_AS_FRACTION
	out << number();
	cerr << "(";
	for(auto d = 1; ; ++ d){
		if((number * d).data <= 1000000){
			cerr << (number * d).data << "/" << d;
			break;
		}
		else if((-number * d).data <= 1000000){
			cerr << "-" << (-number * d).data << "/" << d;
			break;
		}
	}
	cerr << ")";
	return out;
#else
	return out << number();
#endif
#else
	return out << number();
#endif
}
#undef _PRINT_AS_FRACTION

const uint mod = 1e9 + 7; // 1000000007
// const uint mod = (119 << 23) + 1; // 998244353
// const uint mod = 1e9 + 9; // 1000000009
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
	int n;
	cin >> n;
	combinatorics<modular> C(n);
	vector<array<int, 2>> flag(n);
	for(auto i = 0; i < n; ++ i){
		int j;
		cin >> j, -- j;
		if(j >= 0){
			flag[i][0] = true;
			flag[j][1] = true;
		}
	}
	array<int, 3> cnt{};
	for(auto i = 0; i < n; ++ i){
		if(!flag[i][0] && !flag[i][1]){
			++ cnt[0];
		}
		else if(!flag[i][0] || !flag[i][1]){
			++ cnt[flag[i][0] + 1];
		}
	}
	assert(cnt[1] == cnt[2]);
	modular res = 0;
	for(auto x = 0; x <= cnt[0]; ++ x){
		res += C.C(cnt[0], x) * (x & 1 ? -1 : 1) * C.fact[cnt[0] - x + cnt[1]];
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////