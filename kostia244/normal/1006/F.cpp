//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k, a[22][22];
map<ll, ll> can[22][22];
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	ll sz1 = n-1, sz2 = m-1;
	for(ll msk = 0; msk < 1<<sz1; msk++) {
		ll val = a[1][1], x=1,y=1;
		for(int i = 0; i < sz1; i++) {
			if((msk>>i)&1) x++;
			else y++;
			if(x>n||y>m) break;
			val^=a[x][y];
		}
		if(x>n||y>m) continue;
//		cout << x << " " << y << " " << val << "\n";
		can[x][y][val]++;
	}
//	cout << "====\n";
	ll ans = 0;
	for(ll msk = 0; msk < 1<<sz2; msk++) {
		ll val = a[n][m], x=n,y=m;
		for(int i = 0; i < sz2; i++) {
			if((msk>>i)&1) x--;
			else y--;
			if(!x||!y) break;
			val^=a[x][y];
		}
		if(!x||!y) continue;
		val^=a[x][y];
//		cout << x << " " << y << " " << val << "\n";
		ans += can[x][y][k^val];
	}
	cout << ans;
}