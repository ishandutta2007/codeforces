// Hydro submission #61ea6e49770aa3351b5883ed@1642753610580
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 1000010
#define L long long

int n, k, tr[N * 32][2], v[N * 32], cnt = 0;

void Insert(int x, int p = 0) {
	for (int i = 31; i >= 0; i --) {
		int b = (x >> i & 1);
		if (!tr[p][b]) tr[p][b] = ++ cnt;
		p = tr[p][b], v[p] ++;
	}
}
long long dfs(int l, int r, int w, int d, int k) {
	if (k <= 0) return (l == r) ? (L) v[l] * (v[l] - 1) / 2 : (L) v[l] * v[r];
	if (d == 0) return (((w & 1) ^ (w >> 1)) >= k) ? (l == r) ? (L) v[l] * (v[l] - 1) / 2 : (L) v[l] * v[r] : 0;
	long long s = 0;
	if (tr[l][0] && tr[r][0] && (1ll << d - 1) > k) s += dfs(tr[l][0], tr[r][0], 0, d - 1, k);
	if (tr[l][1] && tr[r][1] && (1ll << d - 1) > k) s += dfs(tr[l][1], tr[r][1], 3, d - 1, k);
	if (tr[l][0] && tr[r][1]) 			s += dfs(tr[l][0], tr[r][1], 1, d - 1, k - (1ll << d - 1));
	if (tr[l][1] && tr[r][0] && l != r)	s += dfs(tr[l][1], tr[r][0], 2, d - 1, k - (1ll << d - 1));
	return s;
}

signed main() {
	// freopen("xor.in", "r", stdin);
	// freopen("xor.out", "w", stdout);
	n = read(), k = read(), Insert(0);	
	for (int i = 1, x = 0; i <= n; i ++) x ^= read(), Insert(x);
	printf("%lld\n", dfs(0, 0, 0, 32, k));
	return 0;
}