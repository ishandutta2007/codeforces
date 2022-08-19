// luogu
#include <bits/stdc++.h>
using namespace std;
constexpr int P = 1'000'000'007;
void solve() {
    string s;
    int x;
    cin >> x >> s;
    int len = s.length();
    for (int i = 0; i < x; ++i) {
        len = 1LL * (len - 1 + P) * (s[i] - '0') % P;
        if (s[i] == '1')
            continue;
        string t = s.substr(i + 1, min(x - s.length(), s.length() - i - 1));
        for (int j = 1; j < s[i] - '0'; ++j)
            s += t;
        if (s.length() > x)
            s.resize(x);
    }
    cout << (x + len) % P << "\n";
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