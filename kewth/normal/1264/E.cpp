#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;


const int maxd = 3000, maxm = 100000;
int head[maxd], nxt[maxm << 1], to[maxm << 1], cap[maxm << 1], cost[maxm << 1], hp = 1;

inline void add(int u, int v, int ca, int co) {
	if((hp & 1) and !ca) return;
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	cap[hp] = ca;
	cost[hp] = co;
	if(!(hp & 1)) add(v, u, 0, - co);
}

ll dis[maxd];
bool inq[maxd], vis[maxd];
int from[maxd];
bool spfa(int s, int t) {
	std::queue<int> q;
	std::fill(dis, dis + t + 1, 1000000000000000000);
	std::fill(inq, inq + t + 1, 0);
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		vis[u] = 1;
		q.pop();
		inq[u] = 0;
		for(int i = head[u]; i; i = nxt[i])
			if(cap[i] and dis[u] + cost[i] < dis[to[i]]) {
				dis[to[i]] = dis[u] + cost[i];
				from[to[i]] = i ^ 1;
				if(!inq[to[i]]) {
					q.push(to[i]);
					inq[to[i]] = 1;
				}
			}
	}
	return dis[t] < 1000000000000000000;
}

ll mincostmaxflow(int s, int t) {
	ll res = 0;
	while(spfa(s, t)) {
		int flow = cap[from[t] ^ 1];
		ll sum = cost[from[t] ^ 1];
		for(int u = to[from[t]]; u != s; u = to[from[u]]) {
			flow = std::min(flow, cap[from[u] ^ 1]);
			sum += cost[from[u] ^ 1];
		}
		cap[from[t] ^ 1] -= flow;
		cap[from[t]] += flow;
		for(int u = to[from[t]]; u != s; u = to[from[u]]) {
			cap[from[u] ^ 1] -= flow;
			cap[from[u]] += flow;
		}
		res += sum * flow;
	}
	return res;
}

const int maxn = 55;
bool force[maxn][maxn];
int eid[maxn][maxn];

int main () {
	int n = read, m = read;
	for (int i = 1; i <= m; i ++) {
		int x = read, y = read;
		force[x][y] = 1;
	}

	int p = n;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			eid[i][j] = ++ p;

	int s = ++ p, t = ++ p;

	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			add(s, eid[i][j], 1, 0);
			add(eid[i][j], i, !force[j][i], 0);
			add(eid[i][j], j, !force[i][j], 0);
		}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			add(i, t, 1, j * j - (j - 1) * (j - 1));

	mincostmaxflow(s, t);

	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			int u = eid[i][j];
			for (int k = head[u]; k; k = nxt[k])
				if (cap[k ^ 1] == 1)
					force[i == to[k] ? i : j][i == to[k] ? j : i] = 1;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			printf("%d", force[i][j]);
		puts("");
	}
}