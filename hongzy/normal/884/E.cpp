#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 4098;
int n, m, i, j, cnt, fa[N * 8];
int id(int x, int y) { return x * m + y; }
int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if(u != v) fa[u] = v, cnt --;
}
int main() {
	scanf("%d%d", &n, &m);
	static char s[N];
	static bool now, la[N * 4];
	int ans = 0, c = 0;
	for(i = 1, j; i <= n; i ++) {
		scanf("%s", s + 1); c ^= 1;
		for(j = 1; j <= m / 4; j ++) s[j] = ((s[j] >= 'A' && s[j] <= 'F') ? s[j] - 'A' + 10 : s[j] - '0');
		for(j = 1; j <= m; j += 1) {
			now = s[(j + 3) / 4] >> (3 - (j - 1) % 4) & 1;
			cnt += now; fa[id(c, j)] = id(c, j);
			if(now == 1) {
				if(j > 1 && la[j - 1]) {
					merge(id(c, j - 1), id(c, j));
				}
				if(la[j]) {
					merge(id(c ^ 1, j), id(c, j));
				}
			} else {
				fa[id(c, j)] = 0;
			}
			la[j] = now;
		}
	}
	printf("%d\n", cnt);
	return 0;
}