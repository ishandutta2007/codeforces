#include<bits/stdc++.h>

using namespace std;

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
        int ans = 0;
        for (int j = 30; j >= 0; j--) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (a[i] >> j & 1);
            }
            cnt = n - cnt;
            if (k >= cnt) {
                k -= cnt;
                ans += (1 << j);
            }
        }
        cout << ans << '\n';
    }
}