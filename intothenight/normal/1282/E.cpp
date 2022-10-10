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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		cin >> n;
		vector<array<int, 3>> t(n - 1);
		map<pii, vi> appear;
		vector<vi> tri(n + 1);
		for(int i = 1; i <= n - 2; ++ i){
			int a, b, c;
			cin >> a >> b >> c;
			t[i] = {a, b, c};
			appear[{a, b}].push_back(i);
			appear[{b, a}].push_back(i);
			appear[{b, c}].push_back(i);
			appear[{c, b}].push_back(i);
			appear[{c, a}].push_back(i);
			appear[{a, c}].push_back(i);
			tri[a].push_back(i), tri[b].push_back(i), tri[c].push_back(i);
		}
		auto del = [&](int ind){
			auto [a, b, c] = t[ind];
			array<pii, 3> temp{{{a, b}, {b, c}, {c, a}}};
			for(auto [u, v]: temp){
				auto x = appear[{u, v}];
				if(sz(x) == 1){
					appear.erase(appear.find({u, v}));
					appear.erase(appear.find({v, u}));
				}
				else{
					x.erase(find(all(x), ind));
					appear[{u, v}] = appear[{v, u}] = x;
				}
			}
		};
		vi ord, res;
		int u, v;
		for(auto p: appear){
			if(sz(p.second) == 1){
				tie(u, v) = p.first;
				break;
			}
		}
		ord.push_back(u), ord.push_back(v);
		function<void(int, int)> solve = [&](int u, int v){
			auto x = appear[{u, v}];
			if(x.empty()) return;
			int ind = x[0];
			int w;
			for(auto k: t[ind]){
				if(k != u && k != v){
					w = k;
				}
			}
			del(ind);
			solve(w, v);
			ord.push_back(w);
			solve(u, w);
			res.push_back(ind);
		};
		solve(u, v);
		cout << ord << res;
	}
	return 0;
}
/*
1
6
2 5 6
2 5 1
4 1 2
1 3 5
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