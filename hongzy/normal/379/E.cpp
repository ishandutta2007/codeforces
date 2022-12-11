#include <algorithm>
#include <cstdio>
using namespace std;

typedef long double db;

const int N = 1e7 + 10;

int n, k, m, y[310];
db h[310][1235];

int main() {
	scanf("%d%d", &n, &k);
	m = 1234; db la = 0, res;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= k; j ++) scanf("%d", y + j);
		res = 0;
		for(int j = 0; j < k; j ++) {
			db ly = y[j], d = (db) (y[j] - y[j + 1]) / m;
			for(int u = 1; u <= m; u ++) {
				db h0 = (ly + ly - d) / 2;
				h[j][u] = max(h[j][u], h0);
				res += h[j][u] / m;
				ly -= d;
			}
		}
		printf("%.7f\n", (double) (res - la));
		la = res;
	}
	return 0;
}