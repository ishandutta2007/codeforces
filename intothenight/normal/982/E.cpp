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
mt19937 rnd(time(0));

ll euclid(ll x, ll y, ll &a, ll &b){
	if(y){
		ll d = euclid(y, x % y, b, a);
		return b -= x / y * a, d;
	}
	return a = 1, b = 0, x;
}

ll chinese(ll a, ll m, ll b, ll n){
	ll x, y; euclid(m, n, x, y);
	ll res = a * (y + m) % m * n + b * (x + n) % n * m;
	if(res >= m * n) res -= m * n;
	return res;
}

ll chinese_common(ll a, ll m, ll b, ll n){
	ll d = gcd(m, n);
	if(((b -= a) %= n) < 0) b += n;
	if(b % d) return -1; // No solution
	return d * chinese(0LL, m/d, b/d, n/d) + a;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll n, m, x, y, vx, vy;
	cin >> n >> m >> x >> y >> vx >> vy;
	if(vx == 0){
		if(x == 0){
			if(vy > 0){
				cout << "0 " << m;
			}
			else{
				cout << "0 0";
			}
		}
		else if(x == n){
			if(vy > 0){
				cout << n << " " << m;
			}
			else{
				cout << n << " 0";
			}
		}
		else{
			cout << -1;
		}
	}
	else if(vy == 0){
		if(y == 0){
			if(vx > 0){
				cout << n << " 0";
			}
			else{
				cout << "0 0";
			}
		}
		else if(y == m){
			if(vx > 0){
				cout << n << " " << m;
			}
			else{
				cout << "0 " << m;
			}
		}
		else{
			cout << -1;
		}
	}
	else{
		x *= vx, y *= vy;
		if(x < 0){
			y -= x, x = 0;
		}
		if(y < 0){
			x -= y, y = 0;
		}
		ll t = chinese_common((n - x % n) % n, n, (m - y % m) % m, m);
		if(t == -1){
			cout << -1;
		}
		else{
			ll X = 0, Y = 0;
			if((x + t) % (2 * n)){
				X = n;
			}
			if((y + t) % (2 * m)){
				Y = m;
			}
			cout << X << " " << Y;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\                                    //
//           +++`+``+`+`++++        ///`````````````````````````````\                              //
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