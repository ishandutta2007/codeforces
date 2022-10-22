#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;
char a[maxn], str[maxn];
int n, m, cnt[maxn], sum[maxn];

void solve() {
	scanf("%d %d", &n, &m);
	int vx = 0, vy = 0;
	for (int i = 1; i <= m; i++) {
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", str + 1);
		int s = 0;
		for (int j = 1; j <= m; j++) {
			a[(i - 1) * m + j] = str[j];
			s += str[j] == '*';
			cnt[j] += str[j] == '*';
		}
		sum[i] = s;
		vx = max(vx, s);
	}
	for (int i = 1; i <= m; i++) {
		vy = max(vy, cnt[i]);
	}
	int ans = 1 << 30;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (sum[i] == vx && cnt[j] == vy) {
				ans = min(ans, n + m - vx - vy - (a[(i - 1) * m + j] == '.'));
			}
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