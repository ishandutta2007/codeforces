#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 21000
#define NN 801000
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
const int inf = 987654321;
int n, m;
int s, t;
struct Edge{
	int u, v, w;
	inline bool operator <(const Edge &a) const {
		return w < a.w;
	}
}E[NN];
struct edge{
	int nxt, to, val;
}e[NN];
int head[N], ecnt = 1, hcur[N];
inline void addedge(int from, int to, int val) {
	e[++ecnt] = (edge){head[from], to, val};
	head[from] = ecnt;
}
inline void Addedge(int u, int v, int w) {
//	printf("%d -> %d, w = %d\n", u, v, w);
	addedge(u, v, w), addedge(v, u, 0);
}
int dep[N];
int que[N], front, rear;
inline bool bfs() {
	memset(dep, 0x3f, sizeof(dep));
	for (int i = 1; i <= t; ++i)	hcur[i] = head[i];
	front = rear = 0;
	que[++rear] = s; dep[s] = 0;
	while (front < rear) {
		int cur = que[++front];// printf("cur = %d\n", cur);
		for (int i = head[cur]; i; i = e[i].nxt) {
			int to = e[i].to;// printf("to = %d\n", to);
			if (!e[i].val || dep[to] < inf)	continue;
			dep[to] = dep[cur] + 1; que[++rear] = to;
		}
	}
//	printf("dep[%d] = %d\n", t, dep[t]);
	return dep[t] <= inf;
}
int dfs(int cur, int limi) {
	if (cur == t || !limi)	return limi;
	int flow = 0;
	for (int i= hcur[cur]; i; i = e[i].nxt) {
		int to = e[i].to; hcur[cur] = i;
		if (dep[to] != dep[cur] + 1)	continue;
		int tmp = dfs(to, min(e[i].val, limi));
		if (!tmp)	continue;
		e[i].val -= tmp; e[i ^ 1].val += tmp;
		limi -= tmp; flow += tmp;
		if (!limi)	break;
	}
	return flow;
}

inline bool check(int k) {
	memset(head, 0, sizeof(head));
	ecnt = 1;
	for (int i = 1; i <= n; ++i)	Addedge(s, i, 1), Addedge(i + n, t, 1);
	for (int i= 1; i <= k; ++i) {
		int u = E[i].u, v = E[i].v;
		Addedge(u, v + n, 1);
	}
	int mxflow = 0;
	while (bfs()) {
		mxflow += dfs(s, inf);
	}
//	printf("k = %d, mxflow = %d\n", k, mxflow);
	return mxflow == n;
}
int main() {
	read(n); read(m);
	s = n + n + 1, t = s + 1;
	for (int i = 1; i <= m; ++i) {
		int u, v, w; read(u), read(v), read(w);
		E[i] = (Edge){u, v, w};
	}
	sort(E + 1, E + 1 + m);
	int l = 1, r = m, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))	res = E[mid].w, r = mid - 1;
		else	l = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}


/*
3 5
1 2 1
2 3 2
3 3 3
2 1 4
2 2 5
//4
*/