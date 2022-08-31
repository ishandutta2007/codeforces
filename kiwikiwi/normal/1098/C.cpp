#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 123456;

i64 d[maxN], s, n;
int par[maxN];

i64 check(int s) {

	for (int i = 1; i <= n; i++)
		d[i] = 0;

	i64 lev = n;
	int dep = 2;
	d[1] = 1;
	lev--;

	while (lev) {
		d[dep] = min(lev, d[dep - 1] * s);
		lev -= d[dep];
		dep++;
	}
	i64 ans = 0;
	for (int i = 1; i <= dep; i++) ans += (i64)i * d[i];
	return ans;
}

void construct(int r) {
	i64 t = check(r);
	int maxd = 0;
	for (int i = n; i >= 1; i--) if (d[i] > 0) {
			maxd = i;
			break;
		}
	int dep = maxd;
	while (t < s) {
		while (dep > 0 && d[dep] == 1) --dep;
		--d[dep];
		if (t + maxd + 1 - dep <= s) {
			maxd++;
			d[maxd] += 1;
			t += maxd - dep;
		} else {
			d[s + dep - t] += 1;
			t = s;
			break;
		}
	}
	int s = 1;
	for (int i = 2; i <= n; i++) {
		int c = s + d[i - 1];
		for (int j = 0; j < d[i]; j++) {
			par[c + j] = s + j / r;
		}
		s = c;
	}
}

int main() {
	scanf("%lld%lld", &n, &s);
	if (s > n * (n + 1) / 2) {
		puts("No");
		return 0;
	}
	if (s < 2 * n - 1) {
		puts("No");
		return 0;
	}
	int l = 0, r = n;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid) <= s) r = mid;
		else l = mid;
	}
	construct(r);
	puts("Yes");
	for (int i = 2; i <= n; i++)
		printf("%d ", par[i]);
	puts("");
}