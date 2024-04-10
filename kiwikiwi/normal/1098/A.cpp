#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 123456;
int p[maxN], s[maxN], n;
i64 ans;

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		if (s[i] == -1) s[i] = 1 << 30;
	}
	for (int i = 1; i <= n; i++) {
		s[p[i]] = min(s[p[i]], s[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (s[p[i]] > s[i]) {
			puts("-1");
			return 0;
		}
		if (s[i] == 1 << 30) s[i] = s[p[i]];
		ans += s[i] - s[p[i]];
	}
	printf("%lld\n", ans);
}