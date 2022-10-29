#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
ll b[300000];
bool cmp(int a, int b) { return a > b; }
int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
        }
        sort(b, b + k, cmp);
        int p = 0;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (b[i] == 1) {
                cnt++;
                continue;
            }
            ans += a[p];
            p += b[i] - 1;
        }
        for (int i = 0; i < k; i++) {
            if (i < cnt)
                ans += a[n - 1 - i] * 2;
            else
                ans += a[n - 1 - i];
        }
        cout << ans << endl;
    }
}