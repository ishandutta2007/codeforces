#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e5 + 10;
int test, n, m, x[N], y[N], mx[N], my[N];
bool vis[N];
int main() {
	scanf("%d", &test);
	while(test --) {
		scanf("%d%d", &n, &m);
		rep(i, 0, n) mx[i] = my[i] = vis[i] = 0;
		rep(i, 1, m) {
			scanf("%d%d", x + i, y + i);
			mx[x[i]] = my[y[i]] = i;
		}
		int ans = 0;
		rep(i, 1, n) if(mx[i] && !vis[mx[i]]) {
			int u = mx[i], sz = 0, t = 0, v;
			for(v = u; !vis[v]; v = my[x[v]]) {
				if(v) vis[v] = 1, sz ++;
//				printf("%d!!\n", v);
				if(v == 0) break ;
			}
//			puts(" end"); 
			if(v == u) {
				ans += sz == 1 ? 0 : sz + 1;
			} else {
				ans += sz;
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}