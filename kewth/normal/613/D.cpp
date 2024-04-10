#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 100005;
int head[maxn], nxt[maxn << 1], to[maxn << 1], hp = 1;
int son[maxn], top[maxn], deep[maxn], size[maxn], fa[maxn];
int id[maxn], iid[maxn], ip;
int key[maxn], ikey[maxn], kp;
int stack[maxn], sp;
int f[maxn], g[maxn];

inline void add(int u, int v) {
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
}

void dfs1(int u) {
	deep[u] = deep[fa[u]] + 1;
	size[u] = 1;
	for(int i = head[u]; i; i = nxt[i])
		if(to[i] != fa[u]) {
			fa[to[i]] = u;
			dfs1(to[i]);
			size[u] += size[to[i]];
			if(size[to[i]] > size[son[u]])
				son[u] = to[i];
		}
}

void dfs2(int u) {
	iid[id[u] = ++ ip] = u;
	if(son[u]) {
		top[son[u]] = top[u];
		dfs2(son[u]);
		for(int i = head[u]; i; i = nxt[i])
			if(to[i] != fa[u] and to[i] != son[u]) {
				top[to[i]] = to[i];
				dfs2(to[i]);
			}
	}
}

int lca(int x, int y) {
	while(top[x] != top[y])
		if(deep[top[x]] < deep[top[y]])
			y = fa[top[y]];
		else
			x = fa[top[x]];
	return deep[x] < deep[y] ? x : y;
}

bool cmp(int x, int y) {
	return id[x] < id[y];
}

bool fg;
void dp(int u, int m) {
	/* debug("dp %d\n", u); */
	/* for(int i = head[u]; i; i = nxt[i]) */
	/* 	debug("%d -> %d\n", u, to[i]); */
	for(int i = head[u]; i; i = nxt[i])
		dp(to[i], m);

	if(key[u] <= m) {
		if(key[fa[u]] and key[fa[u]] <= m)
			fg = 1;
		f[u] = 0;
		for(int i = head[u]; i; i = nxt[i])
			f[u] += g[to[i]];
		g[u] = f[u] + 1;
	}

	else {
		int sumf = 0, sumg = 0, d = 0;
		for(int i = head[u]; i; i = nxt[i]) {
			sumf += f[to[i]];
			sumg += g[to[i]];
			d = std::min(d, f[to[i]] - g[to[i]]);
		}
		f[u] = std::min(sumf + 1, sumg + d);
		sumf += 0;
		sumg += 1;
		d = std::min(d, -1);
		g[u] = std::min(sumf + 1, sumg + d);
	}
}

int main() {
	int n = input();

	for(int i = 1; i < n; i ++) {
		int u = input(), v = input();
		add(u, v);
		add(v, u);
	}

	dfs1(1);
	top[1] = 1;
	dfs2(1);

	for(int i = 1; i <= n; i ++)
		head[i] = 0;

	int q = input();
	while(q --) {
		int m = input();
		for(int i = 1; i <= m; i ++)
			ikey[i] = input();
		std::sort(ikey + 1, ikey + m + 1, cmp);

		hp = sp = kp = 0;

		for(int i = 1; i <= m; i ++)
			key[ikey[i]] = ++ kp;

		stack[++ sp] = 1;
		if(!key[1]) ikey[key[1] = ++ kp] = 1;

		for(int i = 1; i <= m; i ++) {
			int u = ikey[i];
			if(u == 1) continue;
			int x = stack[sp];
			int l = lca(u, x);
			/* debug("%d %d %d\n", u, x, l); */

			while(deep[l] < deep[x]) {
				int y = x;
				x = stack[-- sp];
				if(deep[l] < deep[x])
					add(x, y);
				else
					add(l, y);
			}

			if(deep[l] > deep[x]) {
				ikey[key[l] = ++ kp] = l;
				stack[++ sp] = l;
			}

			stack[++ sp] = u;
		}

		for(int i = 2; i <= sp; i ++)
			add(stack[i - 1], stack[i]);

		fg = 0;
		dp(1, m);
		printf("%d\n", fg ? -1 : f[1]);

		for(int i = 1; i <= kp; i ++)
			key[ikey[i]] = head[ikey[i]] = 0;
	}
}