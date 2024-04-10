#include <bits/stdc++.h>
using namespace std;

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

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

constexpr int mod = 1e9 + 7;
//constexpr int mod = (119 << 23) + 1;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
	auto &inv = Z_p<T>::mod_inv;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / int(inv.size()) * inv[mod % int(inv.size())] % mod) % mod);
}

template<typename T, T (*zero)(), T (*one)()> // T must support +=, *=
struct matrix: vector<vector<T>>{
	using C = vector<vector<T>>; // container type
	using C::assign;
	matrix &transpose(){
		matrix res(m, n);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) res[j][i] = (*this)[i][j];
		return *this = res;
	}
	matrix transposed() const{
		matrix res = *this;
		return res.transpose();
	}
	matrix &operator+=(const matrix &M){
		assert(n == M.n && m == M.m);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] += M[i][j];
		return *this;
	}
	matrix operator+(const matrix &M) const{
		matrix res(*this); res += M;
		return res;
	}
	matrix operator*(const matrix &M) const{
		assert(m == M.n);
		int l = M.m;
		matrix res(n, l);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) for(int k = 0; k < l; ++ k) res[i][k] += (*this)[i][j] * M[j][k];
		return res;
	}
	matrix &operator*=(const matrix &M){
		return *this = *this * M;
	}
	matrix &operator*=(T c){
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] *= c;
		return *this;
	}
	matrix operator*(T c) const{
		matrix res(*this); res *= c;
		return res;
	}
	matrix &operator^=(long long e){
		matrix res(n, n, one());
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	matrix operator^(long long e) const{
		assert(n == m);
		matrix res(*this); res ^= e;
		return res;
	}
	T int_det() const{ // For integers or Zp / O(n^3)
		assert(n == m);
		C temp(*this);
		T res = 1;
		for(int i = 0; i < n; ++ i){
			for(int j = i + 1; j < n; ++ j){
				while(temp[j][i]){ // GCD step
					int t = (int)temp[i][i] / (int)temp[j][i];
					if(t) for(int k = i; k < n; ++ k) temp[i][k] -= temp[j][k] * t;
					swap(temp[i], temp[j]);
					res *= -1;
				}
			}
			res *= temp[i][i];
			if(!res) return 0;
		}
		return res;
	}
	T real_det() const{ // For reals / O(n^3)
		assert(n == m);
		C temp(*this);
		T res = 1;
		for(int i = 0; i < n; ++ i){
			int b = i;
			for(int j = i + 1; j < n; ++ j) if(abs(temp[j][i]) > abs(temp[b][i])) b = j;
			if(i != b) swap(temp[i], temp[b]), res *= -1;
			if(res == 0) return 0;
			for(int j = i + 1; j < n; ++ j){
				T v = temp[j][i] / temp[i][i];
				if(v) for(int k = i + 1; k < n; ++ k) temp[j][k] -= v * temp[i][k];
			}
		}
		return res;
	}
	vector<T> maps_to(const vector<T> &v) const{
		assert(m == (int)v.size());
		vector<T> res(n, zero());
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) res[i] += (*this)[i][j] * v[j];
		return res;
	}
	int n, m;
	matrix(int n, int m, T init_diagonal = zero(), T init_off_diagonal = zero()): n(n), m(m){
		assign(n, vector<T>(m, zero()));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] = i == j ? init_diagonal : init_off_diagonal;
	}
	matrix(const C &arr): n((int)arr.size()), m((int)arr[0].size()){
		assign(n, vector<T>(m, zero()));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] = arr[i][j];
	}
};
template<typename T, T (*zero)(), T (*one)()>
matrix<T, zero, one> operator*(T c, matrix<T, zero, one> M){
	for(int i = 0; i < M.n; ++ i) for(int j = 0; j < M.m; ++ j) M[i][j] = c * M[i][j];
	return M;
}
auto zero(){
	return Zp(0);
}
auto one(){
	return Zp(1);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> adjm(n, vector<int>(n));
	for(auto i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adjm[u][v] = adjm[v][u] = true;
	}
	using M = matrix<Zp, zero, one>;
	vector<Zp> values(n);
	for(auto x = 0; x < n; ++ x){
		M temp(n, n, 0, -1);
		for(auto u = 0; u < n; ++ u){
			for(auto v = 0; v < n; ++ v){
				if(adjm[u][v]){
					temp[u][v] = -x;
					temp[u][u] += x;
				}
				else if(u != v){
					temp[u][u] += 1;
				}
			}
		}
		M mat(n - 1, n - 1);
		for(auto i = 0; i < n - 1; ++ i){
			for(auto j = 0; j < n - 1; ++ j){
				mat[i][j] = temp[i + 1][j + 1];
			}
		}
		debug(x);
		debug2(mat);
		values[x] = mat.int_det();
		debug(values[x]);
		debug("\n");
	}
	auto multiply = [&](vector<Zp> p, vector<Zp> q){
		int n = (int)p.size(), m = (int)q.size();
		vector<Zp> res(n + m - 1);
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				res[i + j] += p[i] * q[j];
			}
		}
		return res;
	};
	vector<Zp> res(n);
	for(auto i = 0; i < n; ++ i){
		vector<Zp> p{1};
		Zp c = 1;
		for(auto j = 0; j < n; ++ j){
			if(i != j){
				p = multiply(p, {-j, 1});
				c *= i - j;
			}
		}
		c = values[i] / c;
		for(auto &x: p){
			x *= c;
		}
		for(auto i = 0; i < n; ++ i){
			res[i] += p[i];
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