#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') break;
        ans++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '<') break;
        ans++;
    }

    cout << ans << endl;
}