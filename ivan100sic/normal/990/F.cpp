#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int s[200005];
int u[200005], v[200005], f[200005];
bool vis[200005];
basic_string<int> e[200005];

int D(int x, int i) {
	i = abs(i);
	return u[i] ^ v[i] ^ x;
}

void add_flow(int i, int w) {
	if (i < 0) {
		i = -i;
		w = -w;
	}
	f[i] += w;
	s[u[i]] += w;
	s[v[i]] -= w;
}

void dfs(int x) {
	vis[x] = true;
	for (int i : e[x]) {
		int y = D(x, i);
		if (vis[y])
			continue;
		dfs(y);
		add_flow(i, s[y]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> s[i];
	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += i;
		e[v[i]] += -i;
	}

	dfs(1);

	for (int i=1; i<=n; i++)
		if (s[i] != 0) {
			cout << "Impossible\n";
			return 0;
		}

	cout << "Possible\n";
	for (int i=1; i<=m; i++)
		cout << f[i] << '\n';
}