#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

char c[N];
int T, n, ans;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", c + 1); n = strlen(c + 1);
		ans = 0;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				int now = 0;
				for (int k = 1; k <= n; k++) {
					int x = (now & 1 ? j : i);
					if (c[k] - '0' == x) ++now;
				}
				if (i != j) ans = max(ans, now - (now & 1));
				else ans = max(ans, now);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}