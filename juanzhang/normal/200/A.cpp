#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, m, k, p, q, a[maxn][maxn], d[maxn][maxn];

inline void chkmax(int& x, const int& y) {
	if (x < y) x = y;
}

inline bool pd(int x, int y, int r) {
	for (int i = max(1, x - r); i <= min(n, x + r); i++) {
		int t = r - abs(x - i);
		if (y - t > 0 && !a[i][y - t]) return p = i, q = y - t, 1;
		if (y + t <= m && !a[i][y + t]) return p = i, q = y + t, 1;
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (x + i < 1 || x + i > n || y + j < 1 || y + j > m) continue;
				chkmax(d[x][y], d[x + i][y + j] - abs(i) - abs(j));
			}
		}
		while (!pd(x, y, d[x][y])) d[x][y]++;
		printf("%d %d\n", p, q), a[p][q] = 1;
	}
	return 0;
}