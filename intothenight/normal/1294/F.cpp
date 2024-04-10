#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<class Tuple, size_t ...Is> void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){ ((in >> get<Is>(t)), ...); }
template<class ...Args> istream &operator>>(istream &in, tuple<Args...> &t){ read_tuple(in, t, index_sequence_for<Args...>{}); return in; }
template<class ...Args, template<class...> class T> istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){ for(auto &x: arr) in >> x; return in; }
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
//template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<class Tuple, size_t ...Is> void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){ ((out << (Is ? " " : "") << get<Is>(t)), ...); }
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){ print_tuple(out, t, index_sequence_for<Args...>{}); return out << "\n"; }
template<class ...Args, template<class...> class T> ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vi> adj(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v, u --, v --;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	function<void(int, int)> dfs_init = [&](int u, int p){
		if(p != -1){
			adj[u].erase(find(all(adj[u]), p));
		}
		for(auto v: adj[u]){
			dfs_init(v, u);
		}
	};
	dfs_init(0, -1);
	vector<vpii> res_below(n);
	for(int u = 0; u < n; ++ u){
		res_below[u].resize(sz(adj[u]));
	}
	function<pii(int, int)> dfs_below = [&](int u, int p){
		pii cur{0, u};
		for(int i = 0; i < sz(adj[u]); ++ i){
			int v = adj[u][i];
			res_below[u][i] = dfs_below(v, u);
			++ res_below[u][i].first;
			ctmax(cur, res_below[u][i]);
		}
		return cur;
	};
	dfs_below(0, -1);
	vpii res_above(n);
	function<void(int, int, pii)> dfs_above = [&](int u, int p, pii t){
		res_above[u] = t;
		vector<pair<pii, int>> temp;
		temp.reserve(sz(res_below[u]) + 1);
		temp.emplace_back(t, -1);
		for(int i = 0; i < sz(res_below[u]); ++ i){
			temp.emplace_back(res_below[u][i], i);
		}
		sort(all(temp), greater<pair<pii, int>>());
		if(sz(temp) >= 2) ++ temp[0].first.first, ++ temp[1].first.first;
		for(int i = 0; i < sz(adj[u]); ++ i){
			int v = adj[u][i];
			if(temp[0].second == i){
				dfs_above(v, u, temp[1].first);
			}
			else{
				dfs_above(v, u, temp[0].first);
			}
		}
	};
	dfs_above(0, -1, {0, 0});
	pair<int, tpl> res;
	for(int u = 0; u < n; ++ u){
		res_below[u].push_back(res_above[u]);
		sort(all(res_below[u]), greater<pii>());
		if(sz(res_below[u]) >= 2) ctmax(res, pair<int, tpl>{res_below[u][0].first + res_below[u][1].first, {u + 1, res_below[u][0].second + 1, res_below[u][1].second + 1}});
		if(sz(res_below[u]) >= 3) ctmax(res, pair<int, tpl>{res_below[u][0].first + res_below[u][1].first + res_below[u][2].first, {res_below[u][0].second + 1, res_below[u][1].second + 1, res_below[u][2].second + 1}});
	}
	cout << res.first << "\n" << res.second;
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////