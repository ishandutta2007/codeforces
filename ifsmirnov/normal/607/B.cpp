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

int n;
int a[maxn];

int d[maxn][maxn], g[maxn][maxn];
// d: can, g: can(a..a)

void relax(int &x, int y) { x = min(x, y); }
void solve() {
    forn(i, maxn) forn(j, maxn) d[i][j] = g[i][j] = 10000000;
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    fore(len, 1, n) forn(i, n-len+1) {
        int j = i+len-1;
        if (len == 1) {
            g[i][i] = d[i][i] = 1;
            continue;
        }
        if (len == 2) {
            if (a[i] == a[j]) {
                d[i][j] = g[i][j] = 1;
            } else {
                d[i][j] = g[i][j] = 2;
            }
            continue;
        }
        if (a[i] == a[j]) {
            relax(g[i][j], g[i+1][j-1]);
            relax(g[i][j], d[i+1][j-1] + 1);
        }
        relax(d[i][j], g[i][j]);
        fore(k, i, j-1) {
            relax(d[i][j], d[i][k] + d[k+1][j]);
            relax(g[i][j], g[i][k] + d[k+1][j]);
            relax(g[i][j], d[i][k] + g[k+1][j]);
        }
        relax(d[i][j], g[i][j]);
    }
    cout << d[0][n-1] << endl;
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}