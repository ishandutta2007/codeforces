#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n, k, s, t;
int c[N], v[N];
int g[N], f[N];
ll sum[N];

int main() {
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 1; i <= n; i++) scanf("%d%d", &c[i], &v[i]);
	for (int i = 1; i <= k; i++) scanf("%d", &g[i]); g[++k] = s;
	sort(g + 1, g + 1 + k);
	for (int i = k; i >= 1; i--) 
		g[i] -= g[i - 1];
	sort(g + 1, g + k + 1);
	for (int i = 1; i <= k; i++) {
		f[i] = 2 * g[i];
		sum[i] = sum[i - 1] + g[i];
	}
	int Min = INF;
	for (int i = 1; i <= n; i++) {
		if (g[k] > v[i]) continue;
		int tv = upper_bound(f + 1, f + k + 1, v[i]) - f - 1;
		ll a2 = 1LL * (k - tv) * v[i] - (sum[k] - sum[tv]);
		ll a1 = sum[k] - sum[tv] - a2;
		a2 += sum[tv];
		if (a1 * 2 + a2 > t) continue;
		Min = min(Min, c[i]);
	}
	if (Min == INF) Min = -1;
	printf("%d\n", Min);
	return 0;
}