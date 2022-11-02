#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f = false;
    int need_s = 0;
    for (int i = 0; i < n - 1; ++i) {
        int sum = 0, cnt = 0;
        need_s += s[i] - '0';
        for (int j = i + 1; j < n; ++j) {
            sum += s[j] - '0';
            if (sum == need_s && j != n - 1) {
                cnt++;
                sum = 0;
            }
        }
        if (sum == need_s || (sum == 0 && cnt > 0)) {
            f = true;
            break;
        }
    }
    if (f) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}