// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
basic_string<int> e[500005], dub[500005];
bool vis[500005];
int par[500005];

void dfs(int x, int d) {
	dub[d] += x;
	vis[x] = true;
	for (int y : e[x]) {
		if (!vis[y]) {
			par[y] = x;
			dfs(y, d+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<=n; i++) {
			e[i] = dub[i] = {};
			par[i] = vis[i] = 0;
		}

		for (int i=0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
			e[v] += u;
		}

		dfs(1, 0);

		int td = (n+1)/2 - 1;
		if (dub[td].size()) {
			cout << "PATH\n";
			cout << td + 1 << '\n';
			for (int y=dub[td][0]; y; y=par[y]) {
				cout << y << ' ';
			}
			cout << '\n';
		} else {
			cout << "PAIRING\n";
			td++;
			td = (td+1)/2;
			cout << td << '\n';
			for (int i=0; i<=n; i++) {
				for (int j=0; td && j+1<(int)dub[i].size(); j+=2) {
					cout << dub[i][j] << ' ' << dub[i][j+1] << '\n';
					td--;
				}
			}
		}
	}
}