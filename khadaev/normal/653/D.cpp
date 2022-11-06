#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int long long

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-9;


const int MAXN = 50;
const int INF = 100000000000000;
 
int n, c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN], edges[MAXN][MAXN];
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt) {
		int v = q[qh++];
		for (int to=0; to<n; ++to)
			if (d[to] == -1 && f[v][to] < c[v][to]) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (int & to=ptr[v]; to<n; ++to) {
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
		if (pushed) {
			f[v][to] += pushed;
			f[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	forn(i, 0, MAXN) forn(j, 0, MAXN) f[i][j] = 0;
	memset(q, 0, n * sizeof q[0]);
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, x;
	cin >> n >> m >> x;
	s = 0;
	t = n - 1;
	forn(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		cin >> edges[a][b];
	}
	ld l = 0, r = 1e18;
	while ((r - l) * x > eps) {
		ld med = (l + r) / 2;
		forn(i, 0, n) forn(j, 0, n) {
			c[i][j] = edges[i][j] / med + eps;
		}
		if (dinic() >= x) l = med;
		else r = med;
		//cerr << med << '\n';
	}
	cout << fixed << setprecision(10) << r * x << '\n';
	return 0;
}