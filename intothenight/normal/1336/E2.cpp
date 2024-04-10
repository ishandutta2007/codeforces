#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
	Z_p operator^(long long e) const{
		Z_p b = *this, res = 1;
		for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
		return res;
	}
	Z_p &operator^=(long long e){ return *this = *this ^ e; }
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
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

long long modexp(long long b, long long e, const long long &mod){
	long long res = 1;
	for(; e; b = b * b % mod, e >>= 1) if(e & 1) res = res * b % mod;
	return res;
}
template<int SZ>
struct combinatorics{
	const long long mod;
	vector<long long> inv, fact, invfact;
	vector<vector<long long>> stir1, stir2;
	combinatorics(long long mod): mod(mod), inv(SZ + 1, 1), fact(SZ + 1, 1), invfact(SZ + 1, 1){
		for(long long i = 2; i <= SZ; ++ i){
			inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
			fact[i] = fact[i - 1] * i % mod;
			invfact[i] = invfact[i - 1] * inv[i] % mod;
		}
	}
	long long C(int n, int k){ return n < k ? 0 : fact[n] * invfact[k] % mod * invfact[n - k] % mod; }
	long long P(int n, int k){ return n < k ? 0 : fact[n] * invfact[n - k] % mod; }
	long long H(int n, int k){ return C(n + k - 1, k); }
	long long naive_C(long long n, long long k){
		if(n < k) return 0;
		long long res = 1;
		k = min(k, n - k);
		for(int i = n; i > n - k; -- i) res = res * i % mod;
		return res * invfact[k] % mod;
	}
	long long naive_P(long long n, int k){
		if(n < k) return 0;
		long long res = 1;
		for(int i = n; i > n - k; -- i) res = res * i % mod;
		return res;
	}
	long long naive_H(long long n, long long k){ return naive_C(n + k - 1, k); }
	bool parity_C(long long n, long long k){ return n < k ? 0 : k & (n - k) ^ 1; }
	// Catalan's Trapzoids
	// # of bitstrings of n Xs and k Ys such that in each initial segment, (# of X) + m > (# of Y) 
	long long Cat(int n, int k, int m = 1){
		if(m <= 0) return 0;
		else if(k >= 0 && k < m) return C(n + k, k);
		else if(k < n + m) return (C(n + k, k) - C(n + k, k - m) + mod) % mod;
		else return 0;
	}
	// Stirling number
	// First kind (unsigned): # of n-permutations with k disjoint cycles
	//                        Also the coefficient of x^k for x_n = x(x+1)...(x+n-1)
	// Second kind: # of ways to partition a set of size n into r non-empty sets
	//              Satisfies sum{k=0~n}(x_k) = x^n
	array<bool, 2> pre{};
	template<bool FIRST = true>
	void precalc_stir(int N, int K){
		auto &s = FIRST ? stir1 : stir2;
		pre[!FIRST] = true;
		s.resize(N + 1, vector<long long>(K + 1));
		s[0][0] = 1;
		for(int i = 1; i <= N; ++ i) for(int j = 1; j <= K; ++ j){
			s[i][j] = ((FIRST ? i - 1 : j) * s[i - 1][j] + s[i - 1][j - 1]) % mod;
		}
	}
	// unsigned
	long long Stir1(int n, int k){
		if(n < k) return 0;
		assert(pre[0]);
		return stir1[n][k];
	}
	long long Stir2(long long n, int k){
		if(n < k) return 0;
		if(pre[1] && n < int(stir2.size())) return stir2[n][k];
		long long res = 0;
		for(int i = 0, sign = 1; i <= k; ++ i, sign *= -1){
			res = (res + sign * C(k, i) * modexp(k - i, n, mod) % mod + mod) % mod;
		}
		return res * invfact[k] % mod;
	}
	bool parity_Stir2(long long n, long long k){ return n < k ? 0 : k ? !((n - k) & (k - 1 >> 1)) : 0; }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<long long> basis;
	for(auto i = 0; i < n; ++ i){
		long long x;
		cin >> x;
		x = accumulate(basis.rbegin(), basis.rend(), x, [&](long long x, long long y){ return min(x, x ^ y); });
		if(x){
			basis.insert(lower_bound(basis.begin(), basis.end(), x), x);
		}
	}
	vector<Zp> res(m + 1);
	int k = int(basis.size());
	Zp factor = Zp(2) ^ n - k;
	if(k <= 26){
		long long cur = 0;
		for(auto mask = 0; mask < 1 << k; ++ mask){
			for(auto i = 0; mask && i < k; ++ i){
				cur ^= basis[i];
				if(mask & 1 << i){
					break;
				}
			}
			res[__builtin_popcountll(cur)] += factor;
		}
	}
	else{
		long long lead = 0;
		for(auto i = 0; i < k; ++ i){
			int bit = __lg(basis[i]);
			lead ^= 1LL << bit;
			for(auto j = i + 1; j < k; ++ j){
				if(basis[j] & 1LL << bit){
					basis[j] ^= basis[i];
				}
			}
		}
		vector<int> lead_bit, rem_bit;
		for(auto i = 0; i < m; ++ i){
			lead & 1LL << i ? lead_bit.push_back(i) : rem_bit.push_back(i);
		}
		for(auto i = 0; i < k; ++ i){
			long long to = 0;
			for(auto bit = 0; bit < __builtin_popcountll(lead); ++ bit){
				to |= 1LL * !!(basis[i] & 1LL << lead_bit[bit]) << bit;
			}
			for(auto bit = __builtin_popcountll(lead); bit < m; ++ bit){
				to |= 1LL * !!(basis[i] & 1LL << rem_bit[bit - __builtin_popcountll(lead)]) << bit;
			}
			basis[i] = to;
		}
		vector<long long> cbasis(m - k);
		for(auto i = 0; i < m - k; ++ i){
			cbasis[i] ^= 1LL << i + k;
		}
		for(auto i = 0; i < k; ++ i){
			for(auto bit = k; bit < m; ++ bit){
				if(basis[i] & 1LL << bit){
					cbasis[bit - k] ^= 1LL << i;
				}
			}
		}
		vector<Zp> q(m + 1);
		long long cur = 0;
		for(auto mask = 0; mask < 1LL << m - k; ++ mask){
			for(auto i = 0; mask && i < m - k; ++ i){
				cur ^= cbasis[i];
				if(mask & 1LL << i){
					break;
				}
			}
			++ q[__builtin_popcountll(cur)];
		}
		combinatorics<100> comb(mod);
		vector<vector<Zp>> w(m + 1, vector<Zp>(m + 1));
		for(auto i = 0; i <= m; ++ i){
			for(auto c = 0; c <= m; ++ c){
				for(auto d = 0, sign = 1; d <= c; ++ d, sign *= -1){
					w[i][c] += sign * comb.C(i, d) * comb.C(m - i, c - d);
				}
			}
		}
		Zp factor2 = factor / (Zp(2) ^ m - k);
		for(auto c = 0; c <= m; ++ c){
			for(auto i = 0; i <= m; ++ i){
				res[c] += q[i] * w[i][c];
			}
			res[c] *= factor2;
		}
	}
	for(auto x: res){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////