#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, L, len, ans;
struct pr { int l, r; } a[maxn];

int main() {
	scanf("%d %d %d", &n, &L, &len);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].l, &a[i].r);
		a[i].r += (++a[i].l) - 1;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].l != a[i - 1].r) ans += (a[i].l - a[i - 1].r - 1) / len;
	}
	ans += (L - a[n].r) / len;
	printf("%d", ans);
	return 0;
}