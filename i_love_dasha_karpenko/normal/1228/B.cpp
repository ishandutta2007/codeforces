#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 1007
const ll MOD = 1000000007;
const ll MAXN = DIM * (DIM + 1) / 2;
const ll INF = 10E16;
const ll masksz = 1048576;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n, m,vis[DIM][DIM];
ll P(ll x) {
	ll ret = 1;
	forn(i, x) {
		ret *= 2;
		ret %= MOD;
	}
	return ret;
}
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n) {
		ll x; cin >> x;
		for (ll j = 1; j <= x; j++)vis[i][j] = 1;
		vis[i][x + 1] = -1;
	}
	forn(i, m) {
		ll x; cin >> x;
		for (ll j = 1; j <= x; j++) {
			if (vis[j][i] == -1) {
				cout << 0 << endl;
				return 0;
			}
			vis[j][i] = 1;
		}
		if (vis[x + 1][i] == 1) {
			cout << 0 << endl;
			return 0;
		}
		vis[x + 1][i] = -1;
	}
	ll r = 0;
	forn(i, n) {
		forn(j, m)if (vis[i][j] == 0)r++;
	}
	cout << P(r) << endl;
	return 0;
}