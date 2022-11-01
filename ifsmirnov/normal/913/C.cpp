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

i64 n, m, a[100];

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    cin >> n >> m;
    forn(i, 31) a[i] = 1e18;
    forn(i, n) cin >> a[i];
    n = 31;
    forn(i, n) a[i+1] = min(a[i+1], a[i]*2);
    i64 d = 0;
    forn(i, n) {
        if (m&(1ll<<i)) d += a[i];
        else d = min(d, a[i]);
    }
    cout << d << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}