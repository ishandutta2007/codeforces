#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
const int maxn = 3050;

int n, m;
vi e[maxn];
int d[maxn][maxn];
int q[maxn];
int t1, s1, t2, s2, l1, l2;

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    --s1,--t1,--s2,--t2;
}

void bfs(int v, int *d) {
    int lq = 0, rq = 0;
    forn(i, n) d[i] = inf;
    d[v] = 0; q[rq++] = v;
    while (lq != rq) {
        int v = q[lq++];
        for (auto to: e[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1, q[rq++] = to;
            }
        }
    }
}

void solve() {
    forn(i, n) bfs(i, d[i]);
    if (d[s1][t1] > l1 || d[s2][t2] > l2) {
        cout << -1 << endl;
        return;
    }
    int mn = d[s1][t1] + d[s2][t2];
    forn(III, 2) {
        forn(i, n) forn(j, n) if (i != j) {
            int r1 = d[i][s1] + d[j][t1];
            int r2 = d[i][s2] + d[j][t2];
            int dd = d[i][j];
            if (r1 + dd <= l1 && r2 + dd <= l2) {
                mn = min(mn, r1 + r2 + dd);
            }
        }
        swap(t2, s2);
    }
    cout << m-mn << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}