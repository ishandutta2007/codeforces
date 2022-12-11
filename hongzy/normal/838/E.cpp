#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef double db;
const int N = 2505;
int x[N], y[N], n;
db f[N][N][2];
db dis(int i, int j) {
	return sqrt((x[i] - x[j]) * (db)(x[i] - x[j])
	+ (y[i] - y[j]) * (db)(y[i] - y[j]));
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d%d", x + i, y + i);
	db ans = 0;
	for(int i = 1; i < n; i ++) {
		for(int l = 0; l < n; l ++) {
			int r = l + i >= n ? l + i - n : l + i;
			int ll = l == n - 1 ? 0 : l + 1;
			int rr = r == 0 ? n - 1 : r - 1;
			f[l][r][0] = max(f[ll][r][0] + dis(l, ll), f[ll][r][1] + dis(l, r));
			f[l][r][1] = max(f[l][rr][0] + dis(l, r), f[l][rr][1] + dis(r, rr));
			if(i == n - 1) ans = max(ans, max(f[l][r][0], f[l][r][1]));
		}
	}
	printf("%.9f\n", ans);
	return 0;
}