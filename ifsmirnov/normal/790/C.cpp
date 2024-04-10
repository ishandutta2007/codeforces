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

const int maxn = 80;
const int inf = 1e9;

int n;
int d[maxn][maxn][maxn][3];
string s;
vi pc, pv, pk;
int nc[maxn], nv[maxn], nk[maxn];

void uin(int &x, int y) { x = min(x, y); }

void psum(int a[maxn]) {
    forn(i, n) if (i) a[i] += a[i-1];
}

void solve() {
    forn(i, n) {
        if (s[i] == 'V') pv.pb(i), ++nv[i];
        else if (s[i] == 'K') pk.pb(i), ++nk[i];
        else pc.pb(i), ++nc[i];
    }
    psum(nc);
    psum(nv);
    psum(nk);
    forn(i, maxn) forn(j, maxn) forn(k, maxn) forn(t, 3) d[i][j][k][t] = inf;
    d[0][0][0][0] = 0;
    forn(c, pc.size()+1) forn(v, pv.size()+1) forn(k, pk.size()+1) forn(t, 3) {
        if (d[c][v][k][t] == inf) continue;
        int n = c+v+k;
        if (c < (int)pc.size()) {
            int score = 0;
            score += max(0, v - nv[pc[c]]);
            score += max(0, k - nk[pc[c]]);
            uin(d[c+1][v][k][0], d[c][v][k][t]+score);
        }
        if (v < (int)pv.size()) {
            int score = 0;
            score += max(0, c - nc[pv[v]]);
            score += max(0, k - nk[pv[v]]);
            uin(d[c][v+1][k][1], d[c][v][k][t]+score);
        }
        if (k < (int)pk.size() && t != 1) {
            int score = 0;
            score += max(0, c - nc[pk[k]]);
            score += max(0, v - nv[pk[k]]);
            uin(d[c][v][k+1][2], d[c][v][k][t]+score);
        }
    }
    int res = inf;
    forn(i, 3) uin(res, d[pc.size()][pv.size()][pk.size()][i]);
    cout << res << endl;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    cin >> n >> s;
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}