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
	template<typename U> friend bool operator==(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend bool operator<(const Z_p<U> &lhs, const Z_p<U> &rhs);
	template<typename U> friend istream &operator>>(istream &in, Z_p<U> &number);
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
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

template<typename T>
struct graph{
	struct edge{
		int from, to;
		T cost;
	};
	int n;
	vector<edge> edges;
	vector<vector<int>> adj;
	function<bool(int)> ignore; // edge ignoration rule
	graph(int n): n(n), adj(n), ignore(nullptr){
	}
	int link(int u, int v, T w){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w){ // insert a directed edge
		int id = (int)edges.size();
		adj[u].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	graph reversed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges){
			res.orient(e.to, e.from, e.cost);
		}
		return res;
	}
};

// Requires graph
template<typename T>
struct dfs_tree{
	int n;
	graph<T> *g;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	void init(graph<T> *h){
		g = h;
		n = g->n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, id);
		was.assign(n, -1);
		attempt = 0;
	}
	void clear(){
		pv.clear();
		pe.clear();
		order.clear();
		pos.clear();
		end.clear();
		sz.clear();
		root.clear();
		depth.clear();
		min_depth.clear();
		dist.clear();
		was.clear();
	}
	int attempt = 0;
	void dfs(int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order){
			order.clear();
		}
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g->adj[u]){
				if(id == pe[u] || g->ignore && g->ignore(id)){
					continue;
				}
				auto &e = g->edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = bin_op(dist[u], e.cost);
				pv[v] = u;
				pe[v] = id;
				root[v] = ~root[u] ? root[u] : v;
				recurse(v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(u);
	}
	void dfs_all(){
		order.clear();
		for(auto u = 0; u < n; ++ u){
			if(!~depth[u]){
				dfs(u, false);
			}
		}
		assert((int)order.size() == n);
	}
	inline T bin_op(T x, T y){
		return {0, 0, 0};
	}
	T id = {0, 0, 0};
};

// Requires graph and dfs_tree
template<typename T> // Returns a centroid of the tree starting from r, O(V)
int centroid(dfs_tree<T> &dt, int sz, int u = 0, int pe = -1){ // dfs_tree.dfs(r) must be called before this.
	for(auto id: dt.g->adj[u]){
		if(id == pe || dt.g->ignore && dt.g->ignore(id)){
			continue;
		}
		auto &e = dt.g->edges[id];
		int v = u ^ e.from ^ e.to;
		if(dt.sz[v] > sz / 2) return centroid(dt, sz, v, id);
	}
	return u;
}

vector<Zp> p10, invp10;
// Requires centroid
template<typename T> // O(V log V)
struct centroid_decomposition: graph<int>{ // stores the arborescence
	int n, root; // the root of the arborescence
	vector<int> cpe; // parent edge of each node in arborescence
	vector<vector<T>> dist; // dist[u][i]: sum of weights from u to its i-th centroid parent
	centroid_decomposition(graph<T> &g): n(g.n), graph<int>(g.n), dead(g.n), cpe(g.n, -1), dist(g.n){
		assert((int)g.edges.size() == n - 1);
		g.ignore = [&](int e){ return dead[g.edges[e].from] || dead[g.edges[e].to]; };
		dfs_tree<T> dt;
		dt.init(&g);
		construct(dt, 0, -1);
		for(auto u = 0; u < n; ++ u){
			reverse(dist[u].begin(), dist[u].end());
		}
	}
	using graph<int>::orient;
	vector<int> dead;
	void set_distance(graph<T> &g, int u, int pe){
		int p = u ^ g.edges[pe].from ^ g.edges[pe].to;
		dist[u].push_back(bin_op(dist[p].back(), g.edges[pe].cost));
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore(id)){
				continue;
			}
			set_distance(g, u ^ g.edges[id].from ^ g.edges[id].to, id);
		}
	}
	void construct(dfs_tree<T> &dt, int u, int p){
		dt.dfs(u);
		dead[u = centroid(dt, dt.sz[u], u)] = true;
		if(~p) cpe[u] = orient(p, u, 1);
		else root = u;
		dist[u].push_back(id);
		for(auto id: dt.g->adj[u]){
			auto &e = dt.g->edges[id];
			int v = u ^ e.from ^ e.to;
			if(!dead[v]) set_distance(*dt.g, v, id);
		}
		for(auto id: dt.g->adj[u]){
			auto &e = dt.g->edges[id];
			int v = u ^ e.from ^ e.to;
			if(!dead[v]) construct(dt, v, u);
		}
	}
	inline T bin_op(T x, T y){
		return {p10[y.len] * x.down + y.down, x.up + p10[x.len] * y.up, x.len + y.len};
	}
	T id = {0, 0, 0};
};

struct Q{
	Zp down = 0, up = 0;
	int len = 0;
};


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n >> mod;
	Zp inv = Zp(1) / 10;
	p10.push_back(1), invp10.push_back(1);
	for(auto i = 0; i < 200000; ++ i){
		p10.push_back(p10.back() * 10);
		invp10.push_back(invp10.back() * inv);
	}
	graph<Q> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v, w;
		cin >> u >> v >> w;
		g.link(u, v, {w, w, 1});
	}
	centroid_decomposition<Q> cd(g);
	long long res = 0;
	for(auto u = 0; u < n; ++ u){
		map<Zp, int> upcnt;
		for(auto id: cd.adj[u]){
			int v = u ^ cd.edges[id].from ^ cd.edges[id].to;
			function<void(int, int)> dfs_init = [&](int u, int depth){
				++ upcnt[cd.dist[u][depth].up];
				for(auto id: cd.adj[u]){
					int v = u ^ cd.edges[id].from ^ cd.edges[id].to;
					dfs_init(v, depth + 1);
				}
			};
			dfs_init(v, 1);
		}
		for(auto id: cd.adj[u]){
			int v = u ^ cd.edges[id].from ^ cd.edges[id].to;
			function<void(int, int)> dfs0 = [&](int u, int depth){
				-- upcnt[cd.dist[u][depth].up];
				for(auto id: cd.adj[u]){
					int v = u ^ cd.edges[id].from ^ cd.edges[id].to;
					dfs0(v, depth + 1);
				}
			};
			dfs0(v, 1);
			function<void(int, int)> dfs1 = [&](int u, int depth){
				res += upcnt[-cd.dist[u][depth].down * invp10[cd.dist[u][depth].len]];
				if(cd.dist[u][depth].up == Zp(0)) ++ res;
				if(cd.dist[u][depth].down == Zp(0)) ++ res;
				for(auto id: cd.adj[u]){
					int v = u ^ cd.edges[id].from ^ cd.edges[id].to;
					dfs1(v, depth + 1);
				}
			};
			dfs1(v, 1);
			function<void(int, int)> dfs2 = [&](int u, int depth){
				++ upcnt[cd.dist[u][depth].up];
				for(auto id: cd.adj[u]){
					int v = u ^ cd.edges[id].from ^ cd.edges[id].to;
					dfs2(v, depth + 1);
				}
			};
			dfs2(v, 1);
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