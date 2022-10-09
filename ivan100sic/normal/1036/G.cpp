#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int s[22], t[22];
int a[22];
vector<int> e[1000005];
int indeg[1000005];

bool v[1000005];

void dfs(int x) {
	v[x] = 1;
	for (int y : e[x])
		if (!v[y])
			dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		indeg[v]++;
	}

	{
		int x = 0, y = 0;
		for (int i=1; i<=n; i++) {
			if (e[i].size() == 0)
				t[y++] = i;
			if (indeg[i] == 0)
				s[x++] = i;
		}
		k = x;
	}

	for (int i=0; i<k; i++) {
		fill(v, v+n+1, false);
		dfs(s[i]);
		for (int j=0; j<k; j++)
			if (v[t[j]])
				a[i] |= 1 << j;
	}

	int ok = 0;

	for (int mask=1; mask<(1<<k)-1; mask++) {
		int cc = 0;
		for (int j=0; j<k; j++)
			if (mask & (1 << j))
				cc |= a[j];
		if (__builtin_popcount(cc) <= __builtin_popcount(mask))
			ok = 1;
	}

	cout << (!ok ? "YES\n" : "NO\n");
}