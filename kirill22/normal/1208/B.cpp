#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        unordered_set<int> b;
        bool f = true;
        for (int j = 0; j < i; j++) {
            if (b.find(a[j]) != b.end()) {
                f = false;
            }
            b.insert(a[j]);
        }
        if (f) {
            int r = n - 1;
            while (r >= i) {
                if (b.find(a[r]) != b.end()) {
                    break;
                }
                b.insert(a[r]);
                r--;
            }
            ans = min(ans, r - i + 1);
        }
    }
    cout << ans;
}