#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < 9; i++) {
		int c0 = 0, c1 = 0;
		for (int j = 0; j < n; j++) {
			if (j & (1 << i)) c0++;
			else c1++;
		}
		if (c0 == 0 || c1 == 0) continue;
		printf("%d %d", c0, c1);
		for (int j = 0; j < n; j++) {
			if (j & (1 << i))
				printf(" %d", j + 1);
		}
		for (int j = 0; j < n; j++) {
			if (j & (1 << i)) {

			} else
				printf(" %d", j + 1);
		}
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		ans = max(ans, x);
	}
	printf("-1 %d\n", ans);
	fflush(stdout);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
		solve();
}