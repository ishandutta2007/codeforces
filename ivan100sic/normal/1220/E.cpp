#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, s0;
set<int> e[200005];
basic_string<int> q;
int w[200005];
ll dp[200005];
bool brisan[200005];

ll dfs(int x, int p) {
	ll z = 0;
	for (int y : e[x]) {
		if (y == p)
			continue;
		z = max(z, dfs(y, x));
	}
	return z + w[x];
}

int att[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> w[i];
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].insert(y);
		e[y].insert(x);
	}

	int s0;
	cin >> s0;

	if (n-1 == m) {
		cout << dfs(s0, s0) << '\n';
		return 0;
	}

	for (int i=1; i<=n; i++)
		if (e[i].size() == 1)
			q += i;

	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		int p = *e[x].begin();
		dp[p] = max(dp[p], dp[x] + w[x]);
		e[x].erase(p);
		e[p].erase(x);
		if (e[p].size() == 1)
			q += p;
		brisan[x] = true;
		att[x] = p;
	}

	for (int i=s0; brisan[i]; i=att[i])
		brisan[i] = false;

	ll z = 0, y = 0;
	for (int i=1; i<=n; i++)
		if (!brisan[i])
			z += w[i];
		else
			y = max(y, dp[i] + w[i]);
	cout << y+z << '\n';
}