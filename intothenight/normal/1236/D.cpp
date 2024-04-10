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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef tuple<int, int, int> tpl;
typedef vector<string> vs;
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



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto kill = [](){
		cout << "No";
		exit(0);
	};
	int n, m, k;
	cin >> n >> m >> k;
	vector<set<int>> x(n), y(m);
	while(k --){
		int i, j;
		cin >> i >> j, i --, j --;
		x[i].insert(j), y[j].insert(i);
	}
	function<void(int, int, int, int, int)> solve = [&](int type, int xn, int xx, int yn, int yx){
		if(xn > xx || yn > yx){
			return;
		}
		if(type == 0){
			for(int j = yx; y[j].size() == xx - xn + 1; j --){
				for(auto i: y[j]){
					x[i].erase(j);
				}
				y[j].clear();
				yx --;
			}
			if(!x[xn].empty()){
				kill();
			}
			xn ++;
		}
		else if(type == 1){
			for(int i = xx; x[i].size() == yx - yn + 1; i --){
				for(auto j: x[i]){
					y[j].erase(i);
				}
				x[i].clear();
				xx --;
			}
			if(!y[yx].empty()){
				kill();
			}
			yx --;
		}
		else if(type == 2){
			for(int j = yn; y[j].size() == xx - xn + 1; j ++){
				for(auto i: y[j]){
					x[i].erase(j);
				}
				y[j].clear();
				yn ++;
			}
			if(!x[xx].empty()){
				kill();
			}
			xx --;
		}
		else{
			for(int i = xn; x[i].size() == yx - yn + 1; i ++){
				for(auto j: x[i]){
					y[j].erase(i);
				}
				x[i].clear();
				xn ++;
			}
			if(!y[yn].empty()){
				kill();
			}
			yn ++;
		}
		solve((type + 1) % 4, xn, xx, yn, yx);
	};
	solve(0, 0, n - 1, 0, m - 1);
	cout << "Yes";
	return 0;
}

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