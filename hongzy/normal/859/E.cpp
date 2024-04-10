#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int mo = 1e9 + 7;
const int N = 2e5 + 10;
int n, f[N], cir[N], lop[N], sz[N], ans = 1;
int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
int main() {
	//freopen("qwq.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; i ++) f[i] = i, sz[i] = 1;
	for(int u, v, i = 1; i <= n; i ++) {
		scanf("%d%d", &u, &v);
		int x = find(u), y = find(v);
		if(u == v) lop[x] = 1;
		if(x == y) cir[x] = 1;
		else {
			f[x] = y; cir[y] |= cir[x]; sz[y] += sz[x]; lop[y] |= lop[x];
		}
	}
	for(int i = 1; i <= 2 * n; i ++) {
		if(find(i) == i && sz[i] > 1 && !lop[i]) {
			if(cir[i]) {
				if(sz[i] > 1) ans = (ans << 1) % mo;
			} else {
				ans = 1ll * ans * sz[i] % mo;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}