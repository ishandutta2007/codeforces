#ifdef LOCAL
// #define _GLIBCXX_DEBUG
#endif
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

int n, m;
int a[maxn][maxn];
int s[maxn][maxn];
int v[maxn][maxn];

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, n) forn(j, m) scanf("%d", &s[i][j]), a[i][j] = s[i][j];
}

int gets(int x1, int y1, int x2, int y2) {
    int res = s[x2][y2];
    if (x1) res -= s[x1-1][y2];
    if (y1) res -= s[x2][y1-1];
    if (x1 && y1) res += s[x1-1][y1-1];
    return res;
}

int lg[maxn];
void initlg() {
    forn(i, maxn) if (i) {
        lg[i] = lg[i-1];
        if (i > 2 * (1<<lg[i-1])) {
            ++lg[i];
        }
    }
}
int K;

struct ST {
    vector<vi> a;

    ST(){}

    ST(int n, int v[]) {
        a.resize(K);
        a[0].resize(n);
        forn(i, n) a[0][i] = v[i];
        forn(l, K) if (l) {
            a[l].resize(n - (1<<l) + 1);
            forn(i, n - (1<<l) + 1) {
                a[l][i] = max(a[l-1][i], a[l-1][i+(1<<(l-1))]);
            }
        }
    }

    ST(const ST& l, const ST& r) {
        a = l.a;
        if (!r.a.empty()) {
            forn(i, K) forn(j, a[i].size()) {
                a[i][j] = max(a[i][j], r.a[i][j]);
            }
        }
    }

    int get(int l, int r) {
        ++r;
        int len = lg[r-l];
        return max(a[len][l], a[len][r-(1<<len)]);
    }
};

const int sz = 1<<10;

ST rmq[sz*2];

void build() {
    forn(i, n) rmq[sz+i] = ST(m, v[i]);
    for (int i = sz - 1; i; --i) {
        rmq[i] = ST(rmq[i*2], rmq[i*2+1]);
    }
}

int get(int l, int r, int y1, int y2) {
    assert(l <= r);
    assert(y1 <= y2);
    int mx = -1;
    l += sz;
    r += sz;
    while (l < r) {
        if (l%2 == 1) mx = max(mx, rmq[l].get(y1, y2));
        if (r%2 == 0) mx = max(mx, rmq[r].get(y1, y2));
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r) mx = max(mx, rmq[l].get(y1, y2));
    return mx;
}

int query(int x1, int y1, int x2, int y2) {
    if (gets(x1, y1, x2, y2) == 0) return 0;

    int l = 1, r = min(x2-x1, y2-y1) + 1 + 1;

    while (r-l > 1) {
        int m = (l+r) / 2;
        int tx2 = x2 - m + 1;
        int ty2 = y2 - m + 1;
        if (get(x1, tx2, y1, ty2) >= m) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    forn(i, n) forn(j, m) {
        if (i) s[i][j] += s[i-1][j];
        if (j) s[i][j] += s[i][j-1];
        if (i&&j) s[i][j] -= s[i-1][j-1];
    }

    forn(i, n) forn(j, m) {
        if (a[i][j] == 0) {
            v[i][j] = 0;
        } else {
            int l = 1, r = min(n-i, m-j) + 1;
            while (r-l > 1) {
                int m = (l+r)/2;
                if (gets(i, j, i+m-1, j+m-1) == m*m) {
                    l = m;
                } else {
                    r = m;
                }
            }
            v[i][j] = l;
        }
    }

//     forn(i, n) {
//         forn(j, m) cout << v[i][j] << " ";
//         cout << endl;
//     }

    build();

    int q;
    scanf("%d", &q);
    forn(i, q) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1, --y1, --x2, --y2;
        printf("%d\n", query(x1, y1, x2, y2));
    }
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    initlg();

    scan();
    K = lg[m] + 1;
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}