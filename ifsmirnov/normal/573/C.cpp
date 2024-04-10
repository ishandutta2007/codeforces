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

const int maxn = 100500;

int n;
vi e[maxn];
int d[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        e[v].pb(u);
        e[u].pb(v);
    }
}

int real;

bool dfs(int v, int anc) {
    int c[3] = {0,0,0};
    for (auto to: e[v]) {
        if (to == anc) continue;
        if (!dfs(to, v)) return false;
        ++c[d[to]];
    }
    if (c[2] == 0) {
        if (c[1] == 0) {
            if (c[0] <= 1) d[v] = 0;
            else if (c[0] == 2) d[v] = 1;
            else d[v] = 2;
        } else {
            d[v] = 2;
        }
    } else {
        if (c[2] >= 2) {
            if (anc == -1) {
                return c[2] == 2;
            } else {
                real = v;
                return false;
            }
        }
        d[v] = 2;
    }
    return true;
}

bool run(int root) {
    real = -1;
    forn(i, n) d[i] = 0;
    if (dfs(root, -1)) {
        return true;
    } else if (real != -1) {
        forn(i, n) d[i] = 0;
        return dfs(real, -1);
    }
    return false;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    int res = run(0);
//     forn(i, n) cout << d[i] << " "; cout << endl;
    cout << (res ? "Yes" : "No") << endl;
//     forn(i, n) assert(run(i) == res);
//     forn(i, n) cout << run(i) << " "; cout << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}