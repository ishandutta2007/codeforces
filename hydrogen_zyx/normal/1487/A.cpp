#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mmin = inf;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mmin = min(mmin, a[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) if (a[i] != mmin) ans++;
        cout << ans << endl;
    }
}