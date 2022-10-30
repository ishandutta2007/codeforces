#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
const ll MOD = 1000000007;
const ll MAXN = 10E18;
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
ll n,m,P[DIM],all = 0,vis[DIM];
vector<ll> G[DIM];
void dfs(ll v) {
	vis[v] = 1;
	for (ll to : G[v]) {
		if (vis[to] == 0)dfs(to);
	}
}
set<ll> S;
int main() {
	schnell;
	cin >> n>>m;
	forn(i, m) {
		ll x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	ll flag = 0,res = 0;
	forn(i, n) {
		if (P[i] == 0) {
			all++;
			forn(j, n)vis[j] = 0;
			for (ll to : G[i]) {
				vis[to] = 1;
			}
			ll sz = G[i].size();
			forn(j, n) {
				if (vis[j] == 1)continue;
				if (P[j] != 0) {
					cout << "-1\n";
					return 0;
				}
				P[j] = all;
				if (G[j].size() != sz) {
					cout << "-1\n";
					return 0;
				}
				for (ll to : G[j]) {
					if (vis[to] == 0) {
						cout << "-1\n";
						return 0;
					}
				}
			}
			res += n-sz;
		}
		if (all > 3) {
			cout << -1 << endl;
			return 0;
		}
	}
	if (res != n || all!=3) {
		cout << "-1\n";
		return 0;
	}
		forn(i, n)cout << P[i] << ' ';
		cout << endl;
	
	return 0;
}