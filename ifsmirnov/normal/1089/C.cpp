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
typedef long double ld;
typedef long long ll;

const int maxn = 505;

const int inf = 1e9;

int n, m;
int d[maxn][maxn];
vi e[maxn];

void scan() {
    cin >> n >> m;
    forn(i, n) forn(j, n) d[i][j] = maxn;
    forn(i, n) d[i][i] = 0;
    forn(i, m) {
        int k;
        cin >> k;
        int p = -1;
        forn(j, k) {
            int v;
            cin >> v;
            --v;
            if (p != -1) {
                d[v][p] = d[p][v] = 1;
                e[v].push_back(p);
                e[p].push_back(v);
            }
            p = v;
        }
    }
    forn(i, n) sort(all(e[i]));
}

int findBest(vi& cands) {
    int best = -1, bv = inf;
    forn(v, n) {
        int mx = -1;
        for (int u : e[v]) {
            int s = 0;
            for (auto x : cands) {
                s += d[u][x] < d[v][x];
            }
            mx = max(mx, s);
        }
        if (mx < bv) {
            bv = mx;
            best = v;
        }
    }
    assert(best != -1);
    return best;
}

void solve() {
    forn(k, n) forn(i, n) forn(j, n) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    // forn(i, n) {
    //     forn(j, n) cout << d[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    forn(ITER, n) {
        vi cands;
        forn(i, n) cands.push_back(i);
        while (!cands.empty()) {
            int v = findBest(cands);
            cout << v+1 << endl;
            string s;
            cin >> s;
            if (s == "FOUND") {
                cands.clear();
            } else {
                int u;
                cin >> u;
                --u;
                vi newCands;
                for (auto x : cands) {
                    if (d[u][x] < d[v][x]) {
                        newCands.push_back(x);
                    }
                }
                cands = newCands;
                assert(!cands.empty());
            }
        }
    }
}

int main() {
#ifdef LOCAL
    // freopen("c.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}