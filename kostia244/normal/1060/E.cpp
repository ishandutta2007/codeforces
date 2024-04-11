#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119 * (1 << 23) + 1);
ll n, ans = 0, c[2];
vector<vi> g;
vi sz;
void dfs(ll v, ll par, ll h = 0) {
	c[h]++;
	sz[v] = 1;
	for (auto i : g[v]) {
		if (i == par)
			continue;
		dfs(i, v, h ^ 1);
		sz[v] += sz[i];
	}
	for (auto i : g[v]) {
		if (i == par)
			continue;
		ans += sz[i]*1ll*(n-sz[i]);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n + 1);
	sz.resize(n + 1);
	for (ll f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs(1, 1);
	ans -= c[0]*c[1];
	assert(ans%2==0);
	ans/=2;
	ans += c[0]*c[1];
	cout << ans;
}