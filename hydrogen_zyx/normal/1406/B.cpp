#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[600000];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        ll ans = 1;
        ll mmax = -5e18;
        for (int i = 0; i <= 5; i++) {
            ans = 1;
            for (int j = 1; j <= i; j++) ans *= a[j];
            for (int j = n; j > n - (5 - i); j--) ans *= a[j];
            mmax = max(mmax, ans);
        }
        cout << mmax << endl;
    }
}