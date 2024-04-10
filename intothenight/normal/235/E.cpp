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

constexpr int mod = 1 << 30;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
	auto &inv = Z_p<T>::mod_inv;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / int(inv.size()) * inv[mod % int(inv.size())] % mod) % mod);
}

template<int SZ>
struct number_theory{
	vector<int> lpf, prime, mu, phi; // least prime factor, primes, mobius function, totient function, number of multiples
	number_theory(): lpf(SZ + 1), mu(SZ + 1, 1), phi(SZ + 1, 1){ // O(SZ)
		for(int i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			if(i / lpf[i] % lpf[i]) mu[i] = -mu[i / lpf[i]], phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else mu[i] = 0, phi[i] = phi[i / lpf[i]] * lpf[i];
			for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	const int mx = 2e3;
	number_theory<mx> nt;
	int a, b, c;
	cin >> a >> b >> c;
	vector<Zp> f(a + 1), g(b + 1), h(c + 1);
	for(auto i = 1; i <= mx; ++ i){
		for(auto x = 1; x <= a / i; ++ x){
			f[i] += a / i / x;
		}
		for(auto y = 1; y <= b / i; ++ y){
			g[i] += b / i / y;
		}
		for(auto z = 1; z <= c / i; ++ z){
			h[i] += c / i / z;
		}
	}
	vector<vector<int>> plcm(mx + 1, vector<int>(mx + 1));
	for(auto i = 1; i <= mx; ++ i){
		if(nt.mu[i]){
			for(auto j = 1; j <= mx; ++ j){
				if(nt.mu[j]){
					plcm[i][j] = lcm(i, j);
				}
			}
		}
	}
	Zp res = 0;
	for(auto d1 = 1; d1 <= min(a, b); ++ d1){
		if(nt.mu[d1]){
			for(auto d2 = 1; d2 <= min(b, c); ++ d2){
				if(nt.mu[d2] && plcm[d1][d2] <= b){
					for(auto d3 = 1; d3 <= min(c, a); ++ d3){
						if(nt.mu[d3] && plcm[d2][d3] <= c && plcm[d3][d1] <= a){
							res += nt.mu[d1] * nt.mu[d2] * nt.mu[d3] * f[plcm[d3][d1]] * g[plcm[d1][d2]] * h[plcm[d2][d3]];
						}
					}
				}
			}
		}
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