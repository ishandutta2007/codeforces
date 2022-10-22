#include<bits/stdc++.h>

using namespace std;

// fuck life

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mn = *min_element(a.begin(), a.end()), mx = *max_element(a.begin(), a.end());
        long long ans = 0;
        if (mn != 1) {
            int res = 1e9;
            for (int i = 0; i <= n; i++) {
                int tmp = 0;
                if (i != n) {
                    tmp += abs(1 - a[i]);
                }
                if (i - 1 != -1) {
                    tmp += abs(1 - a[i - 1]);
                }
                if (i - 1 != -1 && i != n) {
                    tmp -= abs(a[i] - a[i - 1]);
                }
                res = min(res, tmp);
            }
            ans += res;
        }
        if (mx < x) {
            int res = 1e9;
            for (int i = 0; i <= n; i++) {
                int tmp = 0;
                if (i != n) {
                    tmp += abs(x - a[i]);
                }
                if (i - 1 != -1) {
                    tmp += abs(x - a[i - 1]);
                }
                if (i - 1 != -1 && i != n) {
                    tmp -= abs(a[i] - a[i - 1]);
                }
                res = min(res, tmp);
            }
            ans += res;
        }
        for (int i = 1; i < n; i++) {
            ans += abs(a[i] - a[i - 1]);
        }
        cout << ans << '\n';
    }
}