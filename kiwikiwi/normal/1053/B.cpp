#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 301000;
i64 x, ans;
int n, p[maxN], sp[maxN], cnt[maxN][2];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		p[i] = __builtin_popcountll(x);
		sp[i] = sp[i - 1] ^ (p[i] & 1);
	}

	for (int i = n; i >= 1; i--) {
		cnt[i][0] += cnt[i + 1][0] + (sp[i] == 0);
		cnt[i][1] += cnt[i + 1][1] + (sp[i] == 1);
	}
	for (int i = 1; i <= n; i++) {
		int r = min(i + 130, n);
		int s = 0, mx = 0;
		for (int j = i; j <= r; j++) {
			s += p[j];
			mx = max(mx, p[j]);
			if (s >= 2 * mx && s % 2 == 0) {
				ans ++;
			}
		}
		ans += cnt[r + 1][sp[i - 1]];
	}
	printf("%lld\n", ans);
}