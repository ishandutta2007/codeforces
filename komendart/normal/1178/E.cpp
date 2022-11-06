#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    string s;
    cin >> s;
    
    int n = sz(s);
    string half;
    string mid;
    for (int i = 0; ; i += 2) {
        int end = n - i - 1;
        if (end - i + 1 > 3) {
            if (s[i] == s[end] || s[i] == s[end - 1]) {
                half.push_back(s[i]);
            } else {
                half.push_back(s[i + 1]);
            }
        } else {
            if (end - i + 1 > 1) {
                mid.push_back(s[i]);
            }
            break;
        }
    }
    string ans = half + mid;
    reverse(half.begin(), half.end());
    ans += half;
    cout << ans << '\n';
}