#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s.push_back('2');
        int ans = 0;
        array<int, 2> c = {0, 0};
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            c[s[i - 1] - '0']++;
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                ans = max(ans, cnt * cnt);
                cnt = 1;
            }
        }
        ans = max(ans, c[0] * c[1]);
        cout << ans << endl;
    }
    return 0;
}