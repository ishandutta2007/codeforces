#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[100005];
int gr, cv, z;
int vis[100005];

void dfs(int x) {
	gr += e[x].size();
	cv += 1;
	vis[x] = 1;
	for (int y : e[x])
		if (!vis[y])
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

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			gr = 0;
			cv = 0;
			dfs(i);
			if (gr == 2*cv-2)
				z++;
		}
	}

	cout << z << '\n';
}