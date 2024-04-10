#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 300005;
int a[maxn], b[maxn];
char s[maxn];
int fa[maxn], size[2][maxn], use[maxn];
int color[maxn];
std::vector<int> G[maxn];

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void dfs(int u, int from) {
	-- size[color[u]][find(u)];
	color[u] ^= 1;
	++ size[color[u]][find(u)];
	for(int v : G[u])
		if(v != from)
			dfs(v, u);
}

inline int get(int x) {
	if(use[x] == -1) return std::min(size[0][x], size[1][x]);
	return size[use[x]][x];
}

int main() {
	int n = read, m = read;
	scanf("%s", s + 1);

	for(int i = 1; i <= m; i ++) {
		int c = read;
		while(c --) {
			int x = read;
			if(!a[x]) a[x] = i;
			else b[x] = i;
		}
	}

	for(int i = 1; i <= m; i ++) {
		fa[i] = i;
		color[i] = 0;
		size[0][i] = 1;
		use[i] = -1;
	}

	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(!b[i]) {
			int x = find(a[i]);
			ans -= get(x);
			if(s[i] == '0')
				use[x] = color[a[i]];
			else
				use[x] = !color[a[i]];
			ans += get(x);
		} else {
			int x = find(a[i]), y = find(b[i]);
			if(x != y) {
				ans -= get(x) + get(y);
				if(size[x] > size[y]) {
					std::swap(x, y);
					std::swap(a[i], b[i]);
				}
				if(s[i] == '0' and color[a[i]] == color[b[i]]) {
					dfs(a[i], 0);
					if(~use[x])
						use[x] ^= 1;
				}
				if(s[i] == '1' and color[a[i]] != color[b[i]]) {
					dfs(a[i], 0);
					if(~use[x])
						use[x] ^= 1;
				}
				if(~use[x])
					use[y] = use[x];
				G[a[i]].push_back(b[i]);
				G[b[i]].push_back(a[i]);
				fa[x] = y;
				size[0][y] += size[0][x];
				size[1][y] += size[1][x];
				ans += get(y);
			}
		}
		printf("%d\n", ans);
	}
}