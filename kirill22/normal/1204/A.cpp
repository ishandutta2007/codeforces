#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    bool f = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            ans = (n - i + 1) / 2;
            if (!f && (i % 2 == (n - 1) % 2)) {
                ans--;
            }
            f = true;
        }
    }
    cout << ans;
}