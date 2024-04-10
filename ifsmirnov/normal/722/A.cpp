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
// #define sz(x) int((x).size())

int dist(int x, int y) {
    int s = abs(x%10 - y%10) != 0;
    x /= 10, y /= 10;
    s += abs(x%10 - y%10) != 0;
    return s;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    int t, h, m;
    scanf("%d", &t);
    scanf("%d:%d", &h, &m);
    int best = 100, bh=0, bm=0;
    forn(th, t) forn(tm, 60) {
        if (t == 12) ++th;
        int d = dist(h, th) + dist(m, tm);
        if (d < best) best = d, bh = th, bm = tm;
        if (t == 12) --th;
    }
    assert(best < 100);
    printf("%02d:%02d\n", bh, bm);


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}