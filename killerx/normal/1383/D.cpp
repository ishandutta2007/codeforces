#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, m;
int a[255][255];
int mxr[255];
int mxc[255];
int id[255 * 255];
int b[255][255];

bool comp(int x, int y) { return a[x / m][x % m] > a[y / m][y % m]; }

int main() {
	scanf("%d %d", &n, &m);
	rep(i, n) rep(j, m) scanf("%d", &a[i][j]), -- a[i][j];
	rep(i, n) rep(j, m) id[i * m + j] = i * m + j;
	rep(i, n) rep(j, m) mxr[i] = std::max(mxr[i], a[i][j]);
	rep(i, n) rep(j, m) mxc[j] = std::max(mxc[j], a[i][j]);
	std::sort(id, id + n * m, comp);
	int r = -1, c = -1;
	std::vector <int> unused;
	std::vector <std::pair <int, int> > vec;
	rep(i, n * m) {
		int x = id[i] / m, y = id[i] % m;
		bool fr = 0, fc = 0;
		if (mxr[x] == a[x][y]) ++ r, fr = 1;
		if (mxc[y] == a[x][y]) ++ c, fc = 1;
		if (!fr && !fc) {
			unused.push_back(i);
			continue;
		}
		if (fr) for (int s = c - 1; ~s; -- s) vec.push_back({r, s});
		if (fc) for (int s = r - 1; ~s; -- s) vec.push_back({s, c});
		b[r][c] = a[x][y];
	}
	rep(i, vec.size()) {
		int x = id[unused[i]] / m;
		int y = id[unused[i]] % m;
		b[vec[i].first][vec[i].second] = a[x][y];
	}
	rep(i, n) rep(j, m) printf("%d%c", b[i][j] + 1, " \n"[j + 1 == m]);
	return 0;
}