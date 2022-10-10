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
typedef tuple<int, int, int, int> tpl;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using Ftn = function<T(T, T)>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 

template<class T, class BO>
struct binarylift: vector<vector<pair<int, T>>>{
	int n, root, lg;
	BO bin_op;
	T id;
	vector<vector<pair<int, T>>> up;
	vector<T> val;
	vi depth;
	binarylift(int n, int root, vector<T> val, BO bin_op, T id): n(n), root(root), bin_op(bin_op), id(id)
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
		for(int i = 1; i <= lg; i ++) up[u][i] = {
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
		for(int d = lg; d >= 0; d --) if(dist & (1 << d)){
			res = bin_op(res, up[u][d].second), u = up[u][d].first;
		}
		return {u, res};
	}
	pair<int, T> query(int u, int v){ // LCA, Query Value
		if(depth[u] < depth[v]) swap(u, v);
		T res;
		tie(u, res) = trace_up(u, depth[u] - depth[v]);
		for(int d = lg; d >= 0; d --) if(up[u][d].first != up[v][d].first){
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
 
struct disjoint: vi{
	int N;
	// vector<pii> Log; // For persistency
	disjoint(int N): N(N){
		this->resize(N);
		iota(all((*this)), 0);
	}
	int root(int u){
		// Log.emplace_back(u, (*this)[u]);
		return (*this)[u] == u ? u : ((*this)[u] = root((*this)[u]));
	}
	void merge(int u, int v){
		(*this)[root(v)] = root(u);
	}
	int share(int u, int v){
		return root((*this)[u]) == root((*this)[v]);
	}
	/*void reverse(){
		auto [u, p] = Log.back();
		Log.pop_back();
		(*this)[u] = p;
	}*/
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<tpl> edge(m);
	for(auto &[w, u, v, ind]: edge){
		static int cnt = 0;
		cin >> u >> v >> w, u --, v --, ind = cnt ++;
	}
	sort(all(edge));
	vi ismst(m);
	disjoint dsu(n);
	binarylift lift(n, 0, vi(n, 0), [](int x, int y){return max(x, y);}, 0);
	ll cost = 0;
	for(int i = 0; i < m; i ++){
		auto [w, u, v, ind] = edge[i];
		if(!dsu.share(u, v)){
			ismst[i] = true;
			dsu.merge(u, v);
			lift.insert(u, v, w);
			cost += w;
		}
	}
	lift.init();
	vl res(m);
	for(int i = 0; i < m; i ++){
		auto [w, u, v, ind] = edge[i];
		if(ismst[i]){
			res[ind] = cost;
		}
		else{
			res[ind] = cost - lift.query(u, v).second + w;
		}
	}
	cout << res;
	return 0;
}
/*
7 14
2 4 25
6 4 5
5 6 3
5 7 9
6 1 17
4 7 6
5 4 25
1 2 23
2 3 15
5 1 10
7 6 21
3 7 5
5 3 4
5 2 15
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