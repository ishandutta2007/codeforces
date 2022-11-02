#include <bits/stdc++.h>
using namespace std;

main() {
    string s;
    cin >> s;
    int n = s.size();
    cout << "Mike\n";
    int mins = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] <= s[mins]) {
            mins = i;
            cout << "Mike\n";
        } else {
            cout << "Ann\n";
        }
    }
    return 0;
}