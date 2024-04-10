// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m, t;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool same(vector<string>& a, int i, int j) {
	for (int d=0; d<4; d++) {
		int x = i + dx[d];
		int y = j + dy[d];
		if (x < 0 || y < 0 || x >= n || y >= m) continue;
		if (a[i][j] == a[x][y]) return 1;
	}
	return 0;
}

vector<string> step(vector<string> a) {
	auto b = a;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int s = same(a, i, j);
			b[i][j] ^= s;
		}
	}
	return b;
}

void dbg(vector<string> a) {
	for (auto b : a) {
		for (char c : b) cerr << (c == '1' ? 'X' : '.');
		cerr << '\n';
	}
	cerr << '\n';
}

void toy(vector<string> a) {
	dbg(a);
	for (int i=0; i<10; i++) {
		a = step(a);
		dbg(a);
	}
}

void gen(vector<string>& a) {
	for (auto& s : a) {
		s.resize(m);
		for (int i=0; i<m; i++) {
			auto e = uniform_int_distribution<int>(0, 5)(eng);
			s[i] = 48 + !!e;
		}
	}
}

int dist[1005][1005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	memset(dist, 255, sizeof dist);

	cin >> n >> m >> t;
	vector<string> a(n);
	for (auto& s : a) cin >> s;

	// toy(a);

	vector<pair<int, int>> q(n*m + 5);
	int qs=0, qe=0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (same(a, i, j)) {
				q[qe++] = {i, j};
				dist[i][j] = 0;
			}
		}
	}

	bool none = qs == qe;

	while (qs != qe) {
		auto [x, y] = q[qs++];
		for (int d=0; d<4; d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (dist[xx][yy] != -1) continue;
			dist[xx][yy] = dist[x][y] + 1;
			q[qe++] = {xx, yy};
		}
	}

	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<m; j++) {
	// 		cerr << dist[i][j] << " \n"[j == m-1];
	// 	}
	// }

	for (int i=0; i<t; i++) {
		int x, y;
		ll t;
		cin >> x >> y >> t;
		x--, y--;

		if (none) {
			cout << a[x][y] << '\n';
		} else {
			if (t < dist[x][y]) {
				cout << a[x][y] << '\n';
			} else {
				cout << ((a[x][y]-48) ^ ((t-dist[x][y]) & 1)) << '\n';
			}
		}
	}
}