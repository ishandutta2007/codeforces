#include <cstdio>
#include <cstring>

const int N = 120;
int x, y, t;
long long d[N][N], ti;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%d%d", &ti, &x, &y);
		ti = ti - x - y;
		bool ok = 0;
		if (ti >= 0) {
			d[0][0] = ti;
			for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (i || j) {
				d[i][j] = 0;
				if (i) d[i][j] += d[i - 1][j] >> 1;
				if (j) d[i][j] += d[i][j - 1] + 1 >> 1;
			}
			int xx = 0, yy = 0;
			while (xx < N && yy < N) {
				if (x == xx && y == yy) ok = 1;
				if (d[xx][yy] & 1) ++xx;
				else ++yy;
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}