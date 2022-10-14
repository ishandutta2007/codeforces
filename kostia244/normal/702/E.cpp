#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n,k,mn[40][100100],sm[40][100100],p[40][100100];

int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> p[0][i];
	for(int i = 0; i < n; i++)
		cin >> mn[0][i], sm[0][i]=mn[0][i];
	for(int i = 1; i < 34; i++) {
		for(int j = 0; j < n; j++) {
			p[i][j] = p[i-1][p[i-1][j]];
			sm[i][j] = sm[i-1][j] + sm[i-1][p[i-1][j]];
			mn[i][j] = min(mn[i-1][j], mn[i-1][p[i-1][j]]);
		}
	}
	for(int i = 0; i < n; i++) {
		ll u = i, m = LLONG_MAX, s = 0;
		for(int j = 34;j--;) {
			if(k&(1ll<<j)) {
				m = min(m, mn[j][u]);
				s = s + sm[j][u];
				u = p[j][u];
			}
		}
		cout << s << " " << m << "\n";
	}
}