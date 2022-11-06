#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        s[i] = s[i - 1] + t;
    }

    if (s[n] % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    int k = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[n] * 2 / 3) k++;
    }

    int result = 0;
    for (int i = 1; i <= n - 2; i++) {
        if (s[i] == s[n] * 2 / 3) k--;
        if (3 * s[i] == s[n]) {
            result += k;
        }
    }
    cout << result << '\n';
}