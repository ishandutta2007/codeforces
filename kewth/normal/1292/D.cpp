#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 10050;
int val[maxn];
int mp[maxn];
std::vector<int> G[maxn];
int Fa[maxn];
int deep[maxn];
int stack[maxn], sp;
int a[maxn];

int size[maxn];
void dfs(int u) {
	size[u] = val[u];
	for(int v : G[u]) {
		dfs(v);
		size[u] += size[v];
	}
}

ll ans = 0;
void calc(int u, int fa, int d) {
	ans += 1ll * d * val[u];
	for(int v : G[u])
		if(v != fa)
			calc(v, u, d + deep[v] - deep[u]);
	if(Fa[u] != fa)
		calc(Fa[u], u, d + deep[u] - deep[Fa[u]]);
}

int main() {
	int N = 5000;

	mp[1] = 1;
	for(int i = 2; i <= N; i ++)
		if(!mp[i])
			for(int j = i; j <= N; j += i)
				mp[j] = i;

	stack[0] = 1;
	for(int x = 2; x <= N; x ++) {
		for(int i = mp[x]; i < x; i ++)
			deep[x + N] += a[i];

		deep[x] = deep[x - 1];
		for(int y = x; y > 1; y /= mp[y]) {
			++ a[mp[y]];
			++ deep[x];
		}

		while(deep[stack[sp]] > deep[x + N]) {
			int y = stack[sp --];
			if(deep[stack[sp]] > deep[x + N])
				G[stack[sp]].push_back(y);
			else
				G[x + N].push_back(y);
		}
		stack[++ sp] = x + N;
		stack[++ sp] = x;
	}

	while(sp) {
		int x = stack[sp --];
		G[stack[sp]].push_back(x);
	}

	int n = read;
	for(int i = 1; i <= n; i ++)
		++ val[std::max(1, int(read))];

	dfs(1);
	int u, to = 1;
	do {
		u = to;
		for(int v : G[u])
			if(size[v] * 2 > n)
				to = v;
	} while(u != to);

	for(int u = 1; u <= N * 2; u ++)
		for(int v : G[u])
			Fa[v] = u;

	calc(u, 0, 0);

	printf("%lld\n", ans);
}