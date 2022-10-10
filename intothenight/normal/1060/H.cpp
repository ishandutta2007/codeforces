#include <bits/stdc++.h>
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

using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
	auto &inv = Z_p<T>::mod_inv;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / int(inv.size()) * inv[mod % int(inv.size())] % mod) % mod);
}

// Requires Z_p
template<class T = Zp>
struct combinatorics{
	int SZ;
	vector<T> inv, fact, invfact;
	vector<vector<T>> stir1, stir2;
	combinatorics(int SZ): SZ(SZ), inv(SZ + 1, 1), fact(SZ + 1, 1), invfact(SZ + 1, 1){
		for(int i = 1; i <= SZ; ++ i) fact[i] = fact[i - 1] * i;
		invfact[SZ] = 1 / fact[SZ];
		for(int i = SZ - 1; i >= 0; -- i){
			invfact[i] = invfact[i + 1] * (i + 1);
			inv[i + 1] = invfact[i + 1] * fact[i];
		}
	} // O(SZ)
	T C(int n, int k){ return n < k ? 0 : fact[n] * invfact[k] * invfact[n - k]; }
	T P(int n, int k){ return n < k ? 0 : fact[n] * invfact[n - k]; }
	T H(int n, int k){ return C(n + k - 1, k); }
	vector<T> precalc_power(int base, int n = -1){
		if(!~n) n = SZ;
		vector<T> res(n + 1, 1);
		for(int i = 1; i <= n; ++ i) res[i] = res[i - 1] * base;
		return res;
	}
	T naive_C(long long n, long long k){
		if(n < k) return 0;
		T res = 1;
		k = min(k, n - k);
		for(long long i = n; i > n - k; -- i) res *= i;
		return res * invfact[k];
	}
	T naive_P(long long n, int k){
		if(n < k) return 0;
		T res = 1;
		for(long long i = n; i > n - k; -- i) res *= i;
		return res;
	}
	T naive_H(long long n, long long k){ return naive_C(n + k - 1, k); }
	bool parity_C(long long n, long long k){ return n < k ? 0 : k & n - k ^ 1; }
	// Catalan's Trapzoids
	// # of bitstrings of n Xs and k Ys such that in each initial segment, (# of X) + m > (# of Y) 
	T Cat(int n, int k, int m = 1){
		if(m <= 0) return 0;
		else if(k >= 0 && k < m) return C(n + k, k);
		else if(k < n + m) return C(n + k, k) - C(n + k, k - m);
		else return 0;
	}
	// Stirling number
	// First kind (unsigned): # of n-permutations with k disjoint cycles
	//                        Also the coefficient of x^k for x_n = x(x+1)...(x+n-1)
	// Second kind: # of ways to partition a set of size n into r non-empty sets
	//              Satisfies sum{k=0~n}(x_k) = x^n
	array<bool, 2> pre{};
	template<bool FIRST = true>
	void precalc_stir(int n, int k){
		auto &s = FIRST ? stir1 : stir2;
		pre[!FIRST] = true;
		s.resize(n + 1, vector<T>(k + 1, 1));
		for(int i = 1; i <= n; ++ i) for(int j = 1; j <= k; ++ j){
			s[i][j] = (FIRST ? i - 1 : j) * s[i - 1][j] + s[i - 1][j - 1];
		}
	}
	// unsigned
	T Stir1(int n, int k){
		if(n < k) return 0;
		assert(pre[0]);
		return stir1[n][k];
	}
	T Stir2(long long n, int k){
		if(n < k) return 0;
		if(pre[1] && n < (int)stir2.size()) return stir2[n][k];
		T res = 0;
		for(int i = 0, sign = 1; i <= k; ++ i, sign *= -1) res += sign * C(k, i) * (Zp(k - i) ^ n);
		return res * invfact[k];
	}
	bool parity_Stir2(long long n, long long k){ return n < k ? 0 : k ? !(n - k & k - 1 >> 1) : 0; }
};

template<class T, T (*zero)(), T (*one)()> // T must support +=, *=
struct matrix_base: vector<vector<T>>{
	using C = vector<vector<T>>; // container type
	using C::assign;
	matrix_base &transpose(){
		matrix_base res(m, n);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) res[j][i] = (*this)[i][j];
		return *this = res;
	}
	matrix_base transposed() const{
		matrix_base res = *this;
		return res.transpose();
	}
	matrix_base &operator+=(const matrix_base &M){
		assert(n == M.n && m == M.m);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] += M[i][j];
		return *this;
	}
	matrix_base operator+(const matrix_base &M) const{
		matrix_base res(*this); res += M;
		return res;
	}
	matrix_base operator*(const matrix_base &M) const{
		assert(m == M.n);
		int l = M.m;
		matrix_base res(n, l);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) for(int k = 0; k < l; ++ k) res[i][k] += (*this)[i][j] * M[j][k];
		return res;
	}
	matrix_base &operator*=(const matrix_base &M){
		return *this = *this * M;
	}
	matrix_base &operator*=(T c){
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] *= c;
		return *this;
	}
	matrix_base operator*(T c) const{
		matrix_base res(*this); res *= c;
		return res;
	}
	matrix_base &operator^=(long long e){
		matrix_base res(n, n, one());
		if(e < 0) e = -e, inversify();
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	matrix_base operator^(long long e) const{
		assert(n == m);
		matrix_base res(*this); res ^= e;
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
	bool inversify(){
		assert(n == m);
		C temp(*this), res(n, vector<T>(n, zero()));
		for(int i = 0; i < n; ++ i) res[i][i] = one();
		for(int j = 0; j < n; ++ j){
			int pivot = -1;
			for(int i = j; i < n; ++ i) if(temp[i][j] != zero()){
				pivot = i;
				break;
			}
			if(!~pivot) return false;
			swap(temp[j], temp[pivot]), swap(res[j], res[pivot]);
			T inv = 1 / temp[j][j];
			for(int jj = 0; jj < n; ++ jj) temp[j][jj] *= inv, res[j][jj] *= inv;
			for(int i = 0; i < n; ++ i) if(i != j && temp[i][j] != zero()){
				T d = temp[i][j];
				for(int jj = 0; jj < n; ++ jj) temp[i][jj] -= d * temp[j][jj], res[i][jj] -= d * res[j][jj];
			}
		}
		swap(*this, res);
		return true;
	}
	vector<T> maps_to(const vector<T> &v) const{
		assert(m == (int)v.size());
		vector<T> res(n, zero());
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) res[i] += (*this)[i][j] * v[j];
		return res;
	}
	int n, m;
	matrix_base(int n, int m, T init_diagonal = zero(), T init_off_diagonal = zero()): n(n), m(m){
		assign(n, vector<T>(m, zero()));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] = i == j ? init_diagonal : init_off_diagonal;
	}
	matrix_base(const C &arr): n((int)arr.size()), m((int)arr[0].size()){
		assign(n, vector<T>(m, zero()));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] = arr[i][j];
	}
};
template<class T, T (*zero)(), T (*one)()>
matrix_base<T, zero, one> operator*(T c, matrix_base<T, zero, one> M){
	for(int i = 0; i < M.n; ++ i) for(int j = 0; j < M.m; ++ j) M[i][j] = c * M[i][j];
	return M;
}
Zp ZERO(){
	return 0;
}
Zp ONE(){
	return 1;
}
template<class T>
using matrix = matrix_base<T, ZERO, ONE>;

using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int d;
	cin >> d >> mod;
	combinatorics C(d);
	const int mx = 110;
	vector<Zp> val(mx, 1); val[0] = 3, val[1] = 8;
	vector<string> res;
	auto add = [&](int i, int j, int k){
		res.push_back("+ " + to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(k + 1));
		val[k] = val[i] + val[j];
	};
	auto power = [&](int i, int j){
		res.push_back("^ " + to_string(i + 1) + " " + to_string(j + 1));
		val[j] = val[i] ^ d;
	};
	auto report = [&](int i){
		res.push_back("f " + to_string(i + 1));
	};
	vector<int> posx{0}, posy{1}, posxy{3}, pos2{2};
	add(0, 1, 3);
	add(0, 2, 4);
	posx.push_back(4);
	for(auto i = 5; i <= 3 + d; ++ i){
		add(2, i - 1, i);
		posx.push_back(i);
	}
	add(1, 2, 4 + d);
	posy.push_back(4 + d);
	for(auto i = 5 + d; i <= 3 + 2 * d; ++ i){
		add(2, i - 1, i);
		posy.push_back(i);
	}
	add(2, 3, 4 + 2 * d);
	posxy.push_back(4 + 2 * d);
	for(auto i = 5 + 2 * d; i <= 3 + 3 * d; ++ i){
		add(2, i - 1, i);
		posxy.push_back(i);
	}
	for(auto i = 0; i <= 3 + 3 * d; ++ i){
		power(i, i);
	}
	add(2, 2, 4 + 3 * d);
	pos2.push_back(4 + 3 * d);
	for(auto i = 5 + 3 * d; i <= 34 + 3 * d; ++ i){
		add(i - 1, i - 1, i);
		pos2.push_back(i);
	}
	int zpos = 35 + 3 * d;
	vector<int> cur;
	for(auto bit = 0; bit <= 30; ++ bit){
		if(mod & 1 << bit){
			cur.push_back(bit);
		}
	}
	add(pos2[cur[0]], pos2[cur[1]], zpos);
	for(auto i = 2; i < (int)cur.size(); ++ i){
		add(zpos, pos2[cur[i]], zpos);
	}
	vector<int> pos;
	for(auto i = 0; i <= 30; ++ i){
		pos.push_back(i + 36 + 3 * d);
	}
	// x,y,1,x+y
	// 4     ~ 3+d   : x+i-3
	// 4+d   ~ 3+2d  : y+i-3-d
	// 4+2d  ~ 3+3d  : x+y+i-3-2d
	// 4+3d  ~ 34+3d : 2^(i-3-3d)
	// 35+3d         : zero
	// 36+3d ~ 66+3d : 2^(i-36-3d) VAL
	auto inc = [&](int i, int N, int p){ // increment value at p by N * val[i]
		add(i, zpos, pos[0]);
		for(auto bit = 1; bit <= 30; ++ bit){
			add(pos[bit - 1], pos[bit - 1], pos[bit]);
		}
		for(auto bit = 0; bit <= 30; ++ bit){
			if(N & 1 << bit){
				add(p, pos[bit], p);
			}
		}
	};
	matrix<Zp> M(d + 1, d + 1, Zp(1), Zp(1));
	for(auto i = 0; i <= d; ++ i){
		for(auto j = d - 1; j >= 0; -- j){
			M[i][j] = M[i][j + 1] * i;
		}
	}
	for(auto i = 0; i <= d; ++ i){
		for(auto j = 0; j <= d; ++ j){
			M[i][j] *= C.C(d, j);
		}
	}
	M.inversify();
	// x^2 on 67+3d, y^2 on 68+3d, (x+y)^2 on 69+3d
	int xx = 67 + 3 * d, yy = xx + 1, xyxy = yy + 1, mxx = xyxy + 1, myy = mxx + 1, final = myy + 1;
	add(zpos, zpos, xx), add(zpos, zpos, yy), add(zpos, zpos, xyxy), add(zpos, zpos, mxx), add(zpos, zpos, myy), add(zpos, zpos, final);
	for(auto i = 0; i <= d; ++ i){
		inc(posx[i], M[2][i].value, xx);
	}
	for(auto i = 0; i <= d; ++ i){
		inc(posy[i], M[2][i].value, yy);
	}
	for(auto i = 0; i <= d; ++ i){
		inc(posxy[i], M[2][i].value, xyxy);
	}
	inc(xx, mod - 1, mxx), inc(yy, mod - 1, myy);
	add(mxx, xyxy, xyxy), add(myy, xyxy, xyxy);
	// xyxy holds 2XY
	inc(xyxy, mod + 1 >> 1, final);
	report(final);
	for(auto s: res){
		cout << s << "\n";
	}
	assert(val[final] == 24);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////