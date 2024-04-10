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

i64 gcdex(i64 a, i64 b, i64 &x, i64 &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    i64 x1, y1;
    i64 g = gcdex(b % a, a, x1, y1);
    x = y1 - x1 * (b / a);
    y = x1;
    assert(a * x + b * y == g);
    return g;
}

i64 gcd(i64 a, i64 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    i64 x, y, p, q;
    cin >> x >> y >> p >> q;
    if (p == 0 && x != 0) {
        cout << -1 << "\n";
        return;
    }
    if (p == q && x != y) {
        cout << -1 << "\n";
        return;
    }

    i64 g = gcd(p, q);
    p /= g, q /= g;

    i64 need = p * y - q * x;
    if (need == 0) {
        cout << 0 << "\n";
        return;
    }
    q -= p;
    if (need < 0) {
        swap(p, q);
        need = -need;
    }

    if (q == 1) {
        cout << need << "\n";
        return;
    }

    i64 r, s;
    gcdex(p, q, r, s);
    if (r < 0) r += q;
    assert((p*r)%q == 1);
    i64 b = (q - (r * (need%q)) % q) % q;
    assert((need + b*p)%q == 0);
    cout << (need + b*p)/q + b << "\n";
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    int t;
    cin >> t;
    forn(i, t) solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}