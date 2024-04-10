#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    vector<int> d;
    int l = -1;
    bool f = true;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            f = false;
            k--;
            ans += 2;
            if (l == -1) {
                l = i;
                continue;
            }
            d.push_back(i - l - 1);
            l = i;
        }
    }
    if (f) {
        cout << 0;
        return 0;
    }
    if (k < 0) {
        cout << -1; return 0;
    }
    int z = n - l - 1;
    int ans2 = ans;
    int k2 = k;

    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        if (k >= d[i]) {
            ans -= 2;
            k -= d[i];
        }
    }
    if (k2 >= z) {
        k2 -= z;
        ans2--;
        sort(d.begin(), d.end());
        for (int i = 0; i < d.size(); i++) {
            if (k2 >= d[i]) {
                ans2 -= 2;
                k2 -= d[i];
            }
        }
    }
    cout << min(ans, ans2);
}