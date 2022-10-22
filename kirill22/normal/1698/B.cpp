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
        int ans = (n - 1) / 2;
        if (k >= 2) {
            ans = 0;
            for (int i = 1; i + 1 < n; i++) {
                ans += a[i] > a[i - 1] + a[i + 1];
            }
        }
        cout << ans << '\n';
    }
}