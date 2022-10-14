#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const llint INF = 1000000000000000000LL;

llint w, sol;
llint cnt[10], mx[850];
llint dp[9][850];

int main () {
    cin >> w;
    for (int i=0; i<840; i++) {
        for (int j=0; j<=8; j++) dp[j][i] = -INF;
        mx[(w - i + 840) % 840] = w - i;
    }
    dp[0][0] = 0;
    for (int i=1; i<=8; i++) {
        cin >> cnt[i];
        for (int j=0; j<840; j++) {
            llint lim = 840 / i;
            for (int k=0; k <= min(lim-1, cnt[i]); k++) {
                llint res = dp[i-1][(j - k*i%840 + 840) % 840] + k*i;
                if (res > w) continue;
                llint br = (cnt[i] - k) / lim * 840;
                if (res + br > w) {
                    res = mx[j];
                } else {
                    res += br;
                }
                dp[i][j] = max(dp[i][j], res);
            }
        }
    }
    for (int i=0; i<840; i++) {
        sol = max(sol, dp[8][i]);
    }
    cout << sol;
    return 0;
}