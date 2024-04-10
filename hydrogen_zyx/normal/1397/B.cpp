#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[500000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    sort(a + 1, a + 1 + n);
    ll mmin = 0x3f3f3f3f3f3f3f3f;
    bool f = 1;
    for (int i = 1; i <= 1e6 && f; i++) {
        ll ans = 0;
        ll now = 1;
        ans += abs(a[1] - 1);
        for (int j = 2; j <= n; j++) {
            now *= i;
            if (now > 1000000000000) {
                f = 0;
                break;
            }
            ans += abs(a[j] - now);
        }
        if (f) mmin = min(mmin, ans);
    }
    cout << mmin;
}