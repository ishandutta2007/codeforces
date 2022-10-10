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

ll modexp(ll b, ll e, ll mod){
	ll res = 1;
	while(e){
		if(e & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		e >>= 1;
	}
	return res;
}
ll modinv(ll b, ll mod){
	return modexp(b, mod - 2, mod);
}

void linearsieve(int n, vector<int> &lpf, vector<int> &prime){
	lpf.resize(n + 1);
	prime.reserve(n + 1);
	for(int i = 2; i <= n; i ++){
		if(!lpf[i]){
			lpf[i] = i;
			prime.push_back(i);
		}
		for(int j = 0; j < prime.size() && prime[j] <= lpf[i] && i * prime[j] <= n; j ++){
			lpf[i * prime[j]] = prime[j];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	const ll mod = 1e9 + 7;
	vl pn(k + 1);
	for(int i = 1; i <= k; i ++){
		pn[i] = modexp(i, n, mod);
	}
	vi lpf, prime;
	linearsieve(k, lpf, prime);
	vi mobius(k + 1);
	for(int i = 1; i <= k; i ++){
		int cnt = 0, t = i;
		while(t != 1){
			cnt ++;
			int p = lpf[t], temp = 0;
			while(t % p == 0){
				temp ++;
				t /= p;
			}
			if(temp >= 2){
				cnt = -1;
				break;
			}
		}
		if(cnt == -1){
			mobius[i] = 0;
		}
		else if(cnt % 2){
			mobius[i] = -1;
		}
		else{
			mobius[i] = 1;
		}
	}
	vector<vi> div(k + 1);
	for(int i = 1; i <= k; i ++){
		for(int j = i; j <= k; j += i){
			div[j].push_back(i);
		}
	}
	ll sum = 0, res = 0;
	for(int i = 1; i <= k; i ++){
		for(auto d: div[i]){
			sum = (sum + mobius[d] * (pn[i / d] - pn[i / d - 1])) % mod;
		}
		sum = (sum + mod) % mod;
		(res += (sum ^ i) % mod) %= mod;
	}
	cout << res;
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