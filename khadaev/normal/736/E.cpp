#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int MAXN = 3010;

int n, c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];
 
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
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

void fail() {
    puts("no");
    exit(0);
}

int ans[MAXN][MAXN];

int main() {
    int m, k;
    cin >> m >> k;
    vector<int> a(k);
    forn(i, 0, k) cin >> a[i];
    int rest = m * (m - 1);
    forn(i, 0, k) rest -= a[i];
    if (rest < 0) fail();
    if (rest > a.back() * (m - k)) fail();
    s = k, t = k + 1;
    int fake = k + 2;
    n = k + 3;
    for (int i = 0; i < k; ++i)
        c[s][i] = 2 * (m - 1 - i);
    c[s][fake] = (m - k) * (m - k - 1);
    forn(i, 0, k) forn(j, i + 1, k) c[i][j] = 2;
    forn(i, 0, k) c[i][fake] = 2 * (m - k);
    forn(i, 0, k) c[i][t] = a[i];
    c[fake][t] = rest;
    int res = dinic();
    if (res != m * (m - 1)) fail();
    puts("yes");
    forn(i, 0, k) forn(j, i + 1, k) {
        ans[i][j] = 2 - f[i][j];
        ans[j][i] = f[i][j];
    }
    int tmp = k;
    forn(i, 0, k) {
        forn(j, k, m) {
            ans[i][j] = 2;
            ans[j][i] = 0;
        }
        forn(q, 0, f[i][fake]) {
            --ans[i][tmp];
            ++ans[tmp][i];
            ++tmp;
            if (tmp == m) tmp = k;
        }
    }
    forn(i, k, m) forn(j, k, m) ans[i][j] = 1;
    forn(i, 0, m) {
        forn(j, 0, m) {
            if (i == j) putchar('X');
            else if (ans[i][j] == 2) putchar('W');
            else if (ans[i][j] == 1) putchar('D');
            else putchar('L');
        }
        putchar('\n');
    }
}