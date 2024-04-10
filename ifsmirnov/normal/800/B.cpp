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

struct pt {
    ld x, y;

    pt operator-(const pt& p) const { return {x-p.x, y-p.y}; }
    ld operator*(const pt& p) const { return x*p.x + y*p.y; }
    ld operator%(const pt& p) const { return x*p.y - y*p.x; }
    ld abs() const { return sqrtl(*this * *this); }
};

ld dist(pt a, pt b, pt p) {
    ld res;
    if ((b-a) * (p-a) < 0) res = (p-a).abs();
    if ((a-b) * (p-b) < 0) res = (p-b).abs();
    else res = fabsl( ((p-a) % (b-a)) / (a-b).abs() );
//     cerr << a.x << " " << a.y << ", " << b.x << " " << b.y << ", " <<
//         p.x << " " << p.y << ": " << res << endl;
    return res;
}

ld res = 1e18;
int n;
pt p[1010];

void solve() {
    cin >> n;
    forn(i, n) cin >> p[i].x >> p[i].y;

    forn(i, n) {
        int a = (i+1)%n, b = (i-1+n)%n;
        res = min(res, dist(p[a], p[b], p[i]));
        forn(j, n) if (j != i && (j+1)%n != i) {
            res = min(res, dist(p[j], p[(j+1)%n], p[i]));
        }
    }
    cout.precision(10);
    cout << fixed;
    cout << res/2 << endl;
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