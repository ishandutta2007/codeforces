#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
// #define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
// #define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
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
    freopen("b.in", "r", stdin);
#endif
#define int i64

    int n, h, k;
    cin >> n >> h >> k;
    vi a(n);
    forn(i, n) cin >> a[i];
    int ptr = 0;
    int cur = 0;
    int t = 0;

    while (ptr != n || cur > 0) {
        if (ptr < n && cur + a[ptr] <= h) {
            cur += a[ptr++];
        } else {
            int need;
            if (ptr == n) need = (cur + k - 1) / k;
            else need = (a[ptr] + cur - h + k - 1) / k;
            t += need;
            cur -= min(cur, k * need);
        }
    }
    cout << t << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}