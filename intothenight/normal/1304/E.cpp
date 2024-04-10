#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename L, typename R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<typename Tuple, size_t ...Is> void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){ ((in >> get<Is>(t)), ...); }
template<typename ...Args> istream &operator>>(istream &in, tuple<Args...> &t){ read_tuple(in, t, index_sequence_for<Args...>{}); return in; }
template<typename ...Args, template<typename...> typename T> istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){ for(auto &x: arr) in >> x; return in; }
template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
//template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<typename Tuple, size_t ...Is> void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){ ((out << (Is ? " " : "") << get<Is>(t)), ...); }
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){ print_tuple(out, t, index_sequence_for<Args...>{}); return out << "\n"; }
template<typename ...Args, template<typename...> typename T> ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

struct binary_lift: vector<vi>{
	int N, root, lg;
	vector<vi> up;
	vi depth;
	binary_lift(int N, int root): N(N), root(root), lg(ceil(log2(N))), depth(N), up(N, vector<int>(lg + 1)){
		this->resize(N);
	}
	void insert(int u, int v){
		(*this)[u].push_back(v);
		(*this)[v].push_back(u);
	}
	void init(){
		dfs(root, root);
	}
	void dfs(int u, int p){
		up[u][0] = p;
		for(int i = 1; i <= lg; ++ i) up[u][i] = up[up[u][i - 1]][i - 1];
		for(auto &v: (*this)[u]) if(v != p){
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
	int lca(int u, int v){
		if(depth[u] < depth[v]) std::swap(u, v);
		u = trace_up(u, depth[u] - depth[v]);
		for(int d = lg; d >= 0; -- d) if(up[u][d] != up[v][d]) u = up[u][d], v = up[v][d];
		return u == v ? u : up[u][0];
	}
	int dist(int u, int v){
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}
	int trace_up(int u, int dist){
		if(dist >= depth[u] - depth[root]) return root;
		for(int d = lg; d >= 0; -- d) if(dist & (1 << d)) u = up[u][d];
		return u;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	binary_lift lift(n, 0);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		lift.insert(u, v);
	}
	lift.init();
	int qq;
	cin >> qq;
	while(qq --){
		int u, v, a, b, k;
		cin >> u >> v >> a >> b >> k, -- u, -- v, -- a, -- b;
		bool ok = false;
		int d = lift.dist(a, b), e;
		if(d <= k && (k - d) % 2 == 0) ok = true;
		if(!ok){
			d = lift.dist(a, u), e = lift.dist(b, v);
			if(d + e + 1 <= k && (k - d - e - 1) % 2 == 0) ok = true;
			if(!ok){
				d = lift.dist(a, v), e = lift.dist(b, u);
				if(d + e + 1 <= k && (k - d - e - 1) % 2 == 0) ok = true;
			}
		}
		ok ? cout << "YES\n" : cout << "NO\n";
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