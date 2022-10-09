#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[205];
int d[205];

int blok_x, blok_y;

bool blokirano(int x, int y) {
	if (x == blok_x && y == blok_y)
		return true;
	if (y == blok_x && x == blok_y)
		return true;
	return false;
}

void bfs(int x) {
	memset(d, 255, sizeof(d));
	d[x] = 0;
	queue<int> q;
	q.push(x);

	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (!blokirano(x, y) && d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u] += v;
		e[v] += u;
	}

	int sol = 0;

	for (int x=0; x<n; x++) {
		for (int y : e[x]) {
			blok_x = x;
			blok_y = y;

			bfs(x);
			int xg = max_element(d, d+n) - d;
			bfs(xg);
			int dx = *max_element(d, d+n);

			bfs(y);
			int yg = max_element(d, d+n) - d;
			bfs(yg);
			int dy = *max_element(d, d+n);

			sol = max(sol, dx*dy);
		}
	}

	cout << sol << '\n';
}