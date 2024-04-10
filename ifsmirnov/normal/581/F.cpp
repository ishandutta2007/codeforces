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

const int maxn = 5050;

int n;
vi e[maxn];
int d[maxn][maxn][2];
int s[maxn];
int root = 0;

void scan() {
    scanf("%d", &n);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
    if (n == 2) {
        cout << 1 << endl;
        exit(0);
    }
    while (root < n && e[root].size() == 1) ++root;
//     cerr << "root = "<< root << endl;
}

void dfs(int v, int anc) {
    s[v] = e[v].size() == 1;
    for (auto to: e[v]) if (to != anc) {
        dfs(to, v);
        s[v] += s[to];
    }
}

int min(int x, int y, int z) {
    return min(x, min(y, z));
}

void pr(vi a) {
    for (auto x: a) cout << x << " "; cout << endl;
}

void go(int v, int anc) {
    forn(i, s[v]+1) d[v][i][0] = d[v][i][1] = maxn;
    if (e[v].size() == 1) {
        d[v][1][1] = 0;
        d[v][0][0] = 0;
        d[v][0][1] = maxn;
        d[v][1][0] = maxn;
        return;
    }
    int sc = 0;
    vi cur0(sc + 1, 0);
    vi cur1(sc + 1, 0);
    for (auto to: e[v]) if (to != anc) {
        go(to, v);
        sc += s[to];

        vi nxt0(sc+1, inf);
        vi nxt1(sc+1, inf);

        forn(c, sc-s[to]+1) forn(r, s[to]+1) {
            nxt0[c+r] = min(nxt0[c+r], cur0[c] + d[to][r][0], cur0[c] + d[to][r][1] + 1);
            nxt1[c+r] = min(nxt1[c+r], cur1[c] + d[to][r][1], cur1[c] + d[to][r][0] + 1);
        }

        cur0 = nxt0;
        cur1 = nxt1;
    }

    assert((int)cur0.size() == s[v] + 1);

    forn(i, s[v] + 1) {
        d[v][i][0] = cur0[i];
        d[v][i][1] = cur1[i];
    }
}

void solve() {
    dfs(root, -1);

    go(root, -1);
    cout << min(d[root][s[root]/2][0], d[root][s[root]/2][1]) << endl;
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