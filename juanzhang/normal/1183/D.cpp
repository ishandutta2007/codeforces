#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, top, a[maxn], c[maxn], d[maxn], st[maxn];

void solve() {
	top = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		c[i] = d[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i), c[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		d[c[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		st[++top] = i;
		if (!d[i]) continue;
		while (d[i]-- && top) {
			ans += st[top--];
		}
	}
	printf("%d\n", ans);
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) solve();
  return 0;
}