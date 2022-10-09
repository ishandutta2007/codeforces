#include <bits/stdc++.h>
using namespace std;

int n, m, fx, fy;
string a[105];

pair<int, int> idi(char x) {
	cout << x << '\n' << flush;
	int a, b;
	cin >> a >> b;
	if (a == fx && b == fy) {
		exit(0);
	}
	return {a, b};
}

int dist[105][105];
char dir[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] = string(" ") + a[i] + string(" ");
		for (int j=1; j<=m; j++) {
			if (a[i][j] == 'F') {
				fx = i;
				fy = j;
			}
		}
	}

	// figure out the buttons
	if (n == 1) {
		for (int j=1; j<m; j++) {
			idi('L');
		}
		for (int j=1; j<m; j++) {
			idi('R');
		}
		return 0;
	}

	if (n == 1) {
		for (int j=1; j<m; j++) {
			idi('U');
		}
		for (int j=1; j<m; j++) {
			idi('D');
		}
		return 0;
	}

	bool flip_lr, flip_ud;

	if (a[2][1] != '*' && a[1][2] != '*') {
		// ispitaj sad oba
		auto p = idi('D');
		if (p == make_pair(1, 1)) {
			flip_ud = true;
		} else {
			flip_ud = false;
			idi('U');
		}

		p = idi('R');
		if (p == make_pair(1, 1)) {
			flip_lr = true;
		} else {
			flip_lr = false;
			idi('L');
		}
	} else if (a[1][2] != '*') {
		// izvali levo/desno
		auto p = idi('R');
		if (p == make_pair(1, 1)) {
			flip_lr = true;
		} else {
			flip_lr = false;
			idi('L');
		}

		int j = 2;
		while (a[2][j] == '*' && j < m) {
			j++;
		}

		for (int rep=1; rep<j; rep++) {
			idi(flip_lr ? 'L' : 'R');
		}

		// sad izvali UD pa se vrati
		cerr << __LINE__ << '\n';

		p = idi('D');
		if (p == make_pair(1, j)) {
			flip_ud = true;
		} else {
			flip_ud = false;
			idi('U');
		}

		// vrati se

		for (int rep=1; rep<j; rep++) {
			idi(flip_lr ? 'R' : 'L');
		}
	} else {
		// izvali gore/dole
		auto p = idi('D');
		if (p == make_pair(1, 1)) {
			flip_ud = true;
		} else {
			flip_ud = false;
			idi('U');
		}

		int j = 2;
		while (a[j][2] == '*' && j < n) {
			j++;
		}

		for (int rep=1; rep<j; rep++) {
			idi(flip_ud ? 'U' : 'D');
		}

		// sad izvali LR pa se vrati

		p = idi('R');
		if (p == make_pair(j, 1)) {
			flip_lr = true;
		} else {
			flip_lr = false;
			idi('L');
		}

		// vrati se

		for (int rep=1; rep<j; rep++) {
			idi(flip_ud ? 'D' : 'U');
		}
	}

	cerr << "flip_lr " << flip_lr << '\n';
	cerr << "flip_ud " << flip_ud << '\n';

	// sad nadji put i odstampaj ga

	{
		queue<pair<int, int>> q;
		memset(dist, 255, sizeof(dist));

		q.push({fx, fy});
		dist[fx][fy] = 0;

		while (!q.empty()) {
			auto p = q.front(); q.pop();
			int x = p.first;
			int y = p.second;

			auto probaj = [&](int a, int b, char dr) {
				if (a < 1 || a > n || b < 1 || b > m) {
					return;
				}
				if (dist[a][b] != -1) {
					return;
				}
				if (::a[a][b] == '*') {
					return;
				}
				dist[a][b] = dist[x][y] + 1;
				q.push({a, b});
				dir[a][b] = dr;
			};

			probaj(x+1, y, 'U');
			probaj(x-1, y, 'D');
			probaj(x, y+1, 'L');
			probaj(x, y-1, 'R');
		}
	}

	{
		int x = 1, y = 1;
		while (dist[x][y] > 0) {
			char c = dir[x][y];

			switch (c) {
				case 'U': x--; break;
				case 'D': x++; break;
				case 'L': y--; break;
				case 'R': y++; break;
			}

			if ((c == 'U' || c == 'D') && flip_ud) {
				c ^= 'U' ^ 'D';
			}

			if ((c == 'L' || c == 'R') && flip_lr) {
				c ^= 'L' ^ 'R';
			}

			idi(c);
		}
	}



}