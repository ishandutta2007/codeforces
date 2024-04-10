#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        int ans = max(n - 2, 0);
        for (int i = 0; i < n; i += 1)
            for (int j = i + 1; j < n; j += 1) {
                int pans = 0;
                for (int k = 0; k < n; k += 1)
                    if ((j - i) * (a[k] - a[i]) != (k - i) * (a[j] - a[i])) pans += 1;
                ans = min(ans, pans);
            }
        cout << ans << "\n";
    }
    return 0;
}