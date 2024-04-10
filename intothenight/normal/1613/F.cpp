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

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edge[id];
			int v = u ^ e.from ^ e.to;
			res[u].push_back(v);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

// Requires graph
template<class T>
struct dfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, size, root, depth, min_depth, was;
	T T_id;
	dfs_forest(int n, T T_id = 0): T_id(T_id){ init(n); }
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		size.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	template<class U, class F = plus<>>
	void dfs(const graph<U> &g, int u, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		auto recurse = [&](auto self, int u)->void{
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			size[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				self(self, v);
				size[u] += size[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(recurse, u);
	}
	template<class U, class F = plus<>>
	void dfs_all(const graph<U> &g, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<U, F>(g, u, false, UT);
	}
};

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	combinatorics<modular> C(n);
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
	}
	dfs_forest<int> df(n);
	df.dfs(g, 0);
	vector<vector<modular>> p;
	for(auto u = 0; u < n; ++ u){
		if(auto deg = g.degree(u) - !!~df.pv[u]){
			p.push_back({1, deg});
		}
	}
	auto q = multiply_all(p);
	modular res = 0;
	for(auto i = 0; i < (int)q.size(); ++ i){
		res += (~i & 1 ? 1 : -1) * q[i] * C.fact[n - i];
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