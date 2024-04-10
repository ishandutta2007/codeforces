#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
    return out << "(" << arr.first << ", " << arr.second << ") ";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto kill = [](){
	    cout << "NO";
	    exit(0);
	};
	int n;
	cin >> n;
	vector<vi> adj(n);
	int root;
	vi c(n);
	for(int u = 0; u < n; ++ u){
		int p;
		cin >> p >> c[u];
		if(p){
			adj[p - 1].push_back(u);
		}
		else{
			root = u;
		}
	}
	vi val(n);
	function<void(int, int)> inc = [&](int u, int k){
		for(auto v: adj[u]){
			if(val[v] >= k){
				val[v] ++;
			}
			inc(v, k);
		}
	};
	vi m(n, 1e9), size(n, 1);
	int cur = 0;
	function<void(int)> dfs = [&](int u){
		if(adj[u].empty()){
			if(c[u]){
				kill();
			}
			val[u] = m[u] = ++ cur;
		}
		else{
			for(auto v: adj[u]){
				dfs(v);
				size[u] += size[v];
				m[u] = min(m[u], m[v]);
			}
			if(size[u] <= c[u]) kill();
			cur ++;
			val[u] = m[u] + c[u];
			inc(u, val[u]);
		}
	};
	dfs(root);
	cout << "YES\n" << val;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////