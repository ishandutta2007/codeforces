#pragma GCC optimize(3)
#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200010, maxm = 2000010;
int head[maxn], nxt[maxm], to[maxm], cap[maxm], hp = 1;

inline void add(int u, int v, int ca) {
	if((hp & 1) and !ca) return;
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	cap[hp] = ca;
	if(!(hp & 1)) add(v, u, 0);
}

int level[maxn];

bool bfs(int s, int t) {
	std::queue<int> q;
	std::fill(level, level + t + 1, 0);
	level[s] = 1;
	q.push(s);
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

int cur[maxn];
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

int maxflow(int s, int t) {
	int res = 0;
	while(bfs(s, t)) {
		std::copy(head, head + t + 1, cur);
		int f = 0;
		do {
			f = dinic(s, t, 2147483647);
			res += f;
		} while(f);
	}
	return res;
}

int tmp[maxn], tp;
int x[maxn], y[maxn];
int typ[maxn], pos[maxn], dif[maxn];
int vdif[maxn];
int deg[maxn];
std::set<int> xset, yset;

char ans[maxn];
int main() {
	int n = read, m = read;
	int a = read, b = read;
	char rb[] = "rb";
	if(a > b) std::swap(rb[0], rb[1]);

	for(int i = 1; i <= n; i ++) {
		x[i] = read;
		y[i] = read;
	}

	for(int i = 1; i <= m; i ++) {
		typ[i] = read;
		tmp[++ tp] = pos[i] = read;
		if(typ[i] == 1) xset.insert(pos[i]);
		if(typ[i] == 2) yset.insert(pos[i]);
		dif[i] = read;
	}

	std::sort(tmp + 1, tmp + tp + 1);
	++ tp;
	for(int i = 1; i <= n; i ++) {
		x[i] = !xset.count(x[i]) ? tp :
			int(std::lower_bound(tmp + 1, tmp + tp, x[i]) - tmp);
		y[i] = !yset.count(y[i]) ? tp :
			int(std::lower_bound(tmp + 1, tmp + tp, y[i]) - tmp);
	}
	for(int i = 1; i <= m; i ++)
		pos[i] = int(std::lower_bound(tmp + 1, tmp + tp, pos[i]) - tmp);

	for(int i = 1; i <= tp * 2; i ++)
		vdif[i] = 1000000000;
	for(int i = 1; i <= m; i ++) {
		int &now = vdif[pos[i] + (typ[i] - 1) * tp];
		if(dif[i] < now)
			now = dif[i];
	}

	int s = tp * 2 + 1, t = tp * 2 + 2;
	int ss = tp * 2 + 3, tt = tp * 2 + 4;

	for(int i = 1; i <= n; i ++) {
		add(x[i], tp + y[i], 1);
		++ deg[x[i]];
		++ deg[tp + y[i]];
	}

	for(int i = 1; i <= tp * 2; i ++) {
		int min = deg[i] < vdif[i] ? 0 : (deg[i] - vdif[i] + 1) >> 1;
		int max = deg[i] - min;
		if(min > max) return puts("-1"), 0;

		if(i <= tp) {
			add(s, i, max - min);
			add(s, tt, min);
			add(ss, i, min);
		} else {
			add(i, t, max - min);
			add(i, tt, min);
			add(ss, t, min);
		}
	}

	add(t, s, 1000000000);

	maxflow(ss, tt);

	for(int i = head[ss]; i; i = nxt[i])
		if(cap[i])
			return puts("-1"), 0;
	for(int i = head[tt]; i; i = nxt[i])
		if(cap[i ^ 1])
			return puts("-1"), 0;

	maxflow(s, t);
	ll sum = 0;
	for(int i = 1; i <= n; i ++) {
		ans[i] = rb[cap[i << 1]];
		if(ans[i] == 'r') sum += a;
		if(ans[i] == 'b') sum += b;
	}

	printf("%lld\n%s\n", sum, ans + 1);
}