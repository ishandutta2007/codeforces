#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define yes cout << "YES\n";
#define no cout << "NO\n";

void get(string &s, int j) {
    if (s[j] == '1') {
        s[j] = '2';
    }
    else s[j] = '1';
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int l[n + 1][26], r[n + 1][26];
        for (int i = 0; i < 26; i++) {
            l[0][i] = 0;
            r[n][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                l[i + 1][j] = l[i][j];
            }
            l[i + 1][a[i] - 1]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                r[i][j] = r[i + 1][j];
            }
            r[i][a[i] - 1]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mx = 0, mx2 = 0;
                for (int k = 0; k < 26; k++) {
                    mx2 = max(mx2, 2 * min(l[i][k], r[j + 1][k]));
                }
                for (int k = 0; k < 26; k++) {
                    mx = max(mx, l[j + 1][k] - l[i][k]);
                }
                ans = max(ans, mx + mx2);
            }
        }
        cout << ans << '\n';
    }
}