#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, r;
        cin >> n >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int tmp = 0;
        int ans = 0;
        set<int> b;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] - tmp <= 0 || (b.find(a[i]) != b.end())) {
                continue;
            }
            else {
                ans++;
                tmp += r;
                b.insert(a[i]);
            }
        }
        cout << ans << endl;
    }
}