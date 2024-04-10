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
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int n;
int L[100005], R[100005], C[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        pii l = pii(1e9 + 5, 1e9 + 5);
        pii r = pii(0, 1e9 + 5);
        auto lr = pair(pii(1e9 + 5, 0), int(1e9 + 5));
        for (int i = 1; i <= n; ++i) {
            cin >> L[i] >> R[i] >> C[i];
            l = min(l, pii(L[i], C[i]));
            r = min(r, pii(-R[i], C[i]));
            lr = min(lr, pair(pii(L[i], -R[i]), C[i]));
            int ans = l.se + r.se;
            if (lr.fs.fs == l.fs && lr.fs.se == r.fs)
                ans = min(ans, lr.se);
            printf("%d\n", ans);
        }
    }
    return 0;
}