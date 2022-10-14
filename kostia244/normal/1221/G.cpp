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
using vvi = vector<vector<ll>>;
const ll mod = (119 * (1 << 23) + 1);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll n, m, comp = 0, isolated = 0, bip = 1, b[50];
vvi g;
vi vis;

void dfs(int v) {
	for (auto i : g[v]) {
		if (!vis[i]) {
			vis[i] = 3 ^ vis[v];
			dfs(i);
		} else if (vis[i] == vis[v])
			bip = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
		f--, --t;
		b[f] |= 1ll << t;
		b[t] |= 1ll << f;
	}
	vis.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		if (g[i].size() == 0)
			isolated++;
		vis[i] = 1, dfs(i), comp++;
	}
	//f012 - f01 - f12 - f02 + f0 + f1 + f2 - f{}
//	cout << comp << " " << isolated << " " << bip << "\n";
	ll ans = (1ll << n); //f012
//	cout << ans << "f012\n";
	ans += (1ll << isolated), ans += (1ll << isolated); //f0, f2
//	cout << ans << "f0,2\n";
	if (bip)
		ans += 1ll << comp; //f1
//	cout << ans << "fbip\n";
	if (m == 0)
		ans -= 1ll << n; //f{}
//	cout << ans << "fempt\n";
	ans -= 1ll << comp; //f02
//	cout << ans << "f02\n";
	ll f01 = 0; //f01==f12
	ll s1 = n / 2;
	ll s2 = n - s1;
	ll good[1 << 20];
	for (ll msk = 0; msk < 1 << s1; msk++) {
		ll ban = 0;
		for (int i = 0; i < s1; i++)
			ban |= ((msk >> i) & 1) * b[i];
		good[msk] = ((msk & ban) == 0);
	}
	for (int i = 0; i < s1; i++)
		for (ll msk = 0; msk < 1 << s1; msk++)
			if ((msk >> i) & 1)
				good[msk] += good[msk ^ (1ll << i)];
	ll full = (1ll << s1) - 1;
	for (ll msk = 0; msk < 1 << s2; msk++) {
		ll ban = 0;
		for (int i = 0; i < s2; i++)
			ban |= ((msk >> i) & 1) * b[s1 + i];
		if ((msk & (ban >> s1)) == 0)
			f01 += good[full ^ (full & ban)];
	}
	ans -= f01 << 1; //f01, f12
	cout << ans;
}