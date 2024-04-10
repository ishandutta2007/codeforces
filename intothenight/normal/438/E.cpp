#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct modular_base{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> _MOD_INV;
	constexpr modular_base(): value(){ }
	template<typename U> modular_base(const U &x){ value = normalize(x); }
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
		if(a < (int)_MOD_INV.size()) return *this *= _MOD_INV[a];
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
template<typename T> vector<typename modular_base<T>::Type> modular_base<T>::_MOD_INV;
template<typename T>
void precalc_inverse(int SZ){
	auto &inv = T::_MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((T::mod() - 1LL * T::mod() / (int)inv.size() * inv[T::mod() % (int)inv.size()]) % T::mod());
}
template<typename T>
vector<T> precalc_power(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
}

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

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "{" << p.first << ", " << p.second << "}";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "{", t) << "}";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
void debug_frac_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_frac_out(Head H, Tail... T){
	for(auto d = 1; ; ++ d){
		if((H * d).value <= 1000000){
			cerr << H * d << "/" << d << ", ";
			break;
		}
		else if((-H * d).value <= 1000000){
			cerr << "-" << -H * d << "/" << d << ", ";
			break;
		}
	}
	debug_frac_out(T...);
}
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug_frac(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_frac_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug(...) 42
#define debug2(...) 42
#define debug_frac(...) 42
#endif
// DEBUG END

// NTTmod: 998244353(2^23*7*17,3),754974721(2^24*3^2*5,11),469762049(2^26*7,3),167772161(2^25*5,3), 924844033(2^21*3^2*7^2, 5)
// Requires modular
template<class T, int primitive_root = 3>
void number_theoric_transform(vector<T> &a, const bool invert = false){
	int n = (int)a.size();
	assert(n && __builtin_popcount(n) == 1 && (T().mod() - 1) % n == 0);
	const T root = T(primitive_root) ^ (T().mod() - 1) / n;
	const T inv_root = T(1) / root;
	for(auto i = 1, j = 0; i < n; ++ i){
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(auto len = 1; len < n; len <<= 1){
		T wlen = (invert ? inv_root : root) ^ n / len / 2;
		for(auto i = 0; i < n; i += len << 1){
			T w = 1;
			for(auto j = 0; j < len; ++ j, w *= wlen){
				T u = a[i + j], v = a[i + j + len] * w;
				a[i + j] = u + v, a[i + j + len] = u - v;
			}
		}
	}
	if(invert){
		T inv_n = T(1) / n;
		for(auto &x: a) x *= inv_n;
	}
}

// O(n log n)
// Requires number_theoric_transform
template<class T, int primitive_root = 3>
vector<T> convolute_ntt(vector<T> p, vector<T> q){
	if(min(p.size(), q.size()) < 60){
		vector<T> res((int)p.size() + (int)q.size() - 1);
		for(auto i = 0; i < (int)p.size(); ++ i) for(auto j = 0; j < (int)q.size(); ++ j) res[i + j] += p[i] * q[j];
		return res;
	}
	int m = (int)p.size() + (int)q.size() - 1, n = 1 << __lg(m) + 1;
	p.resize(n), q.resize(n);
	number_theoric_transform<T, primitive_root>(p), number_theoric_transform<T, primitive_root>(q);
	for(auto i = 0; i < n; ++ i) p[i] *= q[i];
	number_theoric_transform<T, primitive_root>(p, true);
	p.resize(m);
	return p;
}

// O(n log n)
// Requires number_theoric_transform and convolute_ntt
template<class T>
vector<T> operator*(const vector<T> &p, const vector<T> &q){
	return convolute_ntt(p, q);
}

/*
// O(n log n)
// Requires fast_fourier_transform and convolute_integral
template<class T>
vector<T> operator*(const vector<T> &p, const vector<T> &q){
	return convolute_integral(p, q);
}
*/
/*
// O(n log n)
// Requires fast_fourier_transform and convolute_modular
template<class T>
vector<T> operator*(const vector<T> &p, const vector<T> &q){
	return convolute_modular(p, q);
}
*/
/*
// Naive multiplication
// O(n m)
template<class T>
vector<T> operator*(const vector<T> &a, const vector<T> &b){
	if(a.empty() || b.empty()) return {};
	vector<T> c(a.size() + b.size() - 1, 0);
	for(auto i = 0; i < (int)a.size(); ++ i) for(auto j = 0; j < (int)b.size(); ++ j) c[i + j] += a[i] * b[j];
	return c;
}
*/
template<class T>
vector<T> &operator*=(vector<T> &a, const vector<T> &b){
	return a = a * b;
}
template<class T, class U>
vector<T> &operator*=(vector<T> &a, U x){
	for(auto &c: a) c *= x;
	return a;
}
template<class T, class U>
vector<T> operator*(const vector<T> &a, U x){
	vector<T> b = a;
	return b *= x;
}
template<class T, class U>
vector<T> operator*(U x, const vector<T> &a){
	vector<T> b = a;
	return b *= x;
}
template<class T>
vector<T> &operator+=(vector<T> &a, const vector<T> &b){
	if(a.size() < b.size()) a.resize(b.size());
	for(auto i = 0; i < (int)b.size(); ++ i) a[i] += b[i];
	return a;
}
template<class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b){
	vector<T> c = a;
	return c += b;
}
template<class T>
vector<T> &operator-=(vector<T> &a, const vector<T> &b){
	if(a.size() < b.size()) a.resize(b.size());
	for(auto i = 0; i < (int)b.size(); ++ i) a[i] -= b[i];
	return a;
}
template<class T>
vector<T> operator-(const vector<T> &a, const vector<T> &b){
	vector<T> c = a;
	return c -= b;
}
template<class T>
vector<T> operator-(const vector<T> &a){
	vector<T> c = a;
	for(auto i = 0; i < (int)c.size(); ++ i) c[i] = -c[i];
	return c;
}
// Returns the first length terms of the inverse of a
template<class T>
vector<T> inverse(const vector<T> &a, int length){
	assert(!a.empty() && a[0]);
	static vector<T> b;
	b = {1 / a[0]};
	while((int)b.size() < length){
		static vector<T> x;
		x.assign(min(a.size(), b.size() << 1), 0);
		copy(a.begin(), a.begin() + x.size(), x.begin());
		x *= b * b;
		b.resize(b.size() << 1);
		for(auto i = (int)b.size() >> 1; i < (int)min(x.size(), b.size()); ++ i) b[i] = -x[i];
	}
	b.resize(length);
	return b;
}
template<class T>
vector<T> &inplace_inverse(vector<T> &a, int length){
	return a = inverse(a, length);
}
template<class T>
vector<T> &operator/=(vector<T> &a, const vector<T> &b){
	int n = (int)a.size(), m = (int)b.size();
	if(n < m) a.clear();
	else{
		static vector<T> d;
		d.assign(n - m + 1, 0);
		copy(b.rbegin(), b.rbegin() + min(b.size(), d.size()), d.begin());
		reverse(a.begin(), a.end());
		a *= inverse(d, n - m + 1);
		a.erase(a.begin() + n - m + 1, a.end());
		reverse(a.begin(), a.end());
	}
	return a;
}
template<class T>
vector<T> operator/(const vector<T> &a, const vector<T> &b){
	vector<T> c = a;
	return c /= b;
}
template<class T>
vector<T> &operator/=(vector<T> &a, T x){
	T inv_x = 1 / x;
	for(auto &c: a) c *= inv_x;
	return a;
}
template<class T>
vector<T> operator/(const vector<T> &a, T x){
	vector<T> b = a;
	return b /= x;
}
template<class T>
pair<vector<T>, vector<T>> divrem(const vector<T> &a, const vector<T> &b){
	auto q = a / b, r = a - q * b;
	while(!r.empty() && r.back() == 0) r.pop_back();
	return {q, r};
}
template<class T>
vector<T> operator%(const vector<T> &a, const vector<T> &b){
	return divrem(a, b).second;
}
template<class T>
vector<T> &operator%=(vector<T> &a, const vector<T> &b){
	return a = a % b;
}
template<class T>
vector<T> &inplace_derivative(vector<T> &a){
	for(auto i = 0; i < (int)a.size(); ++ i) a[i] *= i;
	if(!a.empty()) a.erase(a.begin());
	return a;
}
template<class T>
vector<T> derivative(const vector<T> &a){
	auto c = a;
	return inplace_derivative(c);
}
template<class T>
vector<T> &inplace_antiderivative(vector<T> &a){
	a.insert(a.begin(), 0);
	precalc_inverse<T>((int)a.size());
	for(auto i = 1; i < (int)a.size(); ++ i) a[i] /= i;
	return a;
}
template<class T>
vector<T> antiderivative(const vector<T> &a){
	auto c = a;
	return inplace_antiderivative(c);
}
template<class T>
vector<T> &inplace_logarithm(vector<T> &a, int length){
	assert(!a.empty() && a[0] == 1);
	inplace_antiderivative(a = derivative(a) * inverse(a, length)).resize(length);
	return a;
}
template<class T>
vector<T> logarithm(const vector<T> &a, int length){
	assert(!a.empty() && a[0] == 1);
	auto b = a;
	return inplace_logarithm(b, length);
}
template<class T>
vector<T> exponential(const vector<T> &a, int length){
	assert(!a.empty() && a[0] == 0);
	static vector<T> b;
	b = {1};
	while((int)b.size() < length){
		static vector<T> x;
		b.resize(b.size() << 1);
		x.assign(min(a.size(), b.size()), 0);
		copy(a.begin(), a.begin() + min(a.size(), b.size()), x.begin());
		++ x[0];
		(x -= logarithm(b, (int)b.size())) *= vector<T>(b.begin(), b.begin() + (int)b.size() / 2);
		for(auto i = b.size() / 2; i < min(x.size(), b.size()); ++ i) b[i] = x[i];
	}
	b.resize(length);
	return b;
}
template<class T>
vector<T> &inplace_exponential(vector<T> &a, int length){
	return a = exponential(a, length);
}
template<class T, class U>
vector<T> &inplace_power(vector<T> &a, U e, int length){
	a.resize(length);
	if(e == 0 || length == 0){
		if(length) a[0] = 1;
		return a;
	}
	if(e < 0) return inplace_power(inplace_inverse(a, length), -e, length);
	if(all_of(a.begin(), a.end(), [&](auto x){ return x == 0; })) return a;
	int pivot = find_if(a.begin(), a.end(), [&](auto x){ return x; }) - a.begin();
	if(pivot && e >= length / pivot){
		fill(a.begin(), a.end(), 0);
		return a;
	}
	a.erase(a.begin(), a.begin() + pivot);
	length -= pivot * e;
	T temp = a[0], pivot_c = 1;
	for(auto f = e; f; f >>= 1, temp *= temp) if(f & 1) pivot_c *= temp;
	inplace_exponential(inplace_logarithm(a /= a[0], length) *= e, length);
	a.insert(a.begin(), pivot * e, 0);
	return a *= pivot_c;
}
template<class T, class U>
vector<T> power(const vector<T> &a, U e, int length){
	auto b = a;
	return inplace_power(b, e, length);
}
template<class T>
vector<T> multiply_all(const vector<vector<T>> &a){
	if(a.empty()) return {0};
	auto solve = [&](auto self, int l, int r)->vector<T>{
		if(r - l == 1) return a[l];
		int m = l + (r - l >> 1);
		return self(self, l, m) * self(self, m, r);
	};
	return solve(solve, 0, (int)a.size());
}
template<class T, class U>
T evaluate(const vector<T> &a, U x){
	T res = {};
	for(auto i = (int)a.size() - 1; i >= 0; -- i) res = res * x + a[i];
	return res;
}

// O((Complexity of product of n term polynomial) * log n)
// Requires polynomial
template<class T>
vector<T> polynomial_sqrt(vector<T> a, int length){
	vector<T> b{1};
	while((int)b.size() < length){
		static vector<T> x;
		b.resize(b.size() << 1);
		x.resize(min(a.size(), b.size()));
		copy(a.begin(), a.begin() + x.size(), x.begin());
		x *= inverse(b, (int)b.size());
		T inv2 = 1 / T(2);
		for(auto i = b.size() / 2; i < min(b.size(), x.size()); ++ i) b[i] = x[i] * inv2;
	}
	b.resize(length);
	return b;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<modular> p(m + 1);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if(x <= m){
			p[x] = 1;
		}
	}
	p = 2 * p * inverse(vector<modular>{1} - 2 * p + polynomial_sqrt(vector<modular>{1} - 4 * p, m + 1), m + 1);
	for(auto i = 1; i <= m; ++ i){
		cout << p[i] << "\n";
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