#if 0
2020.03.18




#endif
#include <cstdio>
#include <cstring>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int inf = 1000000000;
int head[100], nxt[10000], to[10000], cap[10000], hp = 1;
int cur[100], level[100];

inline void add(int u, int v, int c) {
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	cap[hp] = c;
	if(!(hp & 1)) add(v, u, 0);
}

bool bfs(int s, int t) {
	std::queue<int> q;
	q.push(s);
	std::fill(level, level + t + 1, 0);
	level[s] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = nxt[i])
			if(cap[i] and !level[to[i]]) {
				level[to[i]] = level[u] + 1;
				q.push(to[i]);
			}
	}
	return level[t];
}

int dinic(int u, int t, int flow) {
	if(u == t) return flow;
	for(int &i = cur[u]; i; i = nxt[i])
		if(cap[i] and level[to[i]] == level[u] + 1) {
			int f = dinic(to[i], t, std::min(flow, cap[i]));
			if(f) {
				cap[i] -= f;
				cap[i ^ 1] += f;
				return f;
			}
		}
	return 0;
}

int etot[10][10], dtot[10];
int ex[10], ey[10];

int getlen(int n) {
	int len = 1, tmp = 10;
	while(n >= tmp)
		++ len, tmp *= 10;
	return len;
}

int main() {
	int n = read, len = getlen(n);

	for(int i = 1; i < n; i ++) {
		char s[10], t[10];
		scanf("%s %s", s, t);
		int a = int(strlen(s)), b = int(strlen(t));
		if(a > b) std::swap(a, b);
		++ etot[a][b];
	}

	for(int i = 1; i <= n; i ++)
		++ dtot[getlen(i)];

	int m = 0;
	for(int i = 1; i <= len; i ++)
		for(int j = i + 1; j <= len; j ++) {
			ex[m] = i;
			ey[m] = j;
			++ m;
		}

	for(int S = 0; S < (1 << m); S ++) {
		int fa[10];
		for(int i = 1; i <= len; i ++)
			fa[i] = i;
		for(int i = 0; i < m; i ++)
			if(S >> i & 1) {
				int a = ex[i], b = ey[i];
				if(!etot[a][b]) goto fail;
				if(fa[a] == fa[b]) goto fail;
				int tmp = fa[a];
				for(int x = 1; x <= len; x ++)
					if(fa[x] == tmp)
						fa[x] = fa[b];
			}
		for(int i = 1; i <= len; i ++)
			if(fa[i] != fa[1])
				goto fail;

		/* build */ {
			for(int i = 0; i < m; i ++)
				if(S >> i & 1)
					-- etot[ex[i]][ey[i]];

			int s = 66, t = 67;
			hp = 1;
			std::fill(head, head + t + 1, 0);
			for(int i = 1; i <= len; i ++)
				add(s, i, dtot[i] - 1);
			int p = len;
			for(int i = 1; i <= len; i ++)
				for(int j = i; j <= len; j ++) {
					++ p;
					add(i, p, inf);
					add(j, p, inf);
					add(p, t, etot[i][j]);
				}

			while(bfs(s, t)) {
				std::copy(head, head + t + 1, cur);
				while(dinic(s, t, inf));
			}

			for(int i = 0; i < m; i ++)
				if(S >> i & 1)
					++ etot[ex[i]][ey[i]];

			for(int i = head[s]; i; i = nxt[i])
				if(cap[i])
					goto fail;
			for(int i = head[t]; i; i = nxt[i])
				if(cap[i ^ 1])
					goto fail;

			int pow[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
			int pos[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
			for(int i = 0; i < m; i ++)
				if(S >> i & 1)
					printf("%d %d\n", pow[ex[i]], pow[ey[i]]);

			p = len;
			for(int i = 1; i <= len; i ++)
				for(int j = i; j <= len; j ++) {
					++ p;
					for(int k = head[p]; k; k = nxt[k])
						if(to[k] == i) {
							int tmp = cap[k];
							while(tmp --)
								printf("%d %d\n", ++ pos[i], pow[j]);
						} else if(to[k] == j) {
							int tmp = cap[k];
							while(tmp --)
								printf("%d %d\n", ++ pos[j], pow[i]);
						}
				}
			return 0;
		}
fail:;
	}

	puts("-1");
}