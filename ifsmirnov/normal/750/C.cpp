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

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    int d = 0;
    int r = 1e9, l = -1e9;
    int n;
    cin >> n;
    forn(i, n) {
        int dd, t;
        cin >> dd >> t;
        if (t == 1) {
            l = max(l, 1900-d);
        } else {
            r = min(r, 1899-d);
        }
        d += dd;
    }
    if (l > r) { cout << "Impossible\n"; return 0; }
    if (r > 1e8) { cout << "Infinity\n"; return 0; }
    cout << r+d << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}