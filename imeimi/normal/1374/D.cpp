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

int A[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            A[i] = k - ((A[i] - 1) % k + 1);
            ++cnt[A[i]];
        }
        llong ans = 0;
        for (auto [x, c] : cnt) {
            if (x == 0) continue;
            ans = max(ans, (c - 1ll) * k  + x + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}