#include<bits/stdc++.h>

using namespace std;

// fuck life

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string ans = "YES";
        for (int i = 0; i < (int) s.size(); i++) {
            if (i && s[i] == s[i - 1]) {
                continue;
            }
            if (i + 1 < (int) s.size() && s[i] == s[i + 1]) {
                continue;
            }
            ans = "NO";
        }
        cout << ans << '\n';
    }
}