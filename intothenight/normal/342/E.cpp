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
    return out << arr.first << " " << arr.second << "\n";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef tuple<int, int, int> tpl;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using Ftn = function<T(T, T)>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct CD: vector<vi>{
	int N, root;
	vi dead, sz, par;
	vector<pii> cpar;
	vector<vi> dist;
	CD(int N, int root): N(N), root(root), dead(N), sz(N), par(N), cpar(N), dist(N){
		this->resize(N);
	}
	void insert(int u, int v){
		(*this)[u].push_back(v);
		(*this)[v].push_back(u);
	}
	void dfs_sz(int u){
		sz[u] = 1;
		for(auto v: (*this)[u]) if(!dead[v] && v != par[u]){
			par[v] = u;
			dfs_sz(v);
			sz[u] += sz[v];
		}
	}
	int centroid(int u){
		par[u] = -1;
		dfs_sz(u);
		int size = sz[u];
		while(1){
			int w = 0, msz = 0;
			for(auto v: (*this)[u]) if(!dead[v] && v != par[u] && msz < sz[v]){
				w = v, msz = sz[v];
			}
			if(msz * 2 <= size) return u;
			u = w;
		}
	}
	void dfs_dist(int u, int p){
		dist[u].push_back(dist[p].back() + 1);
		for(auto v: (*this)[u]) if(!dead[v] && v != p) dfs_dist(v, u);
	}
	void dfs_centroid(pii t, int u){
		dead[u = centroid(u)] = true;
		cpar[u] = t;
		dist[u].push_back(0);
		int d = 0;
		for(auto v: (*this)[u]) if(!dead[v]) dfs_dist(v, u);
		for(auto v: (*this)[u]) if(!dead[v]) dfs_centroid({u, d ++}, v);
	}
	void init(){
		dfs_centroid({-1, 0}, root);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	CD cd(n, 0);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v, u --, v --;
		cd.insert(u, v);
	}
	cd.init();
	vi res(n, 1e9);
	auto update = [&](int u){
		for(int t = cd.dist[u].size(), v = u; v != -1; v = cd.cpar[v].first){
			res[v] = min(res[v], cd.dist[u][-- t]);
		}
	};
	auto query = [&](int u){
		int ans = 1e9;
		for(int t = cd.dist[u].size(), v = u; v != -1; v = cd.cpar[v].first){
			ans = min(ans, cd.dist[u][-- t] + res[v]);
		}
		return ans;
	};
	update(0);
	while(q --){
		int t, u;
		cin >> t >> u, u --;
		if(t == 1){
			update(u);
		}
		else{
			cout << query(u) << "\n";
		}
	}
	return 0;
}
/*
10 9
10 7
10 6
1 4
7 8
5 1
6 2
7 5
6 3
7 9

2 9
2 8
2 2
2 7
2 6
2 8
2 1
2 6
2 4
*/
 
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\                                     //
//           +++`+``+`+`++++        ///`````````````````````````````\                               //
//           ++`+`+``+++`++++  /////```````````````````````````````````\                            //
//           +++`++`+`+``+++/////`````````````````````````````````````````\                         //
//             +++`++`+``+///```````````|```````````````````````````````````\                       //
//          ____++++/++++/`````````````/````````|````````|```````````````````\                      //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\                     //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\                   //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\                  //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\                 //
//       /\___|__//`|``|```````|`    |      ``:|````````|:```````|```````|```|`````|                //
//      /     /  /``|``|``````|/     |        :|     ```:|```````|```````|``++````++                //
//     /     / //```|``|``````|      |        |:        :|    ```|```````|```++``++`\               //
//     |    /  /````|``|``````/    _.::::.    |          |      |    ````|```|`++`\`|               //
//     |   /   |````|``|`````|            `                    |       ``|```++``++`|               //
//     |  /    |````|``|`````|                                 :         |``++````++|               //
//     | /     /````|``|`````|                              _.-:::.      |..`|``.`|.|               //
//     |/     /`````|``|`````|                                     `     |```|````|`|               //
//    /|      |`````|``|`````|                    :'                    .|```|````|.|               //
//   / |      |`````|``|`````|                                         /|-|``|````|`|               //
//  /  |      |`````|```\````|                                        / ||```|````|``\              //
// /   |      |`````|````|```|::                                    /_| ||```|````|``|              //
//            |`````|````|```|:|:.        `.._                    .\___/:|```|````|``|              //
//            |`````\````|```|:|::-          ``:::....           -:|:|:::|```|````|``|              //
//            |``````|```|```|:|::`|.                          .:::|:|:::|```|````|``|              //
//             \`````|```|```|:|::/|--.                     .`:|:::|:|:::/```|````|``|              //
//              |````|```|```\:|:|:|-----             _..-:|:|:|:::|:|::|````|````|`/               //
//              |````|```|````\|:|:|-------.____.....------|/::|:::|:|::|````|````|`|               //
//              |````|```|\````\:|/\___________    ________/\--\:::|:|::|````/````|`|               //
//              |````\```| \```|:/-------------\  /----------\``\::|:|::|```/`````|`|               //
//              |`````|``|  \``|/---------------\/------------\_________|```|`````|`|               //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                        Created by Aeren                                          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////