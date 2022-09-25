#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, k;
        cin >> n >> k;
        vector<LL> s(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> s[i];
            s[i] += s[i - 1];
        }
        if (k <= n) {
            LL mx = 0;
            for (int i = k; i <= n; i += 1)
                mx = max(mx, s[i] - s[i - k]);
            cout << mx + k * (k - 1) / 2 << "\n";
        }
        else cout << s[n] + (k - 1 + (k - n)) * n / 2 << "\n";
    }
    return 0;
}