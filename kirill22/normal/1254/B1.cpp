#include<bits/stdc++.h>

using namespace std;

#define int long long

int ans = 1e18;

void upd(vector<int>& a, int k) {
    int res = 0;
    for (auto x : a) res += min(x % k, k - x % k);
    ans = min(ans, res);
}


signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) s[i] = a[i];
        else s[i] = s[i - 1] + a[i];
    }
    int k = s[n - 1];
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            upd(s, i);
        }
        while (k % i == 0) k /= i;
    }
    if (k > 1) upd(s, k);
    if (ans < 1e18) cout << ans;
    else cout << -1;
}