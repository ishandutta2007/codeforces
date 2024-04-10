#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
char b[300000];
bool vis[300000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> b;
        for (int i = 0; i < n; i++) {
            if (b[i] == 'L')
                a[i] = (i - 1 + n) % n;
            else
                a[i] = (i + 1) % n;
        }
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++)
            if (a[a[i]] == i) vis[i] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (a[(i + 1) % n] == i || a[(i - 1 + n) % n] == i) continue;
            int cnt = 0;
            int k = i;
            while (!vis[k]) {
                vis[k] = 1;
                cnt++;
                k = a[k];
            }
            ans += (cnt + 1) / 3;
        }
        if (vis[0] == 0) {
            cout << (n + 2) / 3 << endl;
        } else {
            cout << ans << endl;
        }
    }
}