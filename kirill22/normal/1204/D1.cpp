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
    for (int i = 0; i < n; i++) {
        int ans1 = 0, ans2 = 0, ansi = 0;
        for (int j = i; j >= 0; j--) {
            if (s[j] == '1') {
                ans1++;
            }
            else {
                ans2++;
            }
            int tmp = max(ans2, ans1);
            if (tmp == ansi) {
                ans[j] = '1';
            }
            ansi = tmp;
            ans2 = tmp;
        }
    }
    cout << ans;
}