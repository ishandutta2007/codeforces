#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0, j = 0, l = 0, r = 0;
        for (int i = n - 1; i >= 0; i--) {
            r += a[i];
            while (l < r && j < n) {
                l += a[j++];
            }
            if (l == r && j <= i) {
                ans = max(ans, n - i + j);
            }
        }
        cout << ans << '\n';
    }
}