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

const int maxn = 100500;
int n;

int x[maxn], y[maxn]; // n, n+1: guys, n+2: urna

ld dist(int i, int j) {
    ld dx = x[i] - x[j];
    ld dy = y[i] - y[j];
    return sqrtl(dx*dx+dy*dy);
}

void scan() {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", &x[i], &y[i]);
    tie(x[n], y[n], x[n+1], y[n+1], x[n+2], y[n+2]) = tie(a,b,c,d,e,f);
}

pair<ld, int> u1[maxn], u2[maxn];

void solve() {
    ld score = 0;
    forn(i, n) score += 2 * dist(i, n+2);
    forn(i, n) {
        u1[i] = {dist(i, n+2) - dist(i, n), i};
        u2[i] = {dist(i, n+2) - dist(i, n+1), i};
    }
    sort(u1, u1+n); reverse(u1, u1+n);
    sort(u2, u2+n); reverse(u2, u2+n);

    ld best = -1e40;
    best = max(best, u1[0].fi);
    best = max(best, u2[0].fi);
    forn(i, min(2, n)) forn(j, min(2, n)) {
        if (u1[i].se != u2[j].se) {
            best = max(best, u1[i].fi + u2[j].fi);
        }
    }

    cout.precision(10);
    cout << fixed << score - best << endl;
}


int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}