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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		string s;
		cin >> s;
		int n = sz(s);
		vector<vi> d(n + 1, vi(5, 2e9)); // 0:empty, 1:o, 2:on, X:one, 3:t, 4:tw, X:two
		vector<vpii> prev(n + 1, vpii(5)); 
		d[0][0] = 0;
		auto update = [&](int i, int j, int ii, int jj, int val){
			if(d[ii][jj] > d[i][j] + val){
				d[ii][jj] = d[i][j] + val;
				prev[ii][jj] = {i, j};
			}
		};
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < 5; j ++){
				update(i, j, i + 1, j, 1);
			}
			switch(s[i]){
				case 'o':
				for(int j = 0; j < 4; j ++){
					update(i, j, i + 1, 1, 0);
				}
				break;
				case 'n':
				for(int j = 0; j < 5; j ++) if(j != 1){
					update(i, j, i + 1, 0, 0);
				}
				update(i, 1, i + 1, 2, 0);
				break;
				case 'e':
				for(int j = 0; j < 5; j ++) if(j != 2){
					update(i, j, i + 1, 0, 0);
				}
				break;
				case 't':
				for(int j = 0; j < 5; j ++){
					update(i, j, i + 1, 3, 0);
				}
				break;
				case 'w':
				for(int j = 0; j < 5; j ++) if(j != 3){
					update(i, j, i + 1, 0, 0);
				}
				update(i, 3, i + 1, 4, 0);
				break;
				default:
				for(int j = 0; j < 5; j ++){
					update(i, j, i + 1, 0, 0);
				}
			}
		}
		int j = 0;
		for(int k = 1; k < 5; k ++){
			if(d[n][j] > d[n][k]){
				j = k;
			}
		}
		cout << d[n][j] << "\n";
		int i = n;
		const int MX = 2e9;
		while(d[i][j] && d[i][j] != MX){
			auto [ii, jj] = prev[i][j];
			if(d[i][j] > d[ii][jj]){
				cout << i << " ";
			}
			tie(i, j) = pii(ii, jj);
		}
		cout << "\n";
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