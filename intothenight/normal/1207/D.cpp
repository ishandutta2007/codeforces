#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	const ll mod = 998244353;
	int n;
	cin >> n;
	vector<pii> a(n);
	cin >> a;
	vl fact{1};
	for(int i = 1; i <= n; i ++){
		fact.push_back(fact.back() * i % mod);
	}
	ll res = fact[n];
	sort(all(a));
	vl temp;
	for(int i = 0; i < n; i ++){
		if(!i || a[i].first != a[i - 1].first){
			temp.push_back(1LL);
		}
		else{
			temp.back() ++;
		}
	}
	(res += mod - accumulate(all(temp), 1LL, [&](ll x, ll y){return x * fact[y] % mod;})) %= mod;
	sort(all(a), [](pii x, pii y){return x.second < y.second;});
	temp.clear();
	for(int i = 0; i < n; i ++){
		if(!i || a[i].second != a[i - 1].second){
			temp.push_back(1LL);
		}
		else{
			temp.back() ++;
		}
	}
	(res += mod - accumulate(all(temp), 1LL, [&](ll x, ll y){return x * fact[y] % mod;})) %= mod;
	sort(all(a));
	temp.clear();
	for(int i = 0; i < n; i ++){
		if(i && a[i].second < a[i - 1].second){
			cout << res;
			return 0;
		}
		if(!i || a[i].first != a[i - 1].first || a[i].second != a[i - 1].second){
			temp.push_back(1LL);
		}
		else{
			temp.back() ++;
		}
	}
	(res += accumulate(all(temp), 1LL, [&](ll x, ll y){return x * fact[y] % mod;})) %= mod;
	cout << res;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\\\                                  //
//           +++`+``+`+`++++        ///`````````````````````````````\\\                             //
//           ++`+`+``+++`++++  /////```````````````````````````````````\\                           //
//           +++`++`+`+``+++/////`````````````````````````````````````````\\                        //
//             +++`++`+``+///```````````|```````````````````````````````````\\                      //
//          ____++++/++++/`````````````/````````|````````|```````````````````\\                     //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\\                    //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\\                  //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\\                 //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\\                //
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