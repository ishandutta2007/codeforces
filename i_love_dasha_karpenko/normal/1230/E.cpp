#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
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
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}
ll n,A[DIM],res = 0;
vector<ll> G[DIM];
ll __gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
void dfs(ll v, map<ll, ll> M,ll par) {
	map<ll, ll> g;
	res =(res+ A[v])%MOD;
	g[A[v]] = 1;
	for (auto t : M) {
		res =(res+ __gcd(A[v], t.first) * t.second)%MOD;
		g[__gcd(A[v], t.first)] += t.second;
	}
	for (ll to : G[v]) { if (to != par)dfs(to, g, v); }
}
int main() {
	schnell;
	cin >> n;
	forn(i, n)cin >> A[i];
	forn(i, n - 1) {
		ll x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	map<ll, ll> h;
	dfs(1,h,-1);
	cout << res << endl;
	return 0;
}