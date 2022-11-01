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

const int maxn = 100500;

int n, m;
vi e[maxn];
int c[maxn];
int s;

void dfs(int v, int anc, int h) {
    if (c[v]) ++h;
    else h = 0;
    if (h == m+1) return;
    bool lf = true;
    for (auto to: e[v]) if (to != anc) {
        lf = false;
        dfs(to, v, h);
    }
    if (lf) ++s;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%d", &c[i]);
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }

    dfs(0, -1, 0);
    cout << s << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}