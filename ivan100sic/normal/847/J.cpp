#include <bits/stdc++.h>
using namespace std;

// Credits: 
// http://catalog.lib.kyushu-u.ac.jp/handle/2324/14869/IJFCS-revision.pdf

int n, m;
vector<int> e[5005];
bool dir[5005][5005];
int c[5005];

int q[5005], qs, qe;

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
		e[v].push_back(u);
		dir[u][v] = true;
		c[u]++;
	}

	for (int iter=1; iter<=2*m; iter++) {
		int x = 1;
		for (int i=2; i<=n; i++) {
			if (c[i] > c[x]) {
				x = i;
			}
		}

		int starter = c[x];

		vector<bool> visited(n+1, false);
		vector<int> prev(n+1, -1);

		qs = 0;
		qe = 0;
		q[qe++] = x;

		visited[x] = true;
		int final = -1;

		while (qs != qe) {
			int y = q[qs++];

			for (int z : e[y]) if (dir[y][z]) {
				if (c[z] <= starter - 2 && !visited[z]) {
					final = z;
					prev[z] = y;
					qs = qe;
					break;
				}
				if (c[z] <= starter && !visited[z]) {
					visited[z] = true;
					prev[z] = y;
					q[qe++] = z;
				}
			}
		}

		if (final == -1) {
			break;
		}

		for (int x = final; prev[x] != -1; x = prev[x]) {
			int w = prev[x];
			// swap
			if (dir[x][w]) {
				dir[x][w] = false;
				dir[w][x] = true;
				c[x]--;
				c[w]++;
			} else {
				dir[x][w] = true;
				dir[w][x] = false;
				c[x]++;
				c[w]--;
			}
		}
	}

	int val = *max_element(c+1, c+n+1);
	cout << val << '\n';
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (dir[i][j]) {
				cout << i << ' ' << j << '\n';
			}
		}
	}
}