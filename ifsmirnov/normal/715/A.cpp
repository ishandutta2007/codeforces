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

i64 rev(i64 k) {
    return (k * (k-1) + 2 * (k-1) + 1) % ((k+1)*(k+1));
}

i64 mysqrt(i64 x) {
    i64 t = sqrtl(x);
    while (t*t > x) --t;
    while (t*t < x) ++t;
    assert(t*t == x);
    return t;
}

i64 closestSquare(i64 x) {
    i64 t = sqrtl(x);
    while (t*t > x) --t;
    while (t*t < x) ++t;
    return t*t;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    i64 x = 2;
    i64 k = 1;
    int skipped = 0;
    int total = 0;
    forn(i, n) {
        if (i == 0) cout << 2 << "\n";
        else cout << k*(k+1)*(k+1)  - (k-1) << "\n";
        ++k;
    }
    return 0;
    forn(i, n) {
        i64 y = 0;
        for (int t = k;; ++t) {
            i64 need = 1ll*t*t*(k+1)*(k+1);
            cerr << "need = " << need << endl;
//             assert(need >= x);
            ++total;
//             if (need < x) {
//                 ++skipped;
//                 continue;
//             }

            if (need >= x && (need-x)%k == 0) {
                y = (need-x)/k;
                x = need;
                break;
            }
            assert(false);
        }
//         while (closestSquare(x) != x || mysqrt(x) % (k+1) != 0) {
//             x += k;
//             ++y;
//         }
        x = mysqrt(x);
        cout << y << "\n";
        ++k;
//         cerr << "x = " << x << "\n";
//         cerr << "i = " << i << "\n";
        continue;
        /*
        cerr << "x = " << x << endl;
        cerr << "k = " << k << endl;
        i64 m = (k+1) * (k+1);
        i64 y = -x * rev(k);
        y = (y%m + m) % m;
        x += k*y;
        assert(x % m == 0);
        i64 t = x / m;
        i64 sq = closestSquare(t);
        cerr << "nx = " << x << endl;
        x = mysqrt(x);
        printf("%lld\n", y);
        ++k;
        cerr << endl;
        */
    }
    cerr << total << " " << skipped << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}