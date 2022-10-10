#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << "(" << arr.first << ", " << arr.second << ")";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y);}
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y);}
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

template<class T, class BO>
struct binary_lift: vector<vector<pair<int, T>>>{
	int n, root, lg;
	BO bin_op;
	T id;
	vector<vector<pair<int, T>>> up;
	const vector<T> &val;
	vi depth;
	binary_lift(int n, int root, const vector<T> &val, BO bin_op, T id): n(n), root(root), bin_op(bin_op), id(id)
	, lg(32 - __builtin_clz(n)), depth(n), val(val), up(n, vector<pair<int, T>>(lg + 1)){
		this->resize(n);
	}
	void insert(int u, int v, T w){ // w = id if no edge weight
		(*this)[u].push_back({v, w});
		(*this)[v].push_back({u, w});
	}
	void init(){
		dfs(root, root, id);
	}
	void dfs(int u, int p, T w){
		up[u][0] = {p, bin_op(val[u], w)};
		for(int i = 1; i <= lg; ++ i) up[u][i] = {
			up[up[u][i - 1].first][i - 1].first
			, bin_op(up[u][i - 1].second, up[up[u][i - 1].first][i - 1].second)
		};
		for(auto &[v, x]: (*this)[u]) if(v != p){
			depth[v] = depth[u] + 1;
			dfs(v, u, x);
		}
	}
	pair<int, T> trace_up(int u, int dist){ // Node, Distance (Does not include weight of the node)
		T res = id;
		dist = min(dist, depth[u] - depth[root]);
		for(int d = lg; d >= 0; -- d) if(dist & (1 << d)){
			res = bin_op(res, up[u][d].second), u = up[u][d].first;
		}
		return {u, res};
	}
	pair<int, T> query(int u, int v){ // LCA, Query Value
		if(depth[u] < depth[v]) swap(u, v);
		T res;
		tie(u, res) = trace_up(u, depth[u] - depth[v]);
		for(int d = lg; d >= 0; -- d) if(up[u][d].first != up[v][d].first){
			res = bin_op(res, up[u][d].second), u = up[u][d].first;
			res = bin_op(res, up[v][d].second), v = up[v][d].first;
		}
		if(u != v) res = bin_op(bin_op(res, up[u][0].second), up[v][0].second), u = up[u][0].first;
		return {u, bin_op(res, val[u])};
	}
	int dist(int u, int v){
		return depth[u] + depth[v] - 2 * depth[query(u, v).first];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vi temp(n);
	iota(all(temp), 0);
	binary_lift lift(n, 0, temp, [](int x, int y){return min(x, y);}, (int)2e9);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, u --, v --;
		lift.insert(u, v, (int)2e9);
	}
	lift.init();
	int type, s, last = -1;
	cin >> type >> s, s %= n, -- q;
	while(q --){
		int type, u;
		cin >> type >> u, u = (u + last + 1) % n;
		switch(type){
		case 1:
			s = lift.query(u, s).second;
			break;
		case 2:
			cout << (last = lift.query(u, s).second) + 1 << "\n";
		}
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