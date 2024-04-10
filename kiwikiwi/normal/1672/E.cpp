#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int query(int x) {
	if (x == 0) return 1e9;
	printf("? %d\n", x);
	fflush(stdout);
	int y;
	scanf("%d", &y);
	if (y == 0) return 1e9;
	else return y;
}

int main() {
	int n;
	scanf("%d", &n);
	int l = 0, r = 4100000;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (query(m) > 1) l = m; else r = m;
	}
	int ans = r;
	for (int i = 2; i <= n; i++) {
		int w = (ans - 1) / i;
		int h = query(w);
		if (w != 0 && (i64)h * w < ans) ans = min(ans, h * w);
	}
	printf("! %d\n", ans);
	fflush(stdout);
}