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
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, f, t, ans, P;
vi cnt;
vvi g;

void dfs(int v, int h = 0, int p2 = -1) {
	if (h == 2) {
		cnt[v]++;
		return;
	}
	for (auto& i : g[v])
		if (i != P && i != p2)
			dfs(i, h + 1, v);
}

ll nck(int n, int k) {
	if (k == 0)
		return 1;
	return (n * nck(n - 1, k - 1)) / k;
}

int main() {
	doin();
	cin >> n >> m;
	g.resize(n + 1);
	while (m--)
		cin >> f >> t, g[f].pb(t);
	for (int i = 1; i <= n; i++) {
		P = i;
		cnt.assign(n + 1, 0), dfs(i);
		for (int j = 1; j <= n; j++) {
			if (cnt[j])
				ans += nck(cnt[j], 2);
		}
	}
	cout << fixed << ans;
	return 0;
}