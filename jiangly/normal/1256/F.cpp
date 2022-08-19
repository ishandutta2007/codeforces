#include <bits/stdc++.h>
using namespace std;
int calc(const string &s) {
    int result = 0, n = (int)s.length();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (s[i] < s[j])
                ++result;
    return result;
}
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnts[26] {}, cntt[26] {};
    for (char c : s)
        ++cnts[c - 'a'];
    for (char c : t)
        ++cntt[c - 'a'];
    for (int i = 0; i < 26; ++i) {
        if (cnts[i] != cntt[i]) {
            cout << "NO" << "\n";
            return;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (cnts[i] >= 2) {
            cout << "YES" << "\n";
            return;
        }
    }
    int cs = calc(s);
    int ct = calc(t);
    if ((cs - ct) % 2 == 0)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}