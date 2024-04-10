#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int i = 0;
    while (i < n && s[i] == t[i])
        ++i;
    int j = i + 1;
    while (j < n && s[j] == t[j])
        ++j;
    int k = j + 1;
    while (k < n && s[k] == t[k])
        ++k;
    if (s[i] == s[j] && t[i] == t[j] && k >= n)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
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