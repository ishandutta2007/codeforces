#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool cmp(int a, int b) { return a > b; }
int a[200005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, cmp);
        ll ans = 0;
        for (int i = 1; i <= min(k + 1, n); i++) ans += a[i];
        cout << ans << endl;
    }
}