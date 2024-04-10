// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
short d[2005][2005];

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	cin >> n >> m;
	memset(d, 255, sizeof d);

	vector<pair<short, short>> q;
	q.reserve(n*m + 10);

	int k;
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		q.emplace_back(x, y);
		d[x][y] = 0;
	}

	size_t qs = 0;
	while (qs < q.size()) {
		auto [x, y] = q[qs++];

		int g = d[x][y];

		auto mv = [&](int u, int v) {
			if (u < 1 || v < 1 || u > n || v > m) return;
			if (d[u][v] != -1) return;
			d[u][v] = g + 1;
			q.emplace_back(u, v);
		};

		mv(x-1, y);
		mv(x+1, y);
		mv(x, y+1);
		mv(x, y-1);
	}

	int x=1, y=1;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (d[i][j] > d[x][y]) x = i, y = j;
		}
	}

	cout << x << ' ' << y << '\n';

}