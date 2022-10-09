#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[100005];
int n, m;
basic_string<int> s[3];
int v[100005];

void dfs(int x, int y) {
	if (v[x]) {
		if (v[x] != y) {
			cout << "-1\n";
			exit(0);
		} else {
			return;
		}
	}

	v[x] = y;
	s[y] += x;

	for (int z : e[x]) {
		dfs(z, 3-y);
	}
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
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			dfs(i, 1);
		}
	}

	cout << s[1].size() << '\n';
	for (int x : s[1])
		cout << x << ' ';
	cout << '\n';

	cout << s[2].size() << '\n';
	for (int x : s[2])
		cout << x << ' ';
	cout << '\n';
}