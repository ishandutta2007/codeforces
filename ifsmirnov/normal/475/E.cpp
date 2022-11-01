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
const int maxn = 2030;

int n, m;
vi e[maxn];
int tin[maxn], tup[maxn];
int st[maxn], stp;
int comp[maxn], cn;
vi ec[maxn];
int dtime;
int b[maxn];
int w[maxn];
int s[maxn];
int lans[maxn];

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
}

void dfs(int v, int anc) {
    tin[v] = tup[v] = dtime++;
    st[stp++] = v;
    b[v] = 1;
    for (auto to: e[v]) {
        if (to == anc) continue;
        if (b[to]) {
            tup[v] = min(tup[v], tin[to]);
        } else {
            dfs(to, v);
            tup[v] = min(tup[v], tup[to]);
            if (tup[to] > tin[v]) {
                while (--stp) {
                    comp[st[stp]] = cn;
                    if (st[stp] == to) break;
                }
                ++cn;
            }
        }
    }
    if (v == 0) {
        do {
            comp[st[--stp]] = cn;
        } while (stp);
        ++cn;
    }
}

void fill_cn() {
    forn(i, n) {
        ++w[comp[i]];
        for (auto to: e[i]) {
            if (comp[to] != comp[i]) {
                ec[comp[i]].pb(comp[to]);
            }
        }
    }
    forn(i, cn) {
        sort(all(ec[i]));
        ec[i].erase(unique(all(ec[i])), ec[i].end());
    }
}

vi roots;
void find_root(int v, int anc) {
    s[v] = w[v];
    int mx = 0;
    for (auto to: ec[v]) {
        if (to == anc) continue;
        find_root(to, v);
//         if (ret != -1) return ret;
        s[v] += s[to];
        mx = max(mx, s[to]);
    }
    if (max(mx, n - s[v]) * 2 <= n) {
        roots.pb(v);
    }
//     return -1;
}

void go(int v, int anc) {
    s[v] = w[v];
    lans[v] = w[v] * w[v];
    for (auto to: ec[v]) {
        if (to == anc) continue;
        go(to, v);
        s[v] += s[to];
        lans[v] += w[v] * s[to] + lans[to];
    }
}

int dp[maxn][maxn];
int pks;
int ks(vi a) {
    ++pks;
    int n = a.size();
    int w = 0;
    for (auto x: a) w += x;
//     for (auto x: a) cout << x << " "; cout << endl;

    dp[0][0] = pks;
    forn(i, n) {
        forn(j, w+1) {
            if (dp[i][j] == pks) {
                dp[i+1][j] = pks;
            }
        }
        for (int j = w; j >= a[i]; --j) {
            if (dp[i][j-a[i]] == pks) {
                dp[i+1][j] = pks;
            }
        }
    }
    int mind = w, minj = 0;
    forn(j, w+1) if (dp[n][j] == pks) {
//         cout << "pos " << j << endl;
        int nv = abs(w/2 - j);
        if (nv < mind) {
            mind = nv;
            minj = j;
        }
    }

//     cout << "mind = " << mind << endl;

    return minj * (w - minj);
}

void solve() {
    dfs(0, -1);
    fill_cn();
    forn(i, n) b[i] = 0;
//     forn(i, cn) cout << w[i] << " "; cout << endl;
//     cout << endl;
    find_root(0, -1);
    int res = 0;
    for (auto root: roots) {
        go(root, -1);
        vi a;
        for (auto to: ec[root]) {
            a.pb(s[to]);
        }
        res = max(res, lans[root] + ks(a));
        if (clock() > CLOCKS_PER_SEC * 1.7) {
            break;
        }
        break;
    }
    cout << res << endl;
//         int res = lans[root] + ks(a);
//     cout << res << endl;
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