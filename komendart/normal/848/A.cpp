#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int k;
    cin >> k;
    string ans;
    for (int i = 0; i < 26; ++i) {
        for (int cnt = 1; ; ++cnt) {
            if (cnt * (cnt - 1) / 2 > k) {
                --cnt;
                k -= cnt * (cnt - 1) / 2;
                ans += string(cnt, 'a' + i);
                break;
            }
        }
    }
    assert(k == 0);
    cout << ans << '\n';
}