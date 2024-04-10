#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n, s, a[N], cnt[N], sum[N];

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = 0;
	if (a[s] != 0) {
		ans++;
		a[s] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i == s) continue;
		cnt[a[i]]++;
	}
	int yu = cnt[0];
	ans += cnt[0];
	cnt[0] = 1;
	int out = INF;
	for (int i = n - 1; i >= 1; i--) sum[i] = sum[i + 1] + cnt[i];
	int zn = 0;
	for (int i = 1; i <= n; i++) {
		int sb = yu + sum[i];
		out = min(out, max(0, zn - sb) + sum[i] + ans);
		if (cnt[i] == 0) zn++;
	}
	printf("%d\n", out);
	return 0;
}