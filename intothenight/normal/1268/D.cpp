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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<pii> vpii;
template<class T>
using Ftn = function<T(T, T)>;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl;
typedef vector<tpl> vtpl;



const int N = 2e3 + 5;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vs a(n);
	cin >> a;
	vector<bitset<N>> adj(n);
	for(int u = 0; u < n; ++ u){
		for(int v = 0; v < n; ++ v){
			adj[u][v] = a[u][v] - '0';
		}
	}
	vector<bitset<N>> radj(adj);
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < n; ++ j){
			if(i != j){
				radj[i].flip(j);
			}
		}
	}
	// test whether all nodes can be reached from 0
	auto test = [&](const vector<bitset<N>> &adj){
		vector<bitset<N>> dist(n);
		dist[0].set(0), dist[1].set(0);
		for(int v = 0; v < n; ++ v){
			if(adj[0][v]){
				dist[1].set(v);
			}
		}
		int cnt = 1 + adj[0].count();
		for(int d = 2; d < n; ++ d){
			bitset<N> prev(dist[d - 1] ^ dist[d - 2]);
			dist[d] = dist[d - 1];
			for(int u = prev._Find_first(); u < N; u = prev._Find_next(u)){
				dist[d] |= adj[u];
			}
			int delta = (dist[d] ^ dist[d - 1]).count();
			if(!delta) break;
			cnt += delta;
		}
		return cnt == n;
	};
	auto reverse = [&](vector<bitset<N>> &adj, int u){
		for(int v = 0; v < n; ++ v){
			if(u != v){
				adj[u][v].flip();
				adj[v][u].flip();
			}
		}
	};
	if(test(adj) && test(radj)){
		cout << "0 1";
		return 0;
	}
	int cnt = 0;
	for(int u = 0; u < n; ++ u){
		reverse(adj, u), reverse(radj, u);
		if(test(adj) && test(radj)) cnt ++;
		reverse(adj, u), reverse(radj, u);
	}
	if(cnt){
		cout << "1 " << cnt;
		return 0;
	}
	cnt = 0;
	for(int u = 0; u < n; ++ u){
		for(int v = 0; v < n; ++ v){
			if(u != v){
				reverse(adj, u), reverse(radj, u);
				reverse(adj, v), reverse(radj, v);
				if(test(adj) && test(radj)) cnt ++;
				reverse(adj, v), reverse(radj, v);
				reverse(adj, u), reverse(radj, u);
			}
		}
	}
	if(cnt){
		cout << "2 " << cnt;
	}
	else{
		cout << -1;
	}
	return 0;
}
 
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