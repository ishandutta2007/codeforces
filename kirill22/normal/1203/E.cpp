#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int tmp = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    tmp = max(1ll, a[0] - 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - 1 > tmp) {
            tmp = a[i] - 1;
            ans++;
        }
        else if (a[i] > tmp) {
            tmp = a[i];
            ans++;
        }
        else if (a[i] + 1 > tmp) {
            tmp = a[i] + 1;
            ans++;
        }
    }
    cout << ans;
}