#include <bits/stdc++.h>
using namespace std;

int t, n, x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &x, &y);
		if (x && y || !x && !y) printf("-1\n");
		else {
			if (!x) x = y;
			bool ok = 0;
			if (!((n - 1) % x)) {
				for (int i = 1, j = 0; i < n; ++i) {
					if (!((i - 1) % x)) j = i;
					printf("%d ", j + 1);
				}
			} else printf("-1");
			printf("\n");
		}
	}
	return 0;
}