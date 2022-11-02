#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            bal++;
        } else {
            bal--;
        }
        if (bal < -1) {
            cout << "No";
            return 0;
        }
    }
    if (bal != 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}