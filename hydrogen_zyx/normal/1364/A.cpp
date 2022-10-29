#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int mmax = -1, mmin = 0x3f3f3f3f, sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] % x) {
                mmax = max(mmax, i);
                mmin = min(mmin, i);
            }
        }
        if (sum % x == 0) {
            if (mmax == -1) {
                cout << -1 << endl;
            } else {
                cout << n - min(mmin, n - mmax + 1) << endl;
                        }
        } else {
            cout << n << endl;
        }
    }
}