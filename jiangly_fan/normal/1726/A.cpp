#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i += 1)
            cin >> a[i];
        int ans = a.back() - a[0];
        for (int i = 1; i < n; i += 1)
            ans = max(ans, a[i - 1] - a[i]);
        cout << max({ans, *max_element(next(a.begin()), a.end()) - a[0], a.back() - *min_element(a.begin(), prev(a.end()))}) << "\n";
    }
}