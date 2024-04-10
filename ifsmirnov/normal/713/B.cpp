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

#define assert(x)

int a, b, c, d;
int e, f, g, h;

int ask1(int x1, int y1, int x2, int y2) {
    int s = 0;
    s += x1 <= a && y1 <= b && x2 >= c && y2 >= d;
    s += x1 <= e && y1 <= f && x2 >= g && y2 >= h;
    return s;
}

int ask(int x1, int y1, int x2, int y2) {
    ++x1, ++y1;
    if (x1 > x2 || y1 > y2) return 0;
//     return ask1(x1,y1,x2,y2);
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout << flush;
    int t;
    cin >> t;
    return t;
}

int n;

void getBounds(vi& res, function<int(int)> f) {
    int l = 0, r = n;

    assert(f(0) == 0);
    assert(f(n) == 2);
    while (r-l > 1) {
        int m = (r+l)/2;
        if (f(m) == 2) {
            r = m;
        } else {
            l = m;
        }
    }
//     cerr << "bound 1: " << r << endl;
    res.pb(r);
    if (f(l) == 1) {
        r = l;
        l = 0;

        assert(f(l) == 0);
        assert(f(r) == 1);
        while (r-l > 1) {
            int m = (r+l)/2;
            if (f(m) == 1) {
                r = m;
            } else {
                l = m;
            }
        }
//         cerr << "bound 2: " << r << endl;
        res.pb(r);
    }
}

void solve() {
    vi X1;
    vi Y1;
    vi X2;
    vi Y2;

    getBounds(X2, [](int x) { return ask(0,0,x,n); });
    getBounds(X1, [](int x) { return ask(n-x,0,n,n); });
    getBounds(Y2, [](int y) { return ask(0,0,n,y); });
    getBounds(Y1, [](int y) { return ask(0,n-y,n,n); });
    for (auto& x: X1) x = n-x;
    for (auto& x: Y1) x = n-x;

// //     for (auto x: X1) cerr << x << " "; cerr << endl;
//     for (auto x: Y1) cerr << x << " "; cerr << endl;
//     for (auto x: X2) cerr << x << " "; cerr << endl;
//     for (auto x: Y2) cerr << x << " "; cerr << endl;

#define su(x) sort(all(x)); x.erase(unique(all(x)), x.end());

    su(X1)
    su(X2)
    su(Y1)
    su(Y2)

    vector<pair<pii, pii>> ok;
    for (auto x1: X1) for (auto x2: X2) if (x2 > x1) {
        for (auto y1: Y1) for (auto y2: Y2) if (y2 > y1) {
            if (ask(x1,y1,x2,y2) == 1) {
                ok.pb( { {x1,y1}, {x2,y2} } );
            }
        }
    }
    cout << "! ";
    for (auto kv: ok) {
        int x1, y1, x2, y2;
        tie(x1, y1) = kv.fi;
        tie(x2, y2) = kv.se;

        bool good = true;

        for (auto kv2: ok) if (kv != kv2) {
            int X1, Y1, X2, Y2;
            tie(X1, Y1) = kv2.fi;
            tie(X2, Y2) = kv2.se;

            if (X1 >= x1 && Y1 >= y1 && X2 <= x2 && Y2 <= y2) {
                good = false;
            }
        }

        if (good) {
//             cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
            cout << x1+1 << " " << y1+1 << " " << x2 << " " << y2 << " ";
        }
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
//     freopen("b.in", "r", stdin);
#endif

//     cin >> a >> b >> c >> d >> e >> f >> g >> h;

    cin >> n;
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}