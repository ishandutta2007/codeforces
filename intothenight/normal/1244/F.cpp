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
	int n, k;
	string s;
	cin >> n >> k >> s;
	vi visited(n), dis(n, n);
	deque<int> q;
	for(int i = 0; i < n; i ++){
		if(s[(i + 1) % n] == s[i] || s[(i + n - 1) % n] == s[i]){
			visited[i] = true;
			q.push_back(i);
			dis[i] = 0;
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		vi t{(u + 1) % n, (u + n - 1) % n};
		for(auto v: t){
			if(!visited[v]){
				visited[v] = true;
				q.push_back(v);
				dis[v] = min(k, dis[u] + 1);
			}
		}
	}
	for(int u = 0; u < n; u ++){
		if(dis[u] % 2){
			if(s[u] == 'B'){
				cout << 'W';
			}
			else{
				cout << 'B';
			}
		}
		else{
			if(s[u] == 'B'){
				cout << 'B';
			}
			else{
				cout << 'W';
			}
		}
	}
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