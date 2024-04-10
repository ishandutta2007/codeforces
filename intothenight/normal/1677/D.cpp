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

// T must be of modular type
// mod must be a prime
// Requires modular
template<class T>
struct number_theoric_transform_wrapper{
	// i \in [2^k, 2^{k+1}) holds w_{2^k+1}^{i-2^k}
	static vector<T> root;
	static void adjust_root(int n){
		for(auto k = (int)root.size(); k < n; k <<= 1){
			root.resize(n, 1);
			T w = T::primitive_root() ^ (T::mod() - 1) / (k << 1);
			for(auto i = k; i < k << 1; ++ i) root[i] = i & 1 ? root[i >> 1] * w : root[i >> 1];
		}
	}
	// n must be a power of two
	// O(n log n)
	static void transform(vector<T> &p, bool invert = false){
		int n = (int)p.size();
		assert(n && __builtin_popcount(n) == 1 && (T::mod() - 1) % n == 0);
		for(auto i = 1, j = 0; i < n; ++ i){
			int bit = n >> 1;
			for(; j & bit; bit >>= 1) j ^= bit;
			j ^= bit;
			if(i < j) swap(p[i], p[j]);
		}
		adjust_root(n);
		for(auto len = 1; len < n; len <<= 1) for(auto i = 0; i < n; i += len << 1) for(auto j = 0; j < len; ++ j){
			T x = p[i + j], y = p[len + i + j] * root[len + j];
			p[i + j] = x + y, p[len + i + j] = x - y;
		}
		if(invert){
			reverse(p.begin() + 1, p.end());
			T inv_n = T(1) / n;
			for(auto &x: p) x *= inv_n;
		}
	}
	static vector<T> buffer1, buffer2;
	// Double the length of the ntt array
	// n must be a power of two
	// O(n log n)
	static void double_up(vector<T> &p){
		int n = (int)p.size();
		assert(n && __builtin_popcount(n) == 1 && (T().mod() - 1) % (n << 1) == 0);
		buffer1.resize(n << 1);
		for(auto i = 0; i < n; ++ i) buffer1[i << 1] = p[i];
		transform(p, true);
		adjust_root(n << 1);
		for(auto i = 0; i < n; ++ i) p[i] *= root[n | i];
		transform(p);
		for(auto i = 0; i < n; ++ i) buffer1[i << 1 | 1] = p[i];
		p = buffer1;
	}
	// O(n * m)
	static vector<T> convolute_naive(const vector<T> &p, const vector<T> &q){
		vector<T> res(max((int)p.size() + (int)q.size() - 1, 0));
		for(auto i = 0; i < (int)p.size(); ++ i) for(auto j = 0; j < (int)q.size(); ++ j) res[i + j] += p[i] * q[j];
		return res;
	}
	// O((n + m) * log(n + m))
	static vector<T> convolute(const vector<T> &p, const vector<T> &q){
		if(min(p.size(), q.size()) < 55) return convolute_naive(p, q);
		int m = (int)p.size() + (int)q.size() - 1, n = 1 << __lg(m) + 1;
		buffer1.assign(n, 0);
		copy(p.begin(), p.end(), buffer1.begin());
		transform(buffer1);
		buffer2.assign(n, 0);
		copy(q.begin(), q.end(), buffer2.begin());
		transform(buffer2);
		for(auto i = 0; i < n; ++ i) buffer1[i] *= buffer2[i];
		transform(buffer1, true);
		return vector<T>(buffer1.begin(), buffer1.begin() + m);
	}
	// O(n log n)
	static vector<T> square(const vector<T> &p){
		if(p.size() < 40) return convolute_naive(p, p);
		int m = (int)p.size() * 2 - 1, n = 1 << __lg(m) + 1;
		buffer1.assign(n, 0);
		copy(p.begin(), p.end(), buffer1.begin());
		transform(buffer1);
		for(auto i = 0; i < n; ++ i) buffer1[i] *= buffer1[i];
		transform(buffer1, true);
		return vector<T>(buffer1.begin(), buffer1.begin() + m);
	}
};
template<class T>
vector<T> number_theoric_transform_wrapper<T>::root = {1, 1};
template<class T>
vector<T> number_theoric_transform_wrapper<T>::buffer1;
template<class T>
vector<T> number_theoric_transform_wrapper<T>::buffer2;

using ntt = number_theoric_transform_wrapper<modular>;

// T must support *=, *, +=, -=, and -
// T{} should return the additive identity
// Requires modular and number_theoric_transform
template<class T, class ntt>
struct polynomial_base{
	vector<T> data;
	polynomial_base(){}
	polynomial_base(int n): data(n){}
	polynomial_base(int n, T x): data(n, x){}
	polynomial_base(const vector<T> &p): data(p){}
	polynomial_base(const initializer_list<T> &l): data(l){}
	template<class It>
	polynomial_base(It begin, It end): data(begin, end){}
	size_t size() const{
		return (int)data.size();
	}
	void resize(int n, T x = {}){
		data.resize(n, x);
	}
	int degree() const{
		return data.empty() ? numeric_limits<int>::max() : size() - 1;
	}
	T &operator[](int i){
		return data[i];
	}
	const T &operator[](int i) const{
		return data[i];
	}
	operator vector<T>() const{
		return data;
	}
	operator bool() const{
		return !data.empty();
	}
	typename vector<T>::iterator begin(){
		return data.begin();
	}
	typename vector<T>::iterator end(){
		return data.end();
	}
	T evaluate(T x) const{
		T res = {};
		for(auto i = (int)data.size() - 1; i >= 0; -- i) res = res * x + data[i];
		return res;
	}
	polynomial_base operator*(const polynomial_base &p) const{
		return ntt::convolute(data, p.data);
	}
	polynomial_base &operator*=(const vector<T> &p){
		return *this = *this * p;
	}
	template<class U>
	polynomial_base &operator*=(U x){
		for(auto &c: data) c *= x;
		return *this;
	}
	template<class U>
	polynomial_base operator*(U x) const{
		return polynomial_base(*this) *= x;
	}
	template<class U>
	friend polynomial_base operator*(U x, polynomial_base p){
		for(auto &c: p) c = x * c;
		return p;
	}
	polynomial_base &operator+=(const polynomial_base &p){
		data.resize(max(size(), p.size()));
		for(auto i = 0; i < (int)p.size(); ++ i) data[i] += p[i];
		return *this;
	}
	polynomial_base operator+(const polynomial_base &p) const{
		return polynomial_base(*this) += p;
	}
	polynomial_base &operator+=(const T &x){
		if(data.empty()) data.emplace_back();
		data[0] += x;
		return *this;
	}
	polynomial_base operator+(const T &x) const{
		return polynomial_base(*this) += x;
	}
	friend polynomial_base operator+(const T &x, const polynomial_base &p){
		return p + x;
	}
	polynomial_base &operator-=(const polynomial_base &p){
		data.resize(max(size(), p.size()));
		for(auto i = 0; i < (int)p.size(); ++ i) data[i] -= p[i];
		return *this;
	}
	polynomial_base operator-(const polynomial_base &p) const{
		return polynomial_base(*this) -= p;
	}
	polynomial_base &operator-=(const T &x){
		if(data.empty()) data.emplace_back();
		data[0] -= x;
		return *this;
	}
	polynomial_base operator-(const T &x) const{
		return polynomial_base(*this) -= x;
	}
	friend polynomial_base operator-(const T &x, const polynomial_base &p){
		return p - x;
	}
	polynomial_base operator-() const{
		polynomial_base res = *this;
		for(auto i = 0; i < size(); ++ i) res[i] = T{} - res[i];
		return res;
	}
	// Returns the first length terms of the inverse series
	// O(n * log(n))
	polynomial_base inverse(size_t length) const{
		assert(!data.empty() && data[0]);
		static vector<T> a, b;
		b = {1 / data[0]};
		while(b.size() < length){
			a.assign(b.size() << 2, {});
			copy(data.begin(), data.begin() + min(b.size() << 1, data.size()), a.begin());
			ntt::transform(a);
			b.resize(b.size() << 2);
			ntt::transform(b);
			for(auto i = 0; i < (int)b.size(); ++ i) b[i] = 2 * b[i] - a[i] * b[i] * b[i];
			ntt::transform(b, true);
			b.resize((int)b.size() >> 1);
		}
		return vector<T>(b.begin(), b.begin() + length);
	}
	// Returns the first length terms of the inverse series
	// O(n * log(n))
	polynomial_base &inplace_inverse(size_t length){
		return *this = this->inverse(length);
	}
	// Euclidean division
	// O(n * log(n))
	polynomial_base &operator/=(const polynomial_base &p){
		if(data.size() < p.size()){
			data.clear();
			return *this;
		}
		static vector<T> &b;
		int n = data.size() - p.size() + 1;
		b.assign(n, {});
		copy(p.rbegin(), p.rbegin() + min(p.size(), b.size()), b.begin());
		reverse(data.begin(), data.end());
		data = ntt::convolute(data, b.inverse(n));
		data.erase(data.begin() + n, data.end());
		reverse(data.begin(), data.end());
		return *this;
	}
	polynomial_base operator/(const polynomial_base &p) const{
		return polynomial_base(*this) /= p;
	}
	polynomial_base &operator/=(T x){
		assert(x);
		T inv_x = 1 / x;
		for(auto &c: data) c *= inv_x;
		return *this;
	}
	polynomial_base operator/(T x) const{
		return polynomial_base(*this) /= x;
	}
	pair<polynomial_base, polynomial_base> divrem(const polynomial_base &p) const{
		auto q = *this / p, r = *this - q * p;
		while(!r.empty() && r.back() == 0) r.pop_back();
		return {q, r};
	}
	polynomial_base operator%(const polynomial_base &p) const{
		return this->divrem(p).second;
	}
	polynomial_base &operator%=(const polynomial_base &p) const{
		return *this = *this % p;
	}
	polynomial_base &inplace_derivative(){
		if(!data.empty()){
			for(auto i = 0; i < (int)data.size(); ++ i) data[i] *= i;
			data.erase(data.begin());
		}
		return *this;
	}
	polynomial_base derivative() const{
		return polynomial_base(*this).inplace_derivative();
	}
	polynomial_base &inplace_antiderivative(){
		data.insert(data.begin(), 0);
		T::precalc_inverse(data.size());
		for(auto i = 1; i < (int)data.size(); ++ i) data[i] /= i;
		return *this;
	}
	polynomial_base antiderivative() const{
		return polynomial_base(*this).inplace_antiderivative();
	}
	polynomial_base &inplace_log(size_t length){
		assert(!data.empty() && data[0] == 1);
		if(!length){
			data.clear();
			return *this;
		}
		(*this = derivative() * inverse(length)).resize(length - 1);
		inplace_antiderivative();
		return *this;
	}
	polynomial_base log(size_t length) const{
		return polynomial_base(*this).inplace_log(length);
	}
	polynomial_base exp(size_t length) const{
		assert(!data.empty() && data[0] == 0);
		static polynomial_base a, b;
		b = {1};
		while(b.size() < length){
			size_t s = b.size() << 1;
			a.data.assign(s, {});
			copy(data.begin(), data.begin() + min(s, data.size()), a.begin());
			++ a[0];
			(b = ntt::convolute(b, a - b.log(s))).resize(s);
		}
		b.resize(length);
		return b;
	}
	polynomial_base &inplace_exp(size_t length){
		return *this = this->exp(length);
	}
	template<class U>
	polynomial_base &inplace_power(U e, size_t length){
		data.resize(length);
		if(e == 0 || length == 0){
			if(length) data[0] = 1;
			return *this;
		}
		if(e < 0) return inplace_inverse(length).inplace_power(-e, length);
		if(all_of(data.begin(), data.end(), [&](auto x){ return x == 0; })) return *this;
		size_t pivot = find_if(data.begin(), data.end(), [&](auto x){ return x; }) - data.begin();
		if(pivot && e >= (length + pivot - 1) / pivot){
			fill(data.begin(), data.end(), 0);
			return *this;
		}
		data.erase(data.begin(), data.begin() + pivot);
		length -= pivot * e;
		T pivot_c = data[0] ^ e;
		((*this /= data[0]).inplace_log(length) *= e).inplace_exp(length);
		data.insert(data.begin(), pivot * e, 0);
		return *this *= pivot_c;
	}
	template<class U>
	polynomial_base power(U e, size_t length) const{
		return polynomial_base(*this).inplace_power(e, length);
	}
	static polynomial_base multiply_all(const vector<polynomial_base> &a){
		if(a.empty()) return {1};
		auto solve = [&](auto self, int l, int r)->polynomial_base{
			if(r - l == 1) return a[l];
			int m = l + (r - l >> 1);
			return self(self, l, m) * self(self, m, r);
		};
		return solve(solve, 0, (int)a.size());
	}
};

using polynomial = polynomial_base<modular, ntt>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	combinatorics<modular> C(1e6);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = n - k; i < n; ++ i){
			if(~a[i] && a[i]){
				cout << "0\n";
				return 0;
			}
			a[i] = 0;
		}
		vector<polynomial> temp;
		for(auto i = 0; i < n - k; ++ i){
			if(!~a[i]){
				temp.push_back({i, 1});
			}
			else if(!a[i]){
				temp.push_back({0, 1});
			}
		}
		auto p = polynomial::multiply_all(temp);
		modular res = 0;
		for(auto x = 0; x < (int)p.size(); ++ x){
			res += (modular(k + 1) ^ x) * C.fact[k] * p[x];
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