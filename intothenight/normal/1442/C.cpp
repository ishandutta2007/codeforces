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

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;
*/

constexpr int mod = (119 << 23) + 1;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
	auto &inv = Z_p<T>::mod_inv;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / int(inv.size()) * inv[mod % int(inv.size())] % mod) % mod);
}

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class T>
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
	int link(int u, int v, T w = 1){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = 1){ // insert a directed edge
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

template<class T>
struct shortest_path_tree{
	shortest_path_tree(graph<T> *g, T inf = numeric_limits<T>::max() / 3, T minf = numeric_limits<T>::min() / 3): n(g->n), g(g), inf(inf), minf(minf){ }
	void init(){
		dist.assign(n, inf), pv.assign(n, -1), pe.assign(n, -1);
	}
	void init_bfs(vector<int> src = {0}){
		init();
		deque<int> dq;
		for(auto s: src){
			dist[s] = {};
			dq.push_back(s);
		}
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			for(auto id: g->adj[u]){
				if(g->ignore || g->ignore(id)) continue;
				auto &e = g->edges[id];
				int v = u ^ e.from ^ e.to;
				if(dist[v] == inf){
					dist[v] = dist[u] + 1;
					pv[v] = u, pe[v] = id;
					dq.push_back(v);
				}
			}
		}
	}
	void init_dijkstra(vector<int> src = {0}){
		init();
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		for(auto s: src) pq.push({dist[s] = {}, s});
		while(!pq.empty()){
			auto [d, u] = pq.top(); pq.pop();
			if(d != dist[u]) continue;
			for(auto id: g->adj[u]){
				if(g->ignore && g->ignore(id)) continue;
				auto &e = g->edges[id];
				int v = u ^ e.from ^ e.to;
				if(dist[u] + e.cost < dist[v]){
					pq.push({dist[v] = dist[u] + e.cost, v});
					pv[v] = u, pe[v] = id;
				}
			}
		}
	}
	// To find any negative cycle, put every vertices into src
	vector<int> init_bellman_ford(vector<int> src = {0}){ // return edge ids of a negative cycle, {} if none exists
		init(); // For undirected graph, call graph::orient twice instead of graph::link
		for(auto s: src) dist[s] = {};
		int x;
		for(int rep = 0; rep < n; ++ rep){
			x = -1;
			for(int id = 0; id < (int)g->edges.size(); ++ id){
				if(g->ignore && g->ignore(id)) continue;
				auto [u, v, w] = g->edges[id];
				if(dist[u] < inf && dist[u] + w < dist[v]){
					dist[v] = minf < dist[u] + w ? dist[u] + w : minf;
					pv[v] = u, pe[v] = id;
					x = v;
				}
			}
		}
		if(x == -1) return {};
		else{
			for(int i = 0; i < n; ++ i) x = pv[x];
			vector<int> cycle;
			for(int u = x; u != x || cycle.empty(); u = g->edges[pe[u]].from) cycle.push_back(pe[u]);
			return {cycle.rbegin(), cycle.rend()};
		}
	}
	bool init_spfa(vector<int> src = {0}){ // returns false if negative cycle
		init();
		vector<int> cnt(n);
		vector<bool> inq(n);
		deque<int> dq;
		for(auto s: src) dist[s] = {}, dq.push_back(s), inq[s] = true;
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			inq[u] = false;
			for(auto id: g->adj[u]){
				if(g->ignore && g->ignore(id)) continue;
				auto [u, v, w] = g->edges[id];
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					pv[v] = u, pe[v] = id;
					if(!inq[v]){
						dq.push_back(v), inq[v] = true, ++ cnt[v];
						if(cnt[v] > n) return false;
					}
				}
			}
		}
		return true;
	}
	vector<int> path_from_root(int u){
		vector<int> path;
		for(; pe[u] != -1; u = g->edges[pe[u]].from) path.push_back(pe[u]);
		return {path.rbegin(), path.rend()};
	}
	int n;
	T inf, minf;
	graph<T> *g;
	vector<T> dist;
	vector<int> pv, pe;
};

using V = pair<int, long long>;
V operator+(V x, V y){
	return V{x.first + y.first, x.second + y.second};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	const int mx = 16;
	graph<V> g(n * mx), limg(n * 2);
	for(auto u = 0; u < n; ++ u){
		for(auto t = 0; t < mx - 1; ++ t){
			g.orient(u + t * n, u + t * n + n, {0, 1 << t});
		}
	}
	for(auto u = 0; u < n; ++ u){
		limg.orient(u, u + n, {1, 0});
		limg.orient(u + n, u, {1, 0});
	}
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		for(auto t = 0; t < mx; ++ t){
			if(~t & 1){
				g.orient(u + t * n, v + t * n, {0, 1});
			}
			else{
				g.orient(v + t * n, u + t * n, {0, 1});
			}
		}
		limg.orient(v, u, {0, 1});
		limg.orient(u + n, v + n, {0, 1});
	}
	const V inf = pair{numeric_limits<int>::max() / 3, numeric_limits<long long>::max() / 3};
	const V minf = pair{numeric_limits<int>::max() / 3, numeric_limits<long long>::max() / 3};
	shortest_path_tree<V> sptr(&g, inf, minf), limsptr(&limg, inf, minf);
	sptr.init_dijkstra(), limsptr.init_dijkstra({n - 1, 2 * n - 1});
	priority_queue<pair<V, int>, vector<pair<V, int>>, greater<pair<V, int>>> pq;
	V res = inf;
	for(auto t = 0; t < mx; ++ t){
		ctmin(res, sptr.dist[n - 1 + t * n]);
	}
	for(auto t = mx - 2; t < mx; ++ t){
		for(auto u = 0; u < n; ++ u){
			auto cur = sptr.dist[u + t * n] + limsptr.dist[u + (t & 1) * n];
			cur.first += t;
			cur.second -= (1 << t) - 1;
			ctmin(res, cur);
		}
	}
	cout << (Zp(2) ^ res.first) - 1 + res.second << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////