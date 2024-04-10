#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int a[MAXN];
int b[MAXN];
int now[MAXN];

main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        now[i] = s[i] - '0';
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int t = 0; t < 1000; ++t) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (t >= b[i] && (t - b[i]) % a[i] == 0) {
                now[i] ^= 1;
            }
            res += now[i];
        }
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}