#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
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
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
mt19937 rnd(time(0));

pair<vi, vector<vi>> scc(const vector<vi> &adj, const vector<vi> &radj){
	int n = adj.size();
	vi visited(n), order, assign(n);
	vector<vi> comp;
	function<void(int)> dfs1 = [&](int u){
		visited[u] = true;
		for(auto v: adj[u]){
			if(!visited[v]){
				dfs1(v);
			}
		}
		order.push_back(u);
	};
	for(int u = 0; u < n; u ++){
		if(!visited[u]){
			dfs1(u);
		}
	}
	reverse(all(order));
	fill(all(visited), false);
	function<void(int)> dfs2 = [&](int u){
		visited[u] = true;
		assign[u] = comp.size() - 1;
		comp.back().push_back(u);
		for(auto v: radj[u]){
			if(!visited[v]){
				dfs2(v);
			}
		}
	};
	for(auto u: order){
		if(!visited[u]){
			comp.push_back(vi());
			dfs2(u);
		}
	}
	return pair<vi, vector<vi>>(assign, comp);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<tpl> edge(m);
	vector<vi> t(n), tt(n);
	for(auto &[u, v, w]: edge){
		cin >> u >> v >> w, u --, v --;
		t[u].push_back(v), tt[v].push_back(u);
	}
	auto [assign, comp] = scc(t, tt);
	auto solve = [&](ll x){
		ll l = 0, r = 1e5;
		while(r - l > 1){
			ll m = l + r >> 1;
			if(m * (m + 1) / 2 <= x){
				l = m;
			}
			else{
				r = m;
			}
		}
		return x * (l + 1) - (l + 1) * l * (l + 1) / 2 + l * (l + 1) * (2 * l + 1) / 6;
	};
	vector<vector<pii>> adj(comp.size());
	vl cost(comp.size());
	for(auto [u, v, w]: edge){
		if(assign[u] == assign[v]){
			cost[assign[u]] += solve(w);
		}
		else{
			adj[assign[u]].push_back({assign[v], w});	
		}
	}
	int s;
	cin >> s, s --;
	vl d(comp.size(), -9e18);
	d[assign[s]] = cost[assign[s]];
	for(int i = 0; i < comp.size(); i ++){
		for(auto [j, w]: adj[i]){
			d[j] = max(d[j], cost[j] + w + d[i]);
		}
	}
	cout << *max_element(all(d));
	return 0;
}
/*
10 10
2 2 2 2 2 2 2 2 2 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 1
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\                                    //
//           +++`+``+`+`++++        ///`````````````````````````````\\                              //
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