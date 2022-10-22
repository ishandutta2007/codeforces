#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 1; i < (int) s.size(); i++) {
            if (s[i] == s[i - 1] || (i >= 2 && s[i] == s[i - 2])) {
                ans++, s[i] = 'A';
            }
        }
        cout << ans << '\n';
    }
}