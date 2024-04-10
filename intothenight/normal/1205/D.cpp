#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}

struct disjoint{
	int n;
	vector<int> parent;
	disjoint(int _n): n(_n), parent(_n){
		iota(parent.begin(), parent.end(), 0);
	}
	int insert(){
		parent.push_back(parent.size());
		return parent.size() - 1;
	}
	int root(int u){
		return parent[u] == u ? u : (parent[u] = root(parent[u]));
	}
	void merge(int u, int v){
		parent[root(v)] = root(u);
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if(n == 1){
		return 0;
	}
	if(n == 2){
		cout << "1 2 1";
		return 0;
	}
	vector<vi> adj(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v, u --, v --;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	int c;
	vi size(n, 1), parent(n);
	function<void(int, int)> dfs = [&](int u, int p){
		parent[u] = p;
		bool ok = true;
		for(auto &v: adj[u]){
			if(v != p){
				dfs(v, u);
				size[u] += size[v];
				if(size[v] > n >> 1) ok = false;
			}
		}
		if(n - size[u] > n >> 1) ok = false;
		if(ok) c = u;
	};
	dfs(0, 0);
	auto getsize = [&](int u, int p){
		return parent[p] == u ? n - size[p] : size[u];
	};
	disjoint dsu(n);
	priority_queue<pii, vector<pii>, greater<pii>> q;
	for(auto u: adj[c]) q.push({getsize(u, c), u});
	while(sz(q) > 2){
		auto [su, u] = q.top();
		q.pop();
		auto [sv, v] = q.top();
		q.pop();
		dsu.merge(u, v);
		q.push({su + sv, u});
	}
	auto [s1, r1] = q.top();
	q.pop();
	auto [s2, r2] = q.top();
	q.pop();
	vi v1, v2;
	for(int i = s1; i >= 1; i --) v1.push_back(i);
	for(int i = s2; i >= 1; i --) v2.push_back((s1 + 1) * i);
	function<void(int, int, int, vi &)> assign = [&](int u, int p, int sum, vi &arr){
		int val = arr.back();
		arr.pop_back();
		cout << p + 1 << " " << u + 1 << " " << val - sum << "\n";
		for(auto v: adj[u]){
			if(v != p){
				assign(v, u, val, arr);
			}
		}
	};
	for(auto u: adj[c]){
		if(dsu.root(u) == r1){
			assign(u, c, 0, v1);
		}
		else{
			assign(u, c, 0, v2);
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\\\                                  //
//           +++`+``+`+`++++        ///`````````````````````````````\\\                             //
//           ++`+`+``+++`++++  /////```````````````````````````````````\\                           //
//           +++`++`+`+``+++/////`````````````````````````````````````````\\                        //
//             +++`++`+``+///```````````|```````````````````````````````````\\                      //
//          ____++++/++++/`````````````/````````|````````|```````````````````\\                     //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\\                    //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\\                  //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\\                 //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\\                //
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