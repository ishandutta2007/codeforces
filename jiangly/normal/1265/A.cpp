#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (i > 0 && s[i] == s[i - 1]) {
            cout << -1 << "\n";
            return;
        }
        if (s[i] != '?')
            continue;
        if ((i == 0 || s[i - 1] != 'a') && (i == s.length() - 1 || s[i + 1] != 'a'))
            s[i] = 'a';
        else if ((i == 0 || s[i - 1] != 'b') && (i == s.length() - 1 || s[i + 1] != 'b'))
            s[i] = 'b';
        else
            s[i] = 'c';
    }
    cout << s << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}