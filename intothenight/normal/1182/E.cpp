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

ll modexp(ll b, ll e, const ll &MOD){
	ll res = 1;
	while(e){
		if(e & 1){
			(res *= b) %= MOD;
		}
		(b *= b) %= MOD;
		e >>= 1;
	}
	return res;
}
ll modinv(ll b, const ll &MOD){
	return modexp(b, MOD - 2, MOD);
}

struct matrix{
	const ll MOD;
	vector<vector<ll>> arr;
	matrix(const vector<vl> &_arr, ll _MOD): arr(_arr), MOD(_MOD){}
	matrix operator*(const matrix &other) const &{
		assert(!arr.empty() && arr[0].size() == other.arr.size());
		int N = arr.size(), M = arr[0].size(), L = other.arr.size();
		vector<vl> res(N, vl(L));
		for(int i = 0; i < N; i ++){
			for(int j = 0; j < L; j ++){
				for(int k = 0; k < M; k ++){
					(res[i][j] += arr[i][k] * other.arr[k][j]) %= MOD;
				}
			}
		}
		return matrix(res, MOD);
	}
	matrix operator=(const matrix &other){
		arr = other.arr;
		return *this;
	}
	matrix operator*=(const matrix &other){
		*this = *this * other;
		return *this;
	}
	matrix operator^(ll e) const{
		int N = arr.size();
		assert(!arr.empty() && N == arr[0].size());
		vector<vl> temp(N, vl(N));
		for(int i = 0; i < N; i ++) temp[i][i] = 1;
		matrix res(temp, MOD), b(*this);
		while(e){
			if(e & 1) res *= b;
			b *= b;
			e >>= 1;
		}
		return res;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	const ll MOD = 1e9 + 7;
	matrix T(vector<vl>{{0, 0, 1}, {1, 0, 1}, {0, 1, 1}}, MOD - 1);
	T = T ^ (n - 3);
	cout << modinv((modexp(c, n, MOD)), MOD) * modexp(f1*c%MOD, T.arr[0][2], MOD) % MOD * modexp(f2*c%MOD*c%MOD, T.arr[1][2], MOD) % MOD * modexp(f3*c%MOD*c%MOD*c%MOD, T.arr[2][2], MOD) % MOD;
	return 0;
}
/*
1000000000000000000 1 1 1 1

*/

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