#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 123456;

int n;
i64 l[maxN], cost[maxN], red[maxN], cnt[10], ans;
char s[maxN];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", l + i);
		l[i] *= 2;
	}
	scanf("%s", s);
	bool c5 = 0, c3 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G') {
			cost[i] = 5;
			red[i] = 2;
			c5 = 1;
		} else if (s[i] == 'W') {
			cost[i] = 3;
			red[i] = 1;
			c3 = 1;
		} else {
			if (c3) cost[i] = 4, red[i] = 3;
			else cost[i] = 6, red[i] = 5;
		}
		ans += cost[i] * l[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		i64 eng = 0;
		if (s[i] == 'G' || s[i] == 'W') eng = l[i];
		cnt[red[i]] += l[i];
		for (int j = 5; j >= 1; j--) {
			int t = j <= 2 ? 2 : 1;
			i64 d = min(eng, cnt[j] * t);
			cnt[j] -= d / t;
			eng -= d;
			ans -= d * j;
		}
	}
	printf("%lld\n", ans / 2);
}