#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 998244353ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <int> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, f, t, k;
vi c, aa, p, dp;
vvi g;
map<int, bool> ansv;
pi dfs(int v = k, int h = 0) {
	int ans, cnt;
	ans = cnt = 0;
	dp[v] = h;
	for(auto& i : g[v]) {
		cnt++;
		ans += c[i];
		auto t = dfs(i, h+1);
		if(t.first == t.second && c[i] == 1)
			cnt += t.first, ans += t.second, aa.pb(i);
	}
	return {cnt, ans};
}

int main() {
	doin();
	cin >> n;
	g.resize(n + 1);
	c.resize(n + 1);
	p.resize(n + 1);
	dp.resize(n + 1,0);
	for(int i = 1; i <= n; i++) {
		cin >> f >> t;
		if(f != -1)
			g[f].pb(i);
		else
			k = i;
		c[i] = t;
		p[i] = f;
	}

	dfs();

	sort(all(aa));
	if(aa.size() == 0)
		cout << "-1";
	for(auto& i : aa) cout << i << " ";
}