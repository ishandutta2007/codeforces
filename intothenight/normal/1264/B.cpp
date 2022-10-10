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
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << P.first << " " << P.second << "\n";
	return out;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
ostream &operator<<(ostream &out, const set<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const map<T1, T2> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
using Ftn = function<T(T, T)>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	vi a(4);
	cin >> a;
	auto kill = [](){
		cout << "NO";    
	    exit(0);
	};
	if(!a[2] && !a[3]){
		if(abs(a[1] - a[0]) <= 1){
			cout << "YES\n";
			if(a[1] - a[0] == 1){
				for(int i = 0; i < a[0]; i ++){
					cout << "1 0 ";
				}
				cout << 1;
			}
			else if(a[1] - a[0] == -1){
				for(int i = 0; i < a[1]; i ++){
					cout << "0 1 ";
				}
				cout << 0;
			}
			else{
				for(int i = 0; i < a[0]; i ++){
					cout << "1 0 ";
				}
			}
			return 0;
		}
		else{
			kill();
		}
	}
	if(!a[1] && !a[0]){
		if(abs(a[2] - a[3]) <= 1){
			cout << "YES\n";
			if(a[2] - a[3] == 1){
				for(int i = 0; i < a[3]; i ++){
					cout << "2 3 ";
				}
				cout << 2;
			}
			else if(a[2] - a[3] == -1){
				for(int i = 0; i < a[2]; i ++){
					cout << "3 2 ";
				}
				cout << 3;
			}
			else{
				for(int i = 0; i < a[2]; i ++){
					cout << "2 3 ";
				}
			}
			return 0;
		}
		else{
			kill();
		}
	}
	if(a[0] > a[1] || a[3] > a[2]){
		kill();
	}
	int x = a[1] - a[0], y = a[2] - a[3];
	if(abs(x - y) > 1){
		kill();
	}
	cout << "YES\n";
	if(x - y == 1){
		for(int i = 0; i < y; i ++){
			cout << "1 2 ";
		}
		for(int i = 0; i < a[3]; i ++){
			cout << "3 2 ";
		}
		cout << "1 ";
		for(int i = 0; i < a[0]; i ++){
			cout << "0 1 ";
		}
	}
	else if(x - y == -1){
		for(int i = 0; i < x; i ++){
			cout << "2 1 ";
		}
		for(int i = 0; i < a[0]; i ++){
			cout << "0 1 ";
		}
		cout << "2 ";
		for(int i = 0; i < a[3]; i ++){
			cout << "3 2 ";
		}
	}
	else if(x){
		for(int i = 1; i < x; i ++){
			cout << "1 2 ";
		}
		cout << "1 ";
		for(int i = 0; i < a[0]; i ++){
			cout << "0 1 ";
		}
		cout << "2 ";
		for(int i = 0; i < a[3]; i ++){
			cout << "3 2 ";
		}
	}
	else{
		for(int i = 0; i < a[0]; i ++){
			cout << "0 1 ";
		}
		for(int i = 0; i < a[3]; i ++){
			cout << "2 3 ";
		}
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