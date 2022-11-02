#include <bits/stdc++.h>
using namespace std;

int get(string s) {
    int c0 = 0, c1 = 0;
    for (int i = 0; i < 10; ++i) {
        if (s[i] == '1') {
            if (i % 2 == 0) {
                c0++;
            } else {
                c1++;
            }
        }
        if (c0 + (9 - i) / 2 < c1) {
            return i + 1;
        }
        if (c1 + (10 - i) / 2 < c0) {
            return i + 1;
        }
    }
    return 10;
}

main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string s0 = s, s1 = s;
        for (int i = 0; i < 10; ++i) {
            if (s[i] == '?') {
                if (i % 2 == 0) {
                    s0[i] = '1';
                    s1[i] = '0';
                } else {
                    s0[i] = '0';
                    s1[i] = '1';
                }
            }
        }
        cout << min(get(s0), get(s1)) << endl;
    }
    return 0;
}