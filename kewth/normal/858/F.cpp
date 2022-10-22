#if 0
2019.08.30

 n / 2 



#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005;
int head[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1], hp = 1;
int fap[maxn];
bool cut[maxn << 1];
int sontot[maxn];
int que[maxn], qp;
bool vis[maxn];

inline void add(int u, int v) {
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
}

inline void erase(int id) {
	cut[id] = true;
	cut[id ^ 1] = true;
}

int dfs(int u) {
	vis[u] = true;
	int res = 0;
	for(int i = head[u]; i; i = nxt[i]) {
		if(not vis[to[i]]) {
			/* debug("%d -> %d\n", u, to[i]); */
			sontot[u] ++;
			fap[to[i]] = i ^ 1;
			res += dfs(to[i]);
		}
		res ++;
	}
	return res;
}

int main() {
	int n = input(), m = input();

	for(int i = 1; i <= m; i ++) {
		int u = input(), v = input();
		add(u, v);
		add(v, u);
	}

	int ans = 0;

	for(int i = 1; i <= n; i ++)
		if(not vis[i])
			ans += dfs(i) >> 2;

	printf("%d\n", ans);

	for(int i = 1; i <= n; i ++)
		if(not sontot[i])
			que[++ qp] = i;

	while(qp) {
		int u = que[qp --];
		int last = 0;

		for(int i = head[u]; i; i = nxt[i])
			if(not cut[i] and i != fap[u]) {
				if(last) {
					printf("%d %d %d\n", to[last], u, to[i]);
					erase(last);
					erase(i);
					last = 0;
				} else
					last = i;
			}

		if(last and fap[u]) {
			printf("%d %d %d\n", to[last], u, to[fap[u]]);
			erase(last);
			erase(fap[u]);
		}

		sontot[to[fap[u]]] --;
		if(not sontot[to[fap[u]]])
			que[++ qp] = to[fap[u]];
	}
}