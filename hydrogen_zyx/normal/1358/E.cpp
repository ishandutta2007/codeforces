#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll n;
ll b[500005];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= (n + 1) / 2; i++) cin >> a[i];
    ll aaa;
    cin >> aaa;
    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        a[i] = aaa;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum > 0) {
        cout << n;
        return 0;
    }
    if (sum <= 0 && aaa >= 0) {
        cout << -1;
        return 0;
    }
    ll p = (n + 1) / 2 - 1;
    aaa = -aaa;
    sum = -sum;
    for (int i = 1; i <= p; i++) {
        b[i] = b[i - 1] - a[i];
    }
    for (int i = 0; i <= p; i++) {
        b[i] -= i * aaa;
    }
    ll mmin = b[0];
    for (int k = 1; k <= p; k++) {
        mmin = min(mmin, b[k]);
        if (mmin > sum - k * aaa) {
            cout << n - k;
            return 0;
        }
    }
    cout << -1;
}