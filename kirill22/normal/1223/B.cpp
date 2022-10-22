#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        bool f = false;
        for (auto c : s) {
            for (auto b : t) {
                if (b == c) {
                    f = true;
                }
            }
        }
        if (f) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}