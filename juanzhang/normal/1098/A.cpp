#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, a[maxn], fa[maxn], val[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", fa + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] == -1) a[i] = 1 << 30;
	}
	for (int i = 2; i <= n; i++) {
		a[fa[i]] = min(a[fa[i]], a[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[fa[i]]) return puts("-1"), 0;
    if (a[i] < 1 << 30) ans += a[i] - a[fa[i]];
	}
	printf("%I64d", ans);
	return 0;
}