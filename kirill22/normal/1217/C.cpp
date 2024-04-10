#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans++;
            }
            if (i < n - 1 && s[i] == '1' && s[i + 1] == '0') {
                ans++;
            }
        }
        int tmp = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                tmp = i;
            }
            else {
                if (tmp != n) {
                    int t = 1, t2 = tmp - i + 1;
                    for (int j = tmp + 1; j < min(n, tmp + 30); j++) {
                        t *= 2;
                        t2++;
                        if (s[j] == '1') {
                            t++;
                        }
                        if (t == t2) {
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}