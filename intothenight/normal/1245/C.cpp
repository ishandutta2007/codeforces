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

struct recurrence{
	int N;
	vl init, coef;
	ll mod;
	recurrence(vl init, vl coef, ll mod):
		N(coef.size()), init(init), coef(coef), mod(mod){
	}
	recurrence(vl s, ll mod): mod(mod){
		int n = s.size();
		N = 0;
		vl B(n), T;
		coef.resize(n);
		coef[0] = B[0] = 1;
		ll b = 1;
		for(int i = 0, m = 0; i < n; i ++){
			m ++;
			ll d = s[i] % mod;
			for(int j = 1; j <= N; j ++){
				d = (d + coef[j] * s[i - j]) % mod;
			}
			if(!d) continue;
			T = coef;
			ll c = d * modexp(b, mod - 2, mod) % mod;
			for(int j = m; j < n; j ++){
				coef[j] = (coef[j] - c * B[j - m]) % mod;
			}
			if(2 * N > i) continue;
			N = i + 1 - N, B = T, b = d, m = 0;
		}
		coef.resize(N + 1), coef.erase(coef.begin());
		for(auto &x: coef){
			x = (mod - x) % mod;
		}
		reverse(all(coef));
		init.resize(N);
		for(int i = 0; i < N; i ++){
			init[i] = s[i] % mod;
		}
	}
	ll operator[](ll n) const{
		auto combine = [&](vl a, vl b){
			vl res(2 * N + 1);
			for(int i = 0; i <= N; i ++){
				for(int j = 0; j <= N; j ++){
					res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
				}
			}
			for(int i = 2 * N; i > N; i --){
				for(int j = 0; j < N; j ++){
					res[i - 1 - j] = (res[i - 1 - j] + res[i] * coef[N - 1 - j]) % mod;
				}
			}
			res.resize(N + 1);
			return res;
		};
		vl pol(N + 1), e(pol);
		pol[0] = e[1] = 1;
		for(n ++; n; n /= 2){
			if(n % 2) pol = combine(pol, e);
			e = combine(e, e);
		}
		ll res = 0;
		for(int i = 0; i < N; i ++){
			res = (res + pol[i + 1] * init[i]) % mod;
		}
		return res;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	const ll mod = 1e9 + 7;
	string s;
	cin >> s;
	int n = s.size();
	ll res = 1;
	recurrence f({1, 1}, {1, 1}, mod);
	for(int i = 0; i < n; i ++){
		if(s[i] == 'w' || s[i] == 'm'){
			cout << "0";
			return 0;
		}
		if(s[i] == 'u' || s[i] == 'n'){
			int cnt = 1;
			char c = s[i];
			while(i < n - 1 && s[i + 1] == c){
				i ++;
				cnt ++;
			}
			(res *= f[cnt]) %= mod;
		}
	}
	cout << res;
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