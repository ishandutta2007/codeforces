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

// Number Theoric Transformation. Use (998244353, 15311432, 1 << 23) or (7340033, 5, 1 << 20)
int mod = 998244353, root = 15311432, root_pw = 1 << 23, root_1 = modinv(root, mod);
vector<int> ntt(const vector<int> &arr, bool invert){
    int n = arr.size();
    vector<int> a{arr};
    for(int i = 1, j = 0; i < n; i ++){
        int bit = n >> 1;
        for(; j & bit; bit >>= 1){
            j ^= bit;
        }
        j ^= bit;
        if(i < j){
            swap(a[i], a[j]);
        }
    }
    for(int len = 2; len <= n; len <<= 1){
        int wlen = invert ? root_1 : root;
        for(int i = len; i < root_pw; i <<= 1){
            wlen = (int)(1LL * wlen * wlen % mod);
        }
        for(int i = 0; i < n; i += len){
            int w = 1;
            for(int j = 0; j < len / 2; j ++){
                int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }
    if(invert){
        int n_1 = modinv(n, mod);
        for (auto &x: a){
            x = (int)(1LL * x * n_1 % mod);
        }
    }
    return a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi a(n), b(k);
	cin >> a >> b;
	vi cnt(3e5 + 1);
	for(auto x: a){
		cnt[x] ++;
	}
	int sz = 1 << 20;
	vi res(sz);
	for(auto x: b){
		vi p(sz), q(sz);
		p[0] = 1, p[1] = 2;
		q[0] = 1, q[1] = 2, q[2] = 1;
		p = ntt(p, 0), q = ntt(q, 0);
		int c1 = 0, c2 = 0;
		for(int i = 1; i < x; i ++){
			c1 += (cnt[i] == 1);
			c2 += (cnt[i] > 1);
		}
		for(auto &y: p){
			y = modexp(y, c1, mod);
		}
		for(auto &y: q){
			y = modexp(y, c2, mod);
		}
		for(int i = 0; i < sz; i ++){
			p[i] = 1LL * p[i] * q[i] % mod;
		}
		p = ntt(p, 1);
		for(int i = 0; i + x + 1 < sz; i ++){
			(res[i + x + 1] += p[i]) %= mod;
		}
	}
	int qq;
	cin >> qq;
	while(qq --){
		int q;
		cin >> q;
		cout << res[q >> 1] << "\n";
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