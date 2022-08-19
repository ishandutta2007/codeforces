#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1234567;
const i64 mod = 1e9 + 7;

int l[N], r[N], a[N], n, k;
i64 ans;

i64 count(i64 l, i64 r) {
	i64 ans = -1;
	ans += r / k * l;
	r %= k;
	ans += l / k * r;
	l %= k;
	if (l == 0 || r == 0) return ans;
	if (l - 1 + r - 1 < k) return ans + 1;
	return ans + 1 + (l - 1 + r - 1 - k + 1);
}
void dfs(int u, int L, int R) {
	ans = (ans + count(u - L + 1, R - u + 1) % mod * a[u]) % mod;
	if (l[u]) dfs(l[u], L, u - 1);
	if (r[u]) dfs(r[u], u + 1, R);
}

void cartesian() {
	static int s[N];
	int top = 0;
	for (int i = 1; i <= n; i++) {
		int k = top;
		while (k > 0 && a[s[k - 1]] < a[i])
			--k;
		if (k) r[s[k - 1]] = i;
		if (k < top) l[i] = s[k];
		s[k++] = i;
		top = k;
	}
	dfs(s[0], 1, n);
}

int main() {
	scanf("%d%d", &n, &k);
	--k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	cartesian();
	printf("%lld\n", ans);
}