#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[100005];
int dp[100005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	ll sol = 0;
	for (int i=1; i<=n; i++) {
		for (int j : e[i]) {
			if (j < i)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		sol = max(sol, (dp[i] + 1) * (ll)e[i].size());
	}
	cout << sol << '\n';
}