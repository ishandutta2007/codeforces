#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 5007
#define DIM2 DIM*150
#define MODULO 998244353 
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const ll INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
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
ll n,m,ans[DIM],flag = 0,vis[DIM];
vector<ll> G[DIM];
void dfs(ll v) {
	vis[v] = 1;
	for (ll to : G[v]) {
		if (vis[to]==1)flag = 1;
		if (vis[to]==0)
		dfs(to);
	}
	vis[v] = 2;
}
int main() {
	schnell;
	cin >> n>>m;
	forn(i, m) {
		ll x, y;
		cin >> x >> y;
		G[x].pb(y);
		ans[i] = (x > y) + 1;
	}
	//memset(ans, -1, sizeof(ans));
	forn(i, n) {
		if (vis[i] == 0)dfs(i);
	}
	if (flag == 1) {
		cout << "2\n";
		forn(i, m)cout << ans[i] << ' ';
	}
	else {
		cout << "1\n";
		forn(i, m)cout << "1 ";
	}
	cout << endl;
	return 0;
}