#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        cnt1 += (s[i] == 'n');
    }
    for (int i = 0; i < cnt1; ++i) {
        cout << 1 << " ";
    }
    for (int i = 0; i < (n - cnt1 * 3) / 4; ++i) {
        cout << 0 << " ";
    }
    return 0;
}