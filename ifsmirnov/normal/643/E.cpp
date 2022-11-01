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
typedef double ld;

const int maxn = 500500;
const int K = 90;

const ld eps = 1e-30;

int n, q;
int p[maxn];
ld d[maxn][K];

void addv(int par) {
    int v = n++;
    p[v] = par;
    forn(k, K) d[v][k] = 1;
    d[v][0] = 0;
    ld cur = d[par][1];
    d[par][1] /= 2;
    ld nxt = d[par][1];
    int len = 1;
    v = par;
    while (true) {
        if (v == 0) break;
        par = p[v];
        ++len;
        if (len >= K) break;
        ld delta = (1 + nxt) / (1 + cur);
//         if (fabs(1.0 - delta) < eps) break;

        cur = d[par][len];
        d[par][len] *= delta;
        nxt = d[par][len];
        v = p[v];
    }
}

ld getscore(int v) {
    ld res = 0;
    forn(k, K-1) {
        res += k * (d[v][k+1] - d[v][k]);
    }
    return res;
}

void solve() {
    n = 1;
    forn(k, K) d[0][k] = 1;
    d[0][0] = 0;
    scanf("%d", &q);
    cerr.precision(2);
//     cerr << fixed;
    forn(qqq, q) {
        int type, v;
        scanf("%d%d", &type, &v);
        --v;
        if (type == 1) {
            addv(v);
        } else {
            printf("%.10lf\n", getscore(v));
        }
        /*
        forn(i, n) {
            forn(k, K) cerr << d[i][k] << " ";
            cerr << endl;
        }
        cerr << endl;
        */
    }
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
//     freopen("e.out", "w", stdout);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}