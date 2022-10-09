#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
bool inst[55][55], vis[55][55];
string a[55];

void dfs(int x, int y, int px, int py) {

	vis[x][y] = 1;
	inst[x][y] = 1;

	auto go = [&](int p, int q) {
		if (p < 0 || q < 0 || p >= n || q >= m)
			return;
		if (a[p][q] != a[x][y])
			return;
		if (inst[p][q] && make_pair(p, q) != make_pair(px, py)) {
			cout << "Yes\n";
			exit(0);
			return;
		}
		if (vis[p][q])
			return;
		dfs(p, q, x, y);
	};

	go(x+1, y);
	go(x-1, y);
	go(x, y+1);
	go(x, y-1);

	inst[x][y] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!vis[i][j])
				dfs(i, j, i, j);
		}
	}
	cout << "No\n";
}