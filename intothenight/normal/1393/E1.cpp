#include "bits/stdc++.h"
using namespace std;

template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> mod_inv; 
	constexpr Z_p(): value(){ }
	template<typename U> Z_p(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	Z_p &operator+=(const Z_p &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	Z_p &operator-=(const Z_p &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> Z_p &operator+=(const U &otr){ return *this += Z_p(otr); }
	template<typename U> Z_p &operator-=(const U &otr){ return *this -= Z_p(otr); }
	Z_p &operator++(){ return *this += 1; }
	Z_p &operator--(){ return *this -= 1; }
	Z_p operator++(int){ Z_p result(*this); *this += 1; return result; }
	Z_p operator--(int){ Z_p result(*this); *this -= 1; return result; }
	Z_p operator-() const{ return Z_p(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type& operator*=(const Z_p& rhs){
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
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type& operator*=(const Z_p &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type& operator*=(const Z_p &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	Z_p operator^(long long e) const{
		Z_p b = *this, res = 1;
		if(e < 0) b = 1 / b, e = -e;
		for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
		return res;
	}
	Z_p &operator^=(const long long &e){ return *this = *this ^ e; }
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < int(mod_inv.size())) return *this *= mod_inv[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
	template<typename U> friend bool operator==(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend bool operator<(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend istream &operator>>(istream &in, Z_p<U> &number);
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, enable_if_t<is_integral_v<U>>* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
	typename common_type<typename Z_p<T>::Type, int64_t>::type x;
	in >> x;
	number.value = Z_p<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;
*/

constexpr int mod = 1e9 + 7;
//constexpr int mod = 998244353;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
	auto &inv = Z_p<T>::mod_inv;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / int(inv.size()) * inv[mod % int(inv.size())] % mod) % mod);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s, s += '$';
	}
	vector<vector<int>> ord(n);
	for(auto p = 0; p < n; ++ p){
		ord[p].resize(int(a[p].size()));
		iota(ord[p].begin(), ord[p].end(), 0);
		vector<int> lcp(int(a[p].size()));
		for(auto i = int(a[p].size()) - 2; i >= 0; -- i){
			lcp[i] = a[p][i] == a[p][i + 1] ? lcp[i + 1] + 1 : 0;
		}
		auto cmp = [&](int i, int j){
			if(i < j){
				if(lcp[i] < j - i) return a[p][i + lcp[i] + 1] < a[p][i + lcp[i]];
				else return false;
			}
			else{
				if(lcp[j] < i - j) return a[p][j + lcp[j]] < a[p][j + lcp[j] + 1];
				else return false;
			}
		};
		sort(ord[p].begin(), ord[p].end(), cmp);
	}
	vector<Zp> dp(int(a[0].size()));
	iota(dp.begin(), dp.end(), 1);
	for(auto p = 1; p < n; ++ p){
		static vector<Zp> dp_next; dp_next.assign(int(a[p].size()), 0);
		int sz = int(a[p - 1].size()), csz = int(a[p].size()), len = max(sz, csz);
		a[p - 1].resize(len, '$'), a[p].resize(len, '$');
		vector<int> lcp0(len, 1), lcp1(len), lcp2(len); // 0: i vs i, 1: i+1 vs i, 2: i vs i+1
		for(auto i = len - 2; i >= 0; -- i){
			lcp0[i] = a[p - 1][i] == a[p][i] ? lcp0[i + 1] + 1 : 0;
			lcp1[i] = a[p - 1][i + 1] == a[p][i] ? lcp1[i + 1] + 1 : 0;
			lcp2[i] = a[p - 1][i] == a[p][i + 1] ? lcp2[i + 1]  + 1 : 0;
		}
		auto cmp = [&](int i, int j){
			if(i == j){
				if(lcp0[0] < i) return a[p - 1][lcp0[0]] <= a[p][lcp0[0]];
				else if(lcp0[i + 1] < len - i - 1) return a[p - 1][i + 1 + lcp0[i + 1]] <= a[p][i + 1 + lcp0[i + 1]];
				else return true;
			}
			else if(i < j){
				if(lcp0[0] < i) return a[p - 1][lcp0[0]] <= a[p][lcp0[0]];
				else if(lcp1[i] < j - i) return a[p - 1][i + 1 + lcp1[i]] <= a[p][i + lcp1[i]];
				else if(lcp0[j + 1] < len - j - 1) return a[p - 1][j + 1 + lcp0[j + 1]] <= a[p][j + 1 + lcp0[j + 1]];
				else return true;
			}
			else{
				if(lcp0[0] < j) return a[p - 1][lcp0[0]] <= a[p][lcp0[0]];
				else if(lcp2[j] < i - j) return a[p - 1][j + lcp2[j]] <= a[p][j + 1 + lcp2[j]];
				else if(lcp0[i + 1] < len - i - 1) return a[p - 1][i + 1 + lcp0[i + 1]] <= a[p][i + 1 + lcp0[i + 1]];
				else return true;
			}
		};
		for(auto i = -1, j = 0; j < csz; ++ j){
			while(i < sz - 1 && cmp(ord[p - 1][i + 1], ord[p][j])){
				++ i;
			}
			dp_next[j] = (~i ? dp[i] : 0) + (j ? dp_next[j - 1] : 0);
		}
		swap(dp, dp_next);
		a[p].resize(csz);
	}
	cout << dp.back() << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////