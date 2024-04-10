#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int u[200005], v[200005];
basic_string<int> e[200005];
int vis[200005];

void no() {
	cout << "NO\n";
	exit(0);
}

void dfs(int x, int c) {
	if (vis[x]) {
		if (c != vis[x]) {
			no();
		}
		return;
	}

	vis[x] = c;

	for (int i : e[x]) {
		int y = u[i] ^ v[i] ^ x;
		dfs(y, 3-c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i])
			dfs(i, 1);
	}

	cout << "YES\n";
	for (int i=0; i<m; i++)
		cout << vis[u[i]] - 1;
}