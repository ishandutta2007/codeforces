#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = s.size();
        sort(s.begin(), s.end());
        if (s[0] == s[n - 1]) {
            for (int i = 0; i < 2 * n; i++) cout << s[0];
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << "10";
            }
        }
        cout << endl;
    }
}