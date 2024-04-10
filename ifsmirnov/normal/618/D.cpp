#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
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

const int maxn = 200500;

int n;
int tree, nottree;
vi e[maxn];
int deg[maxn];
int d[maxn][2];
const int ROOT = 0;

void scan() {
    scanf("%d%d%d", &n, &tree, &nottree);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        ++deg[v]; ++deg[u];
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs(int v, int anc) {
    if (anc != -1) {
        e[v].erase(find(all(e[v]), anc));
    }

    d[v][0] = d[v][1] = inf;

    int m1 = inf, m2 = inf, s1 = 0;
    int k = e[v].size();
    for (auto to: e[v]) {
        dfs(to, v);
        s1 += d[to][1];
        int m = d[to][0] - d[to][1];
        if (m < m1) {
            m2 = m1;
            m1 = m;
        } else if (m < m2) {
            m2 = m;
        }
    }

    if (k == 0) {
        d[v][0] = 1;
    } else {
        d[v][0] = s1 + m1;
        d[v][1] = s1 + m1 + m2 - 1;
    }
    d[v][1] = min(d[v][1], d[v][0]);

//     cout << v << ": " << d[v][0] << " " << d[v][1] << endl;
}

void solve() {
    if (tree > nottree) {
        i64 res = (i64)nottree * (n-1);
        if (*max_element(deg, deg+n) == n-1) {
            res += tree - nottree;
        }
        cout << res << endl;
        return;
    }

    dfs(ROOT, -1);

    i64 res = (i64)tree * (n-1) + (i64)(nottree - tree) * (d[ROOT][1] - 1);
    cout << res << endl;
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