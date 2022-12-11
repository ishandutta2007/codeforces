#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 3e5 + 10;
int n, p[N], st[20][N], f[N], g[N], lg[N];
void build() {
	lg[1] = 0;
	rep(i, 2, n) lg[i] = lg[i >> 1] + 1;
	rep(i, 1, n) st[0][i] = i + p[i];
	rep(i, 1, lg[n]) rep(j, 1, n - (1 << i) + 1)
		st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
int query(int l, int r) {
	if(r < l) return 0;
	int k = lg[r - l + 1];
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}
int main() {
	int test;
	scanf("%d", &test);
	while(test --) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", p + i);
		build();
		f[0] = f[1] = 0;
		g[0] = g[1] = 0;
		rep(i, 2, n) {
			f[i] = f[i - 1];
			g[i] = (i - 1) << 1 | 1; 
			if(f[i - 1] >= i && max(f[i - 1], i + p[i]) > f[i]) {
				f[i] = max(f[i - 1], i + p[i]);
				g[i] = (i - 1) << 1 | 1;
			}
			int t = lower_bound(f, f + i, i - p[i] - 1) - f;
			if(t < i) {
				int v = max(i - 1, query(t + 1, i - 1));
				if(f[i] < v) {
					f[i] = v;
					g[i] = t << 1;
				}
			}
		}
		if(f[n] < n) {
			puts("NO");
			continue ;
		}
		puts("YES");
		string ans;
		ans.resize(n);
		for(int u = n, v; u; u = v) {
			v = g[u] >> 1;
			if(g[u] & 1) {
				ans[u - 1] = 'R';
			} else {
				ans[u - 1] = 'L';
				rep(k, v + 1, u - 1) ans[k - 1] = 'R';
			}
		}
		puts(ans.c_str());
	}
	return 0;
}