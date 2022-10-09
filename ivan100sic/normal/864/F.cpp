#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> e[3005];

bool has_path[3005][3005];

void dfs(int origin, int x) {
	has_path[origin][x] = true;
	for (int y : e[x]) {
		if (!has_path[origin][y]) {
			dfs(origin, y);
		}
	}
}

void find_hp() {
	for (int i=1; i<=n; i++) {
		dfs(i, i);
	}
}

short int step[3005][3005][13];

void find_step_func() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (!has_path[i][j]) {
				continue;
			}

			if (i == j) {
				step[i][j][0] = i;
				continue;
			}

			for (int k : e[i]) {
				if (has_path[k][j]) {
					if (step[i][j][0] == 0 || k < step[i][j][0]) {
						step[i][j][0] = k;
					}
				}
			}
		}
	}

	for (int h=1; h<13; h++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (has_path[i][j]) {
					int x = step[i][j][h-1];
					step[i][j][h] = step[x][j][h-1];
				}
			}
		}
	}
}

int find_kth(int u, int v, int k) {
	for (int i=12; i>=0; i--) {
		if (k & (1<<i)) {
			u = step[u][v][i];
		}
	}
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}

	find_hp();
	find_step_func();

	// cerr << "debug: " << find_kth(1, 4, 4) << '\n';

	cerr << "debug: " << step[1][4][12] << '\n';
	cerr << "debug: " << has_path[1][4] << '\n';

	while (q--) {
		int u, v, k;
		cin >> u >> v >> k;

		if (!has_path[u][v]) {
			cout << "-1\n";
			continue;
		}

		if (step[u][v][12] != v) {
			cout << "-1\n";
			continue;
		}
		
		if (k == 1) {
			cout << u << '\n';
			continue;
		}

		int x = find_kth(u, v, k-2);

		// ako je prethodni stepen jednak cilju, znaci da si ranije
		// doso pa ne valja
		if (x == v) {
			cout << "-1\n";
			continue;
		}

		cout << find_kth(u, v, k-1) << '\n';
	}
}