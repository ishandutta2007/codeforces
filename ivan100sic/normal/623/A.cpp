#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int e[505][505];
int v[505], l[505], sz;
string s;

void dfs(int x, int c) {
	if (v[x])
		return;
	v[x] = c;
	sz++;
	for (int i=1; i<=n; i++) {
		if (!v[i] && !e[x][i]) {
			dfs(i, 3-c);
		}
	}
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
		e[u][v] = e[v][u] = 1;
	}

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			sz = 0;
			dfs(i, 1);
			l[i] = sz == 1;
		}
	}

	s = string(n+1, ' ');

	for (int i=1; i<=n; i++) {
		if (l[i]) {
			s[i] = 'b';
		} else if (v[i] == 1) {
			s[i] = 'a';
		} else {
			s[i] = 'c';
		}
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i != j) {
				int boja = abs(s[i] - s[j]) <= 1;
				if (boja != e[i][j]) {
					return cout << "No\n", 0;
				}
			}

	cout << "Yes\n" << s.substr(1) << '\n';
}