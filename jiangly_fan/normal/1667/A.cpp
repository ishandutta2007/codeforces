#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<LL> a(n);
    for (LL& ai : a) cin >> ai;
    LL ans = LLONG_MAX;
    for (int i = 0; i < n; i += 1) {
        LL pans = 0;
        for (LL j = i - 1, x = 0; j >= 0; j -= 1) {
            LL y = x / a[j] + 1;
            pans += y;
            x = a[j] * y;
        }
        for (LL j = i + 1, x = 0; j < n; j += 1) {
            LL y = x / a[j] + 1;
            pans += y;
            x = a[j] * y;
        }
        ans = min(ans, pans);
    }
    cout << ans;
}