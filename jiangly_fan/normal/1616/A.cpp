#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        vector<int> c(100 + 1);
        int n;
        cin >> n;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            c[abs(a)] += 1;
        }
        int ans = 0;
        for (int i = 0; i <= 100; i += 1) {
            ans += min(c[i], i ? 2 : 1);
        }
        cout << ans << "\n";
    }
    return 0;
}