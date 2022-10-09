#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[105];
int v[105];

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
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	dfs(1);
	if (count(v+1, v+n+1, 1) == n && n == m)
		cout << "FHTAGN!\n";
	else
		cout << "NO\n";
}