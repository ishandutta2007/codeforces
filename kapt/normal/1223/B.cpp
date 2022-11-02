#include <bits/stdc++.h>
using namespace std;

main() {
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        set<char> ss;
        for (auto elem : s) {
            ss.insert(elem);
        }
        bool f = false;
        for (auto elem : t) {
            if (ss.count(elem)) {
                cout << "YES\n";
                f = true;
                break;
            }
        }
        if (!f) {
            cout << "NO\n";
        }
    }
    return 0;
}