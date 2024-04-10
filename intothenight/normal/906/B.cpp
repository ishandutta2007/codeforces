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
typedef tuple<int, int, int> tpl;template<class T>
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



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto kill = [](){
	    cout << "NO";
	    exit(0);
	};
	int n, m;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << "YES\n1";
		return 0;
	}
	if(n + m <= 4 || n + m == 5 && n != 1 && m != 1){
		kill();
	}
	function<bool(vi &)> ok = [&](vi &a){
		for(int i = 0; i < n; i ++){
			for(int j = 1; j < m; j ++){
				if(abs(a[i * m + j] - a[i * m + j - 1]) == 1 || abs(a[i * m + j] - a[i * m + j - 1]) == m){
					return false;
				}
			}
		}
		for(int i = 1; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(abs(a[i * m + j] - a[(i - 1) * m + j]) == 1 || abs(a[i * m + j] - a[(i - 1) * m + j]) == m){
					return false;
				}
			}
		}
		return true;
	};
	vi a(n * m);
	iota(all(a), 1);
	while(!ok(a)){
		shuffle(all(a), rnd);
	}
	cout << "YES\n" << a;
	return 0;
}
/*
? 1 ? 2 ? 3 ...

*/
 
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\                                  //
//           +++`+``+`+`++++        ///`````````````````````````````\\                             //
//           ++`+`+``+++`++++  /////```````````````````````````````````\                           //
//           +++`++`+`+``+++/////`````````````````````````````````````````\                        //
//             +++`++`+``+///```````````|```````````````````````````````````\                      //
//          ____++++/++++/`````````````/````````|````````|```````````````````\                     //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\                    //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\                  //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\                 //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\                //
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