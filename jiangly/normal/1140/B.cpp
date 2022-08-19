#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0, j = 0;
    while (i < n && s[i] == '<')
        ++i;
    while (j < n && s[n - j - 1] == '>')
        ++j;
    cout << min(i, j) << "\n";
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