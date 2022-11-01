#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

const int maxn = 100500;

#define se second
#define fi first
#define pb push_back

pii sw(pii x) {
    return {x.se, x.fi};
}

pii add(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

int n;
vector<pii> e[maxn];


int c[maxn];
int b[maxn];
vi cur1, cur2;
vi res1, res2;


bool dfs(int v, int cc) {
    c[v] = cc;
    b[v] = 1;

    if (cc) cur1.push_back(v);
    else cur2.push_back(v);

    for (pii kv: e[v]) {
        int to, s;
        tie(to, s) = kv;
        int nc = cc ^ s;
        if (b[to]) {
            if (c[to] != nc) return false;
        } else {
            if (!dfs(to, nc)) return false;
        }
    }
    return true;
}

void solve() {
    vi best(n + 1, -1);
    forn(III, 2) {
        vi res;
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof b);
        bool bad = false;
        forn(i, n) if (!b[i]) {
            cur1.clear();
            cur2.clear();
            if (!dfs(i, 0)) {
                bad = true;
                break;
            }
//             for (int x: cur1) cerr << x << " "; cerr << "| ";
//             for (int x: cur2) cerr << x << " "; cerr << endl;
            if (cur1.size() > cur2.size()) swap(cur1, cur2);
            for (int x: cur1) res.pb(x);
        }
        if (!bad) {
            if (res.size() < best.size()) best = res;
        }

        forn(i, n) for (auto& kv: e[i]) kv.second ^= 1;

// #ifdef HOME
//         break;
// #endif
    }

    if ((int)best.size() <= n) {
        printf("%d\n", (int)best.size());
        for (int x: best) printf("%d ", x+1);
        printf("\n");
    } else {
        printf("-1\n");
    }
}

void scan() {
    int m;
    scanf("%d%d", &n, &m);
    char buf[10];
    forn(i, m) {
        int u, v;
        scanf("%d%d%s", &u, &v, buf);
        e[--u].emplace_back(--v, buf[0] == 'B');
        e[v].emplace_back(u, buf[0] == 'B');
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time: " << clock() << " ms" << endl;
#endif
}