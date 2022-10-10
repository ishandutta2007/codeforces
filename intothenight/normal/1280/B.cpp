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
	const ll mod = 1e9 + 7;
	int tt;
	cin >> tt;
	while(tt --){
		int r, c;
		cin >> r >> c;
		vs a(r);
		cin >> a;
		bool ok = false;
		vector<vi> cnt(r + 1, vi(c + 1));// count of P
		pii X{2e9, 0}, Y{2e9, 0};
		for(int i = 0; i < r; i ++){
			for(int j = 0; j < c; j ++){
				if(a[i][j] == 'A') ok = true;
				else{
					X = {min(X.first, i), max(X.second, i + 1)};
					Y = {min(Y.first, j), max(Y.second, j + 1)};
				}
				cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + (a[i][j] == 'P');
			}
		}
		if(!ok){
			cout << "MORTAL\n";
			continue;
		}
		if(!cnt[r][c]){
			cout << "0\n";
			continue;
		}
		auto cntp = [&](int x, int y, int xx, int yy){
			return cnt[xx][yy] - cnt[x][yy] - cnt[xx][y] + cnt[x][y];
		};
		if(X.first || Y.first || X.second != r || Y.second != c){
			cout << "1\n";
			continue;
		}
		ok = false;
		for(int i = 0; i < r; i ++){
			if(!cntp(i, 0, i + 1, c)){
				ok = true;
				break;
			}
		}
		for(int j = 0; j < c; j ++){
			if(!cntp(0, j, r, j + 1)){
				ok = true;
				break;
			}
		}
		if(ok || a[0][0] == 'A' || a[0][c - 1] == 'A'
		|| a[r - 1][0] == 'A' || a[r - 1][c - 1] == 'A'){
			cout << "2\n";
			continue;
		}
		if(cntp(0, 0, 1, c) < c || cntp(r - 1, 0, r, c) < c
		|| cntp(0, 0, r, 1) < r || cntp(0, c - 1, r, c) < r){
			cout << "3\n";
			continue;
		}
		cout << "4\n";
	}
	return 0;
}
/*
1
24
133321333
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