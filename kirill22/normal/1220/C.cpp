#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    char c = 'z' + 1;
    for (int i = 0; i < n; i++) {
        if (s[i] <= c) {
            cout << "Mike" << endl;
        }
        else {
            cout << "Ann" << endl;
        }
        c = min(c, s[i]);
    }
}