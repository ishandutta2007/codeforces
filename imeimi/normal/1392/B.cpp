#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

llong A[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        llong mn = 1e9, mx = -1e9, k;
        int n;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            mn = min(mn, A[i]);
            mx = max(mx, A[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (k & 1) printf("%lld ", mx - A[i]);
            else printf("%lld ", A[i] - mn);
        }
        printf("\n");
    }
    return 0;
}