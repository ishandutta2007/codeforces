#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p1, p2, p3;
        int mmin1 = 1000000000, mmin2 = 1000000000, mmax = 0;
        bool f = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (mmin1 + mmin2 <= a[i] && f) {
                cout << min(p1, p2) << ' ' << max(p1, p2) << ' ' << i << endl;
                f = 0;
            }
            if (a[i] < mmin1) {
                mmin2 = mmin1;
                p2 = p1;
                mmin1 = a[i];
                p1 = i;
            } else if (a[i] < mmin2) {
                mmin2 = a[i];
                p2 = i;
            }
        }
        if (f) cout << -1 << endl;
    }
}