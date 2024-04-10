#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S; cin >> S;
    int s = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') s += 1;
    }
    int n = S.size() / 2 - s;
    if (n == 0) {
        cout << "YES\n"; return;
    }
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            if (n > 1) {
                S[i] = '('; --n;
            }
            else if (n == 1) {
                S[i] = ')';
                n = 0;
            }
            else if (n == 0) {
                S[i] = '(';
            }
            else S[i] = ')';
        }
    }
    s = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') s += 1;
        else s -= 1;
        if (s < 0) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";

}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}