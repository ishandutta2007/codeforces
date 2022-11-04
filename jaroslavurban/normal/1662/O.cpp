#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int N = 50, M = 2 * 360;

void ProGamerMove() {
	array<array<bool, M>, N> wall{}, vis{};
	int n; cin >> n;
	while (n--) {
		char c; cin >> c;
		if (c == 'C') {
			int r, a, b; cin >> r >> a >> b;
			for (int i = 2 * a; i != 2 * b; i = (i + 1) % M) wall[2 * r][i] = true;
			wall[2 * r][2 * b] = true;
		} else if (c == 'S') {
			int r1, r2, a; cin >> r1 >> r2 >> a;
			for (int i = 2 * r1; i <= 2 * r2; ++i) wall[i][2 * a] = true;
		} else assert(0);
	}
	function<void(int, int)> dfs = [&] (int i, int j) {
		vis[i][j] = true;
		for (int di = -1; di <= +1; ++di)
			for (int dj = -1; dj <= +1; ++dj)
				if (abs(di) + abs(dj) == 1) {
					int ni = i + di;
					int nj = (j + dj + M) % M;
					if (ni >= 0 && ni < N && nj >= 0 && nj < M && !vis[ni][nj] && !wall[ni][nj]) dfs(ni, nj);
				}
	};
	dfs(N - 1, 0);
//	for (int i = 0; i < N; ++i, cerr << '\n')
//		for (int j = 0; j < M; ++j)
//			cerr << vis[i][j] << ' ';
	cout << (vis[0][0] ? "YES\n" : "NO\n");
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}