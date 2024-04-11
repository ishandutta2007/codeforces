#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    char c = 'a';
    for (auto i: s) {
        if (i > c) {
            cout << "NO\n";
            return 0;
        }
        if (i == c) ++c;
    }
    cout << "YES\n";
}