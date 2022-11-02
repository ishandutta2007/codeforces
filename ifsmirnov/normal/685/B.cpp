#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;

const int maxn = 300500;

int n, q;
vi e[maxn];
int s[maxn];
vi in[maxn], out[maxn];
int p[maxn][20];
int res[maxn];
int mxv[maxn];

void scan() {
    scanf("%d%d", &n, &q);
    forn(i, n) if (i) {
        int p;
        scanf("%d", &p);
        e[p-1].pb(i);
    }
}

void dfs1(int v) {
    s[v] = 1;
    for (int to: e[v]) {
        dfs1(to);
        s[v] += s[to];
        p[to][0] = v;
    }
}

void dfs2(int v, set<int>& a) {
    vector<set<int>> ch;
    for (int to: e[v]) {
        ch.emplace_back();
        dfs2(to, ch.back());
    }
    ch.emplace_back();
    ch.back().swap(a);
    sort(all(ch), [](const set<int>& a, const set<int>& b) {
        return a.size() > b.size();
    });
    a.swap(ch[0]);
    forn(i, ch.size()) if (i) a.insert(ch[i].begin(), ch[i].end());

    for (int x: out[v]) a.insert(x);
    assert(!a.empty());
    res[v] = *a.begin();
    for (int x: in[v]) a.erase(x);

//     cerr << "vert " << v << endl;
//     cerr << "+ "; for (int x: out[v]) cerr << x << " "; cerr << ";    - ";
//     for (int x: in[v]) cerr << x << " "; cerr << endl;
//     for (int x: a) cerr << x << " "; cerr << endl;
//     cerr << "---------" << endl;
}

void solve() {
    dfs1(0);
    forn(k, 20) if (k) forn(i, n) p[i][k] = p[p[i][k-1]][k-1];

    forn(v, n) {
        if (e[v].empty()) {
            in[v].pb(v);
            out[v].pb(v);
            continue;
        }
        int tv = e[v][0];
        for (int to: e[v]) {
            if (s[to] > s[tv]) tv = to;
        }

        int S = s[v];
        int T = s[tv];

        mxv[v] = T;
        int mn = 2*T;
        int mx = 2*S;

//         cerr << v << ": " << mn << "-" << mx << endl;
        // mn <= u <= mx

        int u = v;
        if (s[u] < mn) {
            ford(k, 20) {
                int t = p[u][k];
                if (s[t] < mn) u = t;
            }

            u = p[u][0];
        }
        if (s[u] < mn || s[u] > mx) continue;
        out[u].pb(v);

//         cerr << "st: " << u << endl;

        ford(k, 20) {
            int t = p[u][k];
            if (s[t] <= mx) u = t;
        }
        in[u].pb(v);
//         cerr << "end: " << u << endl;
    }

    set<int> tmp;
    dfs2(0, tmp);

//     forn(i, n) cerr << res[i] << " "; cerr << endl;

    forn(u, n) {
        int v = res[u];
        assert((s[u] - s[v]) * 2 <= s[u]);
        assert(mxv[v] * 2 <= s[u]);
    }

    forn(i, q) {
        int v;
        scanf("%d", &v);
        printf("%d\n", res[v-1]+1);
    }
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}