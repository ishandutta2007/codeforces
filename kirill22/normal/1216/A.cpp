#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            ans++;
            if (s[i] == 'a') {
                s[i] = 'b';
            }
            else {
                s[i] = 'a';
            }
        }
    }
    cout << ans << endl << s;
}
//gg