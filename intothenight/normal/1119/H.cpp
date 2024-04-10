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


template<class T>
vector<T> xort(const vector<T> &P, bool inverse, const ll mod){
	vector<T> p(P);
	int n = p.size();
	for(int len = 1; 2 * len <= n; len <<= 1){
		for(int i = 0; i < n; i += 2 * len){
			for(int j = 0; j < len; j ++){
				T u = p[i + j], v = p[i + j + len];
				p[i + j] = (u + v) % mod, p[i + j + len] = (u - v + mod) % mod;
			}
		}
	}
	if(inverse){
		for(int i = 0; i < n; i ++){
			(p[i] *= modinv(n, mod)) %= mod;
		}
	}
	return p;
}

// Find a solution of the system of linear equations. Return -1 if no sol, rank otherwise.
int solvele(const vector<vl> &AA, vl &x, const vl &bb, ll mod){
	auto A = AA;
	auto b = bb;
	int n = A.size(), m = A[0].size(), rank = 0, br, bc;
	vi col(m);
	iota(col.begin(), col.end(), 0);
	for(auto &x: A){
		for(auto &y: x){
			y %= mod;
		}
	}
	for(int i = 0; i < n; i ++){
		long long v, bv = 0;
		for(int r = i; r < n; r ++){
			for(int c = i; c < m; c ++){
				if((v = abs(A[r][c])) > bv){
					br = r, bc = c, bv = v;
				}
			}
		}
		if(!bv){
			for(int j = i; j < n; j ++){
				if(abs(b[j])){
					return -1;
				}
			}
			break;
		}
		swap(A[i], A[br]), swap(b[i], b[br]), swap(col[i], col[bc]);
		for(int j = 0; j < n; j ++){
			swap(A[j][i], A[j][bc]);
		}
		bv = modinv(A[i][i], mod);
		for(int j = i + 1; j < n; j ++){
			ll fac = A[j][i] * bv % mod;
			b[j] = (b[j] - fac * b[i] % mod + mod) % mod;
			for(int k = i + 1; k < m; k ++){
				A[j][k] = (A[j][k] - fac * A[i][k] % mod + mod) % mod;
			}
		}
		rank ++;
	}
	x.resize(m);
	for(int i = rank; i --; ){
		b[i] = b[i] * modinv(A[i][i], mod) % mod;
		x[col[i]] = b[i];
		for(int j = 0; j < i; j ++){
			b[j] = (b[j] - A[j][i] * b[i] % mod + mod) % mod;
		}
	}
	return rank;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	const ll mod = 998244353;
	int n, k;
	cin >> n >> k;
	ll x, y, z;
	cin >> x >> y >> z;
	vector<vl> a(n, vl(3));
	cin >> a;
	int sum = 0;
	for(int i = 0; i < n; i ++){
		sum ^= a[i][0];
	}
	vector<vl> A, b(1 << k);
	function<void(vl, int)> solve = [&](vl c, int type){
		vl t(1 << k);
		for(int i = 0; i < n; i ++){
			t[0] += c[0];
			(t[a[i][0] ^ a[i][1]] += c[1]) % mod;
			(t[a[i][0] ^ a[i][2]] += c[2]) % mod;
			(t[a[i][1] ^ a[i][2]] += c[3]) % mod;
		}
		t = xort(t, 0, mod);
		if(type){
			A.push_back({
				(c[0] + c[1] + c[2]) % mod,
				(c[0] + c[1] - c[2] + mod) % mod,
				(c[0] - c[1] + c[2] + mod) % mod,
				(c[0] - c[1] - c[2] + 2 * mod) % mod
			});
		}
		else{
			A.push_back({1, -1, -1, 1});
		}
		for(int i = 0; i < (1 << k); i ++){
			b[i].push_back(t[i]);
		}
	};
	solve({x + 1, y, z, 0}, 1);
	solve({x, y + 1, z, 0}, 1);
	solve({x, y, z + 1, 0}, 1);
	solve({0, 0, 0, 1}, 0);
	vl res(1 << k);
	for(int i = 0; i < (1 << k); i ++){
		vl coef;
		solvele(A, coef, b[i], mod);
		res[i] = modexp(x + y + z, coef[0], mod)
			* modexp((x + y - z + mod) % mod, coef[1], mod) % mod
			* modexp((x - y + z + mod) % mod, coef[2], mod) % mod
			* modexp((x - y - z + 2 * mod) % mod, coef[3], mod) % mod;
	}
	res = xort(res, 1, mod);
	for(int i = 0; i < (1 << k); i ++){
		cout << res[i ^ sum] << " ";
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\                                    //
//           +++`+``+`+`++++        ///`````````````````````````````\\                              //
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