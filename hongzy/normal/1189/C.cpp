#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], f[N][20], lg[1 << 20];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i), (a[i] += a[i - 1]) %= 10;
	for(int i = 0; i < 20; i ++) lg[1 << i] = i;
	for(int i = 1; i <= n; i ++) f[i][0] = 0;
	for(int i = 1; i < 20; i ++) {
		for(int j = 1; j + (1 << i) - 1 <= n; j ++) {
			int k = j + (1 << (i - 1)), r = j + (1 << i) - 1;
			int ls = (a[k - 1] - a[j - 1] + 10) % 10;
			int rs = (a[r] - a[k - 1] + 10) % 10;
			f[j][i] = f[j][i - 1] + f[k][i - 1] + (ls + rs >= 10);
		}
	}
	int q; scanf("%d", &q);
	while(q --) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", f[l][lg[r - l + 1]]);
	}
	return 0;
}