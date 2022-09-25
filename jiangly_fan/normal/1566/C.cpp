#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            if (s[i] != t[i]) ans += 2;
            else if (s[i] == '0') ans += 1;
        }
        vector<int> v(n);
        for (int i = 0; i + 1 < n; i += 1)
            if (s[i] == t[i] and s[i + 1] == t[i + 1] and s[i] != s[i + 1] and v[i] == 0 and v[i + 1] == 0)
                ans += v[i] = v[i + 1] = 1;
        cout << ans << "\n";
    }
    return 0;
}