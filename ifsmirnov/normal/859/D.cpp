#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i < (int)(e); ++i)
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

const int maxn = 150;

int n;
ld d[maxn][maxn], p[maxn][maxn], pr[maxn][maxn];
int l[maxn], r[maxn];

ld rd() { double x; cin >> x; return x; }

void scan() {
    cin >> n;
    n = 1<<n;
    forn(i, n) forn(j, n) pr[i][j] = rd() / 100;
}

void solve() {
    forn(i, n) {
        p[i+n][i] = 1;
        l[i+n] = i;
        r[i+n] = i+1;
    }
    ld mul = 1;
    ford(v, n) if (v) {
        l[v] = l[v*2];
        r[v] = r[v*2+1];

        int m = (l[v] + r[v]) / 2;

        ld bl = 0, br = 0;
        fore(x, l[v], r[v]) {
            if (x < m) bl = max(bl, d[v*2][x]);
            else br = max(br, d[v*2+1][x]);
        }

        // cerr << v << ": " << bl << " " << br << endl;

        fore(x, l[v], r[v]) {
            int vx = x < m ? v*2 : v*2+1;
            fore(y, l[v], r[v]) {
                if ((x < m) == (y < m)) continue;

                p[v][x] += p[vx^1][y] * pr[x][y];
            }
            p[v][x] *= p[vx][x];
        }

        fore(sel, l[v], r[v]) {
            d[v][sel] = sel < m ? br : bl;
            d[v][sel] += d[v*2 + (sel >= m)][sel];


            // fore(x, l[v], r[v]) if ((x<m) == (sel<m)) {
            int x = sel;
            ld t = 0;
            int vx = x < m ? v*2 : v*2+1;
            {
                fore(y, l[v], r[v]) if ((y<m) != (sel<m)) {

                    t += pr[x][y] * p[vx][x] * p[vx^1][y];
                }
            }
            d[v][sel] += t * mul;
            // cerr << v << " " << sel << ": " << p[v][sel] << " " << d[v][sel] << endl;
        }

        if (!(v&(v-1))) mul *= 2;
    }

    ld mx = 0;
    forn(i, n) mx = max(mx, d[1][i]);

    cout.precision(10);
    cout << fixed;
    cout << (double)mx << endl;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    scan();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}