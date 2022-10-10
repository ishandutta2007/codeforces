#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
T binexp(T b, long long e){
	T res = 1;
	for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
	return res;
}
template<typename T>
T modinv(T a, T m){
	T u = 0, v = 1;
	while(a){
		T t = m / a;
		m -= t * a; swap(a, m);
		u -= t * v; swap(u, v);
	}
	assert(m == 1);
	return u;
}
template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
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
	Z_p &operator/=(const Z_p &otr){ return *this *= Z_p(modinv(otr.value, mod())); }
	template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
	template<typename U> friend bool operator==(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend bool operator<(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend istream &operator>>(istream &in, Z_p<U> &number);
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
	typename common_type<typename Z_p<T>::Type, int64_t>::type x;
	in >> x;
	number.value = Z_p<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }
constexpr int mod = 998244353;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), w(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	copy_n(istream_iterator<int>(cin), n, w.begin());
	int good = 0, bad = 0;
	for(int i = 0; i < n; ++ i){
		if(a[i]){
			good += w[i];
		}
		else{
			bad += w[i];
		}
	}
	int tot = good + bad;
	vector<vector<Zp>> dp(m + 1, vector<Zp>(m + 1));
	dp[0][0] = 1;
	for(int i = 0; i < m; ++ i){
		for(int j = i; j >= 0; -- j){
			if(tot + 2 * j - i > 0){
				Zp p = Zp(good + j) / (tot + 2 * j - i);
				dp[i + 1][j] += (1 - p) * dp[i][j];
				dp[i + 1][j + 1] += p * dp[i][j];
			}
		}
	}
	const auto &d = dp[m];
	Zp cgood = d[0], cbad = d[m];
	for(int j = 1; j <= m; ++ j){
		static Zp temp = 1;
		temp *= 1 + 1 / Zp(good + j - 1);
		cgood += temp * d[j];
	}
	for(int j = 1; j <= min(m, int(Zp(bad))); ++ j){
		static Zp temp = 1;
		temp *= 1 - 1 / Zp(bad - j + 1);
		cbad += temp * d[m - j];
	}
	for(int i = 0; i < n; ++ i){
		if(a[i]){
			cout << cgood * w[i] << "\n";
		}
		else{
			cout << cbad * w[i] << "\n";
		}
	}
	return 0;
}

/*
dp[i][j]: after i-th visit, probability of liking j times so far

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////