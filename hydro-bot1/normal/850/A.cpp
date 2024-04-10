// Hydro submission #61891cac1edf93b3ad658933@1636375725451
#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, a[N][6], res[N], cnt = 0;

int main() {
	scanf("%d", &n);
	if (n > 32) return puts("0"), 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= 5; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		[&]() {
			for (int j = 1; j <= n; j ++) {
				for (int k = j + 1; k <= n; k ++) {
					int T = 0;
					for (int l = 1; l <= 5; l ++) {
						T += (a[i][l] - a[j][l]) * (a[i][l] - a[k][l]);
					}
					if (T > 0) return;
				}
			}
			res[++ cnt] = i;
		}();
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++) {
		printf("%d\n", res[i]);
	}
	return 0;
}