#include<bits/stdc++.h>
 
using namespace std;

const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 1;
        for (int i = 0; i < k; i++) {
            if (a[n - i - 1] > 0) {
                ans = 0;
            }
        }
        for (int i = 1; i <= k; i++) {
            ans = ans * 1ll * i % mod;
        }
        for (int i = 0; i < n - k; i++) {
            if (a[i] == -1) {
                ans = ans * 1ll * (i + k + 1) % mod;
            } else if (a[i] == 0) {
                ans = ans * 1ll * (k + 1) % mod;
            }
        }
        cout << ans << '\n';
    }
}