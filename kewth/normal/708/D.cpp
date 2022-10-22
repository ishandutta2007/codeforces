#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 110, maxm = 1010;
int head[maxn], nxt[maxm], to[maxm], cap[maxm], cost[maxm], hp = 1;

inline void add(int u, int v, int ca, int co) {
	if((hp & 1) and !ca) return;
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	cap[hp] = ca;
	cost[hp] = co;
	if(!(hp & 1)) add(v, u, 0, - co);
}

int dis[maxn];
bool inq[maxn];

bool spfa(int s, int t) {
	std::queue<int> q;
	std::fill(dis, dis + t + 1, 1000000000);
	std::fill(inq, inq + t + 1, 0);
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = head[u]; i; i = nxt[i])
			if(cap[i] and dis[u] + cost[i] < dis[to[i]]) {
				dis[to[i]] = dis[u] + cost[i];
				if(!inq[to[i]]) {
					q.push(to[i]);
					inq[to[i]] = 1;
				}
			}
	}
	return dis[t] < 1000000000;
}

int cur[maxn];
int dinic(int u, int t, int flow) {
	inq[u] = 1;
	if(u == t) return flow;
	for(int &i = cur[u]; i; i = nxt[i])
		if(cap[i] and !inq[to[i]] and dis[u] + cost[i] == dis[to[i]]) {
			int f = dinic(to[i], t, std::min(flow, cap[i]));
			if(f) {
				cap[i] -= f;
				cap[i ^ 1] += f;
				inq[u] = 0;
				return f;
			}
		}
	inq[u] = 0;
	return 0;
}

int mincostmaxflow(int s, int t) {
	int res = 0;
	while(spfa(s, t)) {
		std::copy(head, head + t + 1, cur);
		int f = 0;
		do {
			f = dinic(s, t, 2147483647);
			res += dis[t] * f;
		} while(f);
	}
	return res;
}

int deg[maxn];
int main() {
	int n = read, m = read;
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		int u = read, v = read, c = read, f = read;
		if(c < f) {
			ans += f - c;
			add(v, u, f - c, 0);
			add(v, u, c, 1);
			add(u, v, 1000000000, 2);
		} else {
			add(u, v, c - f, 1);
			add(v, u, f, 1);
			add(u, v, 1000000000, 2);
		}
		deg[u] -= f;
		deg[v] += f;
	}

	int s = n + 1, t = n + 2, ss = n + 3, tt = n + 4;
	add(s, 1, 1000000000, 0);
	add(n, t, 1000000000, 0);
	add(t, s, 1000000000, 0);
	for(int i = 1; i <= n; i ++) {
		if(deg[i] > 0) {
			add(ss, i, deg[i], 0);
			add(s, tt, deg[i], 0);
		}
		if(deg[i] < 0) {
			add(ss, t, -deg[i], 0);
			add(i, tt, -deg[i], 0);
		}
	}

	ans += mincostmaxflow(ss, tt);
	printf("%d\n", ans);
}