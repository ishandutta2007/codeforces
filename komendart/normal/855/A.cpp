#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    set<string> d;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (d.count(s)) cout << "YES\n";
        else cout << "NO\n";
        d.insert(s);
    }
}