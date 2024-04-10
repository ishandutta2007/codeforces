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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	string s;
	cin >> n >> s;
	vector<int> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + (s[i] == '?');
	}
	#ifdef LOCAL
	const int mx = 17;
	#else
	const int mx = 17;
	#endif
	array<vector<modular>, mx + 1> power;
	for(auto x = 0; x <= mx; ++ x){
		power[x] = modular::precalc_power(x, n);
	}
	vector<array<modular, mx + 1>> pref_cnt(n + 1), suff_cnt(n + 1);
	pref_cnt[0].fill(1), suff_cnt[n].fill(1);
	for(auto i = 0; i < n; ++ i){
		for(auto x = 0; x <= mx; ++ x){
			pref_cnt[i + 1][x] = pref_cnt[i][x] * (s[i] == '?' ? x : 1);
		}
	}
	for(auto i = n - 1; i >= 0; -- i){
		for(auto x = 0; x <= mx; ++ x){
			suff_cnt[i][x] = suff_cnt[i + 1][x] * (s[i] == '?' ? x : 1);
		}
	}
	vector<array<modular, mx + 1>> res(1 << mx);
	for(auto sum = 1; sum < 2 * n; ++ sum){
		int req = 0, cnt = 0;
		for(auto l = (sum - 1) / 2, r = sum - l; 0 <= l && r <= n; -- l, ++ r){
			if(s[l] == s[r - 1]){
				cnt += s[l] == '?';
			}
			else if(s[l] == '?' || s[r - 1] == '?'){
				req |= 1 << (s[l] ^ s[r - 1] ^ '?') - 'a';
			}
			else{
				break;
			}
			for(auto x = 0; x <= mx; ++ x){
				res[req][x] += power[x][cnt] * pref_cnt[l][x] * suff_cnt[r][x];
			}
		}
	}
	for(auto c = 0; c < mx; ++ c){
		for(auto mask = 0; mask < 1 << mx; ++ mask){
			if(~mask & 1 << c){
				for(auto x = 0; x <= mx; ++ x){
					res[mask | 1 << c][x] += res[mask][x];
				}
			}
		}
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		string s;
		cin >> s;
		int req = 0;
		for(auto c: s){
			req |= 1 << c - 'a';
		}
		cout << res[req][(int)s.size()] << "\n";
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