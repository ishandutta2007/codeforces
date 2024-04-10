#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

int n, m, ans;
std::string s, t;

int main() {
    for (int T = read(); T; T--) {
        m = read(); std::cin >> s;
        for (int i = 0; i < s.size(); i++) { s[i]--; }
        ans = s.size(); t = s;
        for (int i = 1; i <= m; i++) {
            int tmp = (ans + mod - i) % mod, x = t[i - 1] - '0';
            if (x == 0) {
                continue;
            } else if (x == 1) {
                ans += tmp; ans %= mod;
                int len = t.size();
                for (int j = i; j < len; j++) {
                    if (t.size() > m + 5) { break; }
                    t += t[j];
                }
            } else {
                ans += tmp; ans %= mod;
                ans += tmp; ans %= mod;
                int len = t.size();
                for (int j = i; j < len; j++) {
                    if (t.size() > m + 5) { break; }
                    t += t[j];
                }
                for (int j = i; j < len; j++) {
                    if (t.size() > m + 5) { break; }
                    t += t[j];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}