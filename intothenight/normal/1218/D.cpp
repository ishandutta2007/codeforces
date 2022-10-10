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


ll modexp(ll b, ll e, ll mod){
	ll res = 1;
	while(e){
		if(e & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		e >>= 1;
	}
	return res;
}
ll modinv(ll b, ll mod){
	return modexp(b, mod - 2, mod);
}


template<class T>
vector<T> xort(const vector<T> &P, bool inverse, const ll mod){
	vector<T> p(P);
	int n = p.size();
	for(int len = 1; 2 * len <= n; len <<= 1){
		for(int i = 0; i < n; i += 2 * len){
			for(int j = 0; j < len; j ++){
				T u = p[i + j], v = p[i + j + len];
				p[i + j] = (u + v) % mod, p[i + j + len] = (u - v + mod) % mod;
			}
		}
	}
	if(inverse){
		for(int i = 0; i < n; i ++){
			(p[i] *= modinv(n, mod)) %= mod;
		}
	}
	return p;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	const ll mod1 = 1e9 + 7;
	const ll mod2 = 998244353;
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n);
	for(int i = 0; i < m; i ++){
		int u, v, w;
		cin >> u >> v >> w, u --, v --;
		adj[u].push_back({v, w}), adj[v].push_back({u, w});
	}
	vector<pii> prev(n);
	vector<vi> cycle;
	vi color(n);
	int sum = 0;
	function<void(int, int)> dfs = [&](int u, int p){
		color[u] = 1;
		for(auto [v, w]: adj[u]){
			if(v - p){
				if(color[v] == 0){
					prev[v] = {u, w};
					sum ^= w;
					dfs(v, u);
				}
				else if(color[v] == 1){
					cycle.push_back({w});
					for(int t = u; t != v; t = prev[t].first){
						sum ^= prev[t].second;
						cycle.back().push_back(prev[t].second);
					}
				}
			}
		}
		color[u] = 2;
	};
	dfs(0, 0);
	int mx = 1024 * 128;
	vl d1(mx, 1), d2(mx, 1);
	for(auto &c: cycle){
		vl temp(mx), tt(mx);
		int t = accumulate(all(c), 0, bit_xor<int>());
		for(auto x: c){
			temp[t ^ x] ++;
		}
		tt = xort(temp, 0, mod2);
		temp = xort(temp, 0, mod1);
		for(int i = 0; i < mx; i ++){
			(d1[i] *= temp[i]) %= mod1;
			(d2[i] *= tt[i]) %= mod2;
		}
	}
	d1 = xort(d1, 1, mod1);
	d2 = xort(d2, 1, mod2);
	int res = 2e9;
	ll cnt;
	for(int i = 0; i < mx; i ++){
		if((d1[i] || d2[i]) && res > (i ^ sum)){
			res = i ^ sum;
			cnt = d1[i];
		}
	}
	cout << res << " " << cnt;
	return 0;
}
/*
 3-(2)>6
 | ^
(3) \______
 |        |
 1-(5)>4 (4)
 |     ___|
(6)  /
 v /
 2-(1)>5
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