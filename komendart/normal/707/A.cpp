#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        string s; cin >> s;
        if (s == "C" || s == "M" || s == "Y") {
            cout << "#Color\n";
            return 0;
        }
    }
    cout << "#Black&White\n";
}