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
    freopen("a.in", "r", stdin);
#endif

    i64 n, t, k, d;
    cin >> n >> t >> k >> d;
    for (int T = 0; T <= 2500000; ++T) {
        int without = k * (T / t);
        int with = without;
        if (T >= d) with += k * ( (T - d) / t);
        if (with >= n) {
            if (without < n) cout << "YES\n";
            else cout << "NO\n";
            return 0;
        }
    }
    assert(false);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}