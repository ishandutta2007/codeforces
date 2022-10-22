#include<bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 1;
    string s;
    cin >> s;
    int n = s.size();
    char c = s[0];
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
        if (s[i] == c) {
            tmp++;
            continue;
        }
        if (c == 'n' || c == 'u') {
            int x = 0, y = 1;
            while (tmp--) {
                int z = x + y;
                x = y;
                y = z;
                x %= mod;
            y %= mod;
            }
            ans = (ans * y) % mod;
        }
        c = s[i];
        tmp = 1;
    }
     if (c == 'n' || c == 'u') {
        int x = 0, y = 1;
        while (tmp--) {
            int z = x + y;
            x = y;
            y = z;
            x %= mod;
            y %= mod;
        }
        ans = (ans * y) % mod;
    }
    cout << ans;
}