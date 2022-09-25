#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        if (s.back() == 'A') cout << "NO\n";
        else {
            int ok = 1, t = 0;
            for (char c : s) {
                if (c == 'A') t += 1;
                else t -= 1;
                if (t < 0) ok = 0;
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}