#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

llint q, n;
llint a[MAXN], b[MAXN];
llint dp[3][MAXN], opt[3][MAXN];

llint f (llint d) {
    if (d == 0) return 0;
    if (d == 1) return 1;
    return 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i] >> b[i];
            for (int tip = 0; tip <= 2; tip++) {
                llint h1, h2;
                if (tip == 0) h1 = a[i] + 1, h2 = a[i] + 2;
                if (tip == 1) h1 = a[i], h2 = a[i] + 2;
                if (tip == 2) h1 = a[i], h2 = a[i] + 1;
                if (opt[2][i - 1] != h1) {
                    dp[tip][i] = dp[2][i - 1] + (h1 - a[i]) * b[i];
                    opt[tip][i] = h1;
                } else {
                    llint v1 = dp[2][i - 1] + (h2 - a[i]) * b[i];
                    llint v2 = dp[f(h1 - a[i - 1])][i - 1] + (h1 - a[i]) * b[i];
                    dp[tip][i] = min(v1, v2);
                    if (v1 < v2) opt[tip][i] = h2; else opt[tip][i] = h1;
                }
            }
        }
        cout << dp[2][n] << '\n';
    }
    return 0;
}