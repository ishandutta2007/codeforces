#if 0
date

(cf538h)
 [t, T] 
x = min(r), y = max(l) 



 x + y in [t, T]  x y 
 x + y < t  y  x + y > T  x 
 x, y 


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005;
std::vector<int> G[maxn];
int color[maxn];
int l[maxn], r[maxn];

inline shit() { puts("IMPOSSIBLE"); exit(0); }

void dfs(int u, int c) {
	if(!color[u]) {
		color[u] = c;
		for(int v : G[u])
			dfs(v, 3 - c);
	} else if(color[u] != c)
		shit();
}

int main() {
	int L = read, R = read;
	int n = read, m = read;
	int x = 1000000000, y = 0;
	for(int i = 1; i <= n; i ++) {
		l[i] = read;
		r[i] = read;
		x = std::min(x, r[i]);
		y = std::max(y, l[i]);
	}

	for(int i = 1; i <= m; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	if(x + y < L) y = L - x;
	if(x + y > R) x = R - y;
	if(x < 0 or y < 0) shit();
	
	for(int i = 1; i <= n; i ++) {
		bool a = l[i] <= x and x <= r[i];
		bool b = l[i] <= y and y <= r[i];
		if(a and !b) dfs(i, 1);
		if(!a and b) dfs(i, 2);
		if(!a and !b) shit();
	}

	for(int i = 1; i <= n; i ++)
		if(!color[i])
			dfs(i, 1);
			
	puts("POSSIBLE");
	printf("%d %d\n", x, y);
	for(int i = 1; i <= n; i ++)
		printf("%d", color[i]);
	puts("");
}