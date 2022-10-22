#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n  = s.size();
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += '0';
    }
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '1') {
                b[0] = 1;
            }
            else {
                b[0] = -1;
            }
        }
        else {
            b[i] = b[i - 1];
            if (s[i] == '1') {
                b[i] += 1;
            }
            else {
                b[i] += -1;
            }
        }
    }
    int tmp = 0;
    vector<int> mn(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            mn[i] = b[i];
        }
        else {
            mn[i] = min(mn[i + 1], b[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            tmp += -1;
        }
        else {
            tmp -= -1;
        }
        if (s[i] == '1' && i != n - 1) {
            int k = tmp + mn[i + 1];
            if (k < 0) {
                ans[i] = '1';
            }
        }
    }
    cout << ans;
}