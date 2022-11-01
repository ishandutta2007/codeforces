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

const int maxn = 1050;

int n;
int p[maxn];
int w[maxn], b[maxn];
int ww[maxn], bb[maxn];
int W;

int d[maxn][maxn];

int get(int x) { return p[x] == x ? x : (p[x] = get(p[x])); }
void unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return;
    p[x] = y;
    w[y] += w[x];
    b[y] += b[x];
}

void scan() {
    int m;
    scanf("%d%d%d", &n, &m, &W);
    forn(i, n) p[i] = i;
    forn(i, n) scanf("%d", &w[i]), ww[i] = w[i];
    forn(i, n) scanf("%d", &b[i]), bb[i] = b[i];
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        unite(u-1, v-1);
    }
}

void uax(int &x, int y) { x = max(x, y); }

void solve() {
    forn(i, n) {
        if (p[i] != i) {
            fore(j, 0, W) d[i+1][j] = d[i][j];
        } else {
            fore(j, 0, W) d[i+1][j] = d[i][j];
            fore(j, 0, W - w[i]) uax(d[i+1][j+w[i]], d[i][j] + b[i]);
            forn(k, n) if (get(k) == i) {
                fore(j, 0, W - ww[k]) uax(d[i+1][j+ww[k]], d[i][j] + bb[k]);
            }
        }
    }
    int res = 0;
    fore(j, 0, W) uax(res, d[n][j]);
    cout << res << endl;
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