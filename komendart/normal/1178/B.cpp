#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> pref(n + 2), suf(n + 2);
    for (int i = 2; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if (s[i - 1] == s[i - 2] && s[i - 1] == 'v') {
            ++pref[i];
        }
    }
    for (int i = n - 1; i > 0; --i) {
        suf[i] = suf[i + 1];
        if (s[i - 1] == s[i] && s[i] == 'v') {
            ++suf[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'o') {
            ans += pref[i] * suf[i];
        }
    }
    cout << ans << '\n';
    
}