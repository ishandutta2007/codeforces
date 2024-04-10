#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN (1 << 18) + 10

int n;
i64 a[maxN], b[maxN];

i64 solve(i64 t) {
	for (int i = 0; i < n; i++) b[i] = a[i] + t;
	if (b[0] >= 0) {
		i64 val = 0;
		for (int i = 1; i < n; i++) val += b[0] * b[i];
		return val - (n - 1) * t * t;
	}
	if (b[n - 1] <= 0) {
		i64 val = 0;
		for (int i = 0; i < n - 1; i++) val += b[n - 1] * b[i];
		return val - (n - 1) * t * t;		
	}
	i64 val = 0;
	for (int i = 1; i < n - 1; i++)	{
		if (b[i] > 0) val += b[0] * b[i];
		else val += b[i] * b[n - 1];
	}
	val += b[0] * b[n - 1];
	return val - (n - 1) * t * t;
}
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	i64 s1 = 0, s2 = 0;
	for (int i = 1; i < n; i++) s1 += a[0] + a[i];
	for (int i = 0; i < n - 1; i++) s2 += a[n - 1] + a[i];
	if (s1 > 0) {
		puts("INF");
		return;
	}
	if (s2 < 0) {
		puts("INF");
		return;
	}
	i64 tl = -1000000, tr = 1000000;
	while (tl + 3 < tr) {
		i64 fl = (tl + tr) /2, fr = (tl + tr) / 2 + 1;
		if (solve(fl) > solve(fr)) tr = fr;
		else tl = fl;
	}
	i64 ans = -(1ll << 60);
	for (i64 v = tl; v <= tr; v++) ans = max(ans, solve(v));
	printf("%lld\n", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		solve();
	}
}