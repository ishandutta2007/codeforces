#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

struct MinCostMaxFlow {
	static const int mxn = 8888, mxm = 200000;
	int V[mxm], W[mxm], C[mxm], nex[mxm], m;
	int n, S, T;
	int head[mxn];
	inline void init(int _n, int _S, int _T) {
		n = _n, S = _S, T = _T;
		m = 0;
		rep(i, n) head[i] = -1;
	}
	inline void __add_edge(int u, int v, int w, int c) {
		V[m] = v, W[m] = w, C[m] = c, nex[m] = head[u], head[u] = m ++;
	}
	inline void add_edge(int u, int v, int w, int c) {
		__add_edge(u, v, w, c);
		__add_edge(v, u, 0, -c);
	}
	int dis[mxn], pu[mxn], pe[mxn];
	inline bool spfa() {
		static int h[mxn];
		rep(i, n) h[i] = dis[i];
		rep(i, n) dis[i] = i == S ? 0 : 0x3f3f3f3f;
		std::priority_queue <std::pair <int, int> > pq;
		pq.push({-dis[S], S});
		while (!pq.empty()) {
			int u = pq.top().second;
			int d = -pq.top().first;
			pq.pop();
			if (d > dis[u]) continue;
			for (int e = head[u]; ~e; e = nex[e]) {
				int v = V[e], w = W[e], c = C[e];
				if (w && dis[v] > dis[u] + c + h[u] - h[v]) {
					dis[v] = dis[u] + c + h[u] - h[v];
					pu[v] = u, pe[v] = e;
					pq.push({-dis[v], v});
				}
			}
		}
		rep(i, n) dis[i] = std::min(0x3f3f3f3f, dis[i] + h[i]);
		return dis[T] < 1e9;
		
	}
	inline void solve(int &flow, int &cost) {
		flow = cost = 0;
		while (spfa()) {
			int f = 0x3f3f3f3f;
			for (int u = T; u != S; u = pu[u]) f = std::min(f, W[pe[u]]);
			flow += f, cost += f * dis[T];
			for (int u = T; u != S; u = pu[u]) W[pe[u]] -= f, W[pe[u] ^ 1] += f;
		}
	}
} mcmf;

const int mxn = 2205;
const int inf = 0x3f3f3f3f;
int n, a[mxn * 2], b[mxn * 2];

i64 f[mxn * 2], g[mxn * 2];
i64 h[mxn * 2];
std::vector <int> idf, idg, idh;

int flow, cost;

inline void run(int tim) {
	rep(i, n * 2) f[i] = b[i], g[i] = 1LL * tim * a[i] + b[i];
	idf.resize(n * 2); std::iota(idf.begin(), idf.end(), 0);
	std::sort(idf.begin(), idf.end(), [&] (int i, int j) { return f[i] < f[j]; });
	idg.resize(n * 2); std::iota(idg.begin(), idg.end(), 0);
	std::sort(idg.begin(), idg.end(), [&] (int i, int j) { return g[i] < g[j]; });
	idh.resize(n * 2); std::iota(idh.begin(), idh.end(), 0);
	std::sort(idh.begin(), idh.end(), [&] (int i, int j) { return h[i] < h[j]; });
	std::vector <i64> maxg(n * 2 + 1);
	maxg[0] = 0;
	rep(i, n * 2) maxg[i + 1] = std::max(maxg[i], g[idf[i]]);
	rep(i, n * 2) h[i] = maxg[std::upper_bound(idf.begin(), idf.end(), i, [&] (int x, int y) { return f[x] < f[y]; }) - idf.begin()];
	int S = n * 4, T = n * 4 + 1;
	mcmf.init(n * 4 + 2, S, T);
	rep(i, n) mcmf.add_edge(S, i, 1, 0);
	int last;
	std::vector <int> ndf(idf.size() + 1, -1), ndg(idg.size() + 1, -1);
	last = -1;
	rep(i, n * 2) {
		if (idf[i] >= n) {
			if (~last) mcmf.add_edge(n + (idf[i] - n), n + (last - n), inf, 0);
			last = idf[i];
		}
		ndf[i + 1] = last;
	}
	last = -1;
	rep(i, n * 2) {
		if (idg[i] >= n) {
			if (~last) mcmf.add_edge(n * 2 + (idg[i] - n), n * 2 + (last - n), inf, 0);
			last = idg[i];
		}
		ndg[i + 1] = last;
	}
	rep(i, n) {
		mcmf.add_edge(n + i, n * 3 + i, 1, 0);
		mcmf.add_edge(n * 2 + i, n * 3 + i, 1, 0);
		mcmf.add_edge(n * 3 + i, T, 1, 0);
	}
	rep(i, n) {
		int p;
		p = std::upper_bound(idf.begin(), idf.end(), i, [&] (int x, int y) { return f[x] < f[y]; }) - idf.begin();
		if (~ndf[p]) mcmf.add_edge(i, n + (ndf[p] - n), 1, 1);
		p = std::upper_bound(idg.begin(), idg.end(), i, [&] (int x, int y) { return g[x] < g[y]; }) - idg.begin();
		if (~ndg[p]) mcmf.add_edge(i, n * 2 + (ndg[p] - n), 1, 1);
		p = std::upper_bound(idg.begin(), idg.end(), i, [&] (int x, int y) { return h[x] < g[y]; }) - idg.begin();
		if (~ndg[p]) mcmf.add_edge(i, n * 2 + (ndg[p] - n), 1, 2);
	}
	mcmf.solve(flow, cost);
}

inline bool chk(int tim) {
	rep(i, n * 2) f[i] = b[i], g[i] = 1LL * tim * a[i] + b[i];
	idf.resize(n * 2); std::iota(idf.begin(), idf.end(), 0);
	std::sort(idf.begin(), idf.end(), [&] (int i, int j) { return f[i] < f[j]; });
	idg.resize(n * 2); std::iota(idg.begin(), idg.end(), 0);
	std::sort(idg.begin(), idg.end(), [&] (int i, int j) { return g[i] < g[j]; });
	idh.resize(n * 2); std::iota(idh.begin(), idh.end(), 0);
	std::sort(idh.begin(), idh.end(), [&] (int i, int j) { return h[i] < h[j]; });
	std::vector <i64> maxg(n * 2 + 1);
	maxg[0] = 0;
	rep(i, n * 2) maxg[i + 1] = std::max(maxg[i], g[idf[i]]);
	rep(i, n * 2) h[i] = maxg[std::upper_bound(idf.begin(), idf.end(), i, [&] (int x, int y) { return f[x] < f[y]; }) - idf.begin()];
	int cnt = 0;
	std::vector <bool> vis(n * 2);
	int c = 0;
	int jf = 0, jg = 0;
	rep(_, n * 2) if (idf[_] < n) {
		int i = idf[_];
		while (jf < n * 2 && f[idf[jf]] <= f[i]) {
			if (idf[jf] >= n && !vis[idf[jf]]) vis[idf[jf]] = 1, ++ cnt;
			++ jf;
		}
		while (jg < n * 2 && g[idg[jg]] <= h[i]) {
			if (idg[jg] >= n && !vis[idg[jg]]) vis[idg[jg]] = 1, ++ cnt;
			++ jg;
		}
		++ c;
		if (c > cnt) return 0;
	}
	return 1;
}

inline void solve(int tim) {
	run(tim); printf("%d\n", cost);
}

int main() {
	scanf("%d", &n);
	rep(i, n * 2) scanf("%d %d", &a[i], &b[i]);
	int lb = 0, rb = 0x3f3f3f3f;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (chk(md)) rb = md;
		else lb = md + 1;
	}
	if (lb > 1e9 + 100) puts("-1");
	else {
		printf("%d ", lb);
		solve(lb);
	}
    return 0;
}