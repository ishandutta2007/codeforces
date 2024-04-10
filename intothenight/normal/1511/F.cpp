#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());

template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> MOD_INV;
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
	typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type &operator*=(const Z_p& rhs){
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
	typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type &operator*=(const Z_p &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type &operator*=(const Z_p &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	template<typename U>
	Z_p &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		Z_p res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	Z_p operator^(U e) const{
		return Z_p(*this) ^= e;
	}
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)MOD_INV.size()) return *this *= MOD_INV[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
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

// constexpr int mod = 1e9 + 7; // 1000000007
constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::MOD_INV;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(int SZ){
	auto &inv = Z_p<T>::MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()]) % mod);
}

template<typename T>
vector<T> precalc_power(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
}

// Store the linear recurrence relation of form Sum{t<=i<t+n}( coef[i] * A[i] ) = A[t+n]
// T must be of modular type
// Requires modular
template<class T>
struct linear_recurrence{
	int n;
	vector<T> init, coef;
	linear_recurrence(const vector<T> &init, const vector<T> &coef): n((int)coef.size()), init(init), coef(coef){
		assert((int)coef.size() == (int)init.size());
	}
	// Berlekamp Massey Algorithm / find the minimal linear recurrence relation
	// O(n * sz + sz log mod)
	linear_recurrence(const vector<T> &s){
		assert(!s.empty());
		int sz = (int)s.size();
		n = 0;
		vector<T> B(sz), C;
		coef.resize(sz);
		coef[0] = B[0] = 1;
		T b = 1;
		for(auto i = 0, m = 0; i < sz; ++ i){
			++ m;
			T d = s[i];
			for(auto j = 1; j <= n; ++ j) d += coef[j] * s[i - j];
			if(!d) continue;
			C = coef;
			T c = d / b;
			for(auto j = m; j < sz; ++ j) coef[j] -= c * B[j - m];
			if(2 * n > i) continue;
			n = i + 1 - n, B = C, b = d, m = 0;
		}
		n = max(n, 1);
		coef.resize(n + 1), coef.erase(coef.begin());
		for(auto &x: coef) x = -x;
		reverse(coef.begin(), coef.end());
		init.resize(n);
		for(auto i = 0; i < n; ++ i) init[i] = s[i];
	}
	// n^2 log i (or n log n log i if FFT is used)
	T operator[](long long i) const{
		assert(0 <= i);
		auto combine = [&](const vector<T> &a, const vector<T> &b){
			vector<T> res(2 * n + 1);
			for(auto i = 0; i <= n; ++ i) for(auto j = 0; j <= n; ++ j) res[i + j] += a[i] * b[j];
			for(auto i = n << 1; i > n; -- i) for(auto j = 0; j < n; ++ j) res[i - 1 - j] += res[i] * coef[n - 1 - j];
			res.resize(n + 1);
			return res;
		};
		vector<T> pol(n + 1), e(pol);
		pol[0] = e[1] = 1;
		for(++ i; i; i >>= 1, e = combine(e, e)) if(i & 1) pol = combine(pol, e);
		T res = 0;
		for(auto i = 0; i < n; ++ i) res += pol[i + 1] * init[i];
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<array<int, 2>> pos;
	vector<vector<int>> invpos(10, vector<int>(10, -1));
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		for(auto j = 0; j < (int)a[i].size(); ++ j){
			invpos[i][j] = (int)pos.size();
			pos.push_back({i, j});
		}
	}
	const int sz = (int)pos.size();
	const int mx = 26;
	vector<array<vector<int>, mx>> next_temp(sz);
	for(auto x = 0; x < sz; ++ x){
		auto [i, j] = pos[x];
		if(j + 1 == (int)a[i].size()){
			for(auto c = 0; c < mx; ++ c){
				for(auto k = 0; k < n; ++ k){
					if(a[k][0] - 'a' == c){
						next_temp[x][c].push_back(invpos[k][0]);
					}
				}
			}
		}
		else{
			next_temp[x][a[i][j + 1] - 'a'].push_back(invpos[i][j + 1]);
		}
	}
	vector<vector<pair<int, int>>> next(sz * sz);
	for(auto x = 0; x < sz; ++ x){
		for(auto y = 0; y < sz; ++ y){
			vector<int> cnt(sz * sz);
			for(auto c = 0; c < mx; ++ c){
				for(auto z: next_temp[x][c]){
					for(auto w: next_temp[y][c]){
						++ cnt[sz * z + w];
					}
				}
			}
			for(auto t = 0; t < sz * sz; ++ t){
				if(cnt[t]){
					next[sz * x + y].push_back({t, cnt[t]});
				}
			}
		}
	}
	vector dp({vector<Zp>(sz * sz)});
	dp[0][(sz + 1) * invpos[0][(int)a[0].size() - 1]] = 1;
	for(auto t = 0; t < 2 * sz * sz; ++ t){
		const vector<Zp> &dp_cur = dp[t];
		vector<Zp> dp_next(sz * sz);
		for(auto x = 0; x < sz * sz; ++ x){
			for(auto [y, val]: next[x]){
				dp_next[y] += dp_cur[x] * val;
			}
		}
		dp.push_back(dp_next);
	}
	Zp res = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			int u = sz * invpos[i][(int)a[i].size() - 1] + invpos[j][(int)a[j].size() - 1];
			vector<Zp> cur((int)dp.size());
			for(auto t = 0; t < (int)dp.size(); ++ t){
				cur[t] = dp[t][u];
			}
			linear_recurrence<Zp> f(cur);
			res += f[m];
		}
	}
	cout << res << "\n";
	return 0;
}

/*
40 ^ 4

2560000
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////