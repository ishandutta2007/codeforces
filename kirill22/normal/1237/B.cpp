#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> A(n), b(n);
    vector<pair<int, int>> a(n + 1, {-10000, -1000});
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        a[A[i]].first = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[b[i]].second = i;
    }
    sort(a.begin(), a.end());
    int ans = 0, mx = -100;
    for (int i = 1; i <= n; i++) {
        if (a[i].second < mx) {
            ans++;
        }
        mx = max(mx, a[i].second);
    }
    cout << ans;

}