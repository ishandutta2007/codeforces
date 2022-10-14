#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 2005;
const llint INF = 1000000000000000000LL;

llint n, k;
llint lef[MAXN], rig[MAXN], a[MAXN];
llint dp[MAXN][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> lef[i] >> rig[i] >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int tip = 0; tip < 2; tip++) {
            llint res = INF;
            llint pos = lef[i] + tip, curr = k, spent = 0;
            for (int j = i; j <= n; j++) {
                llint m = (a[j] - curr + k - 1) / k;
                if (pos + m > rig[j]) break;
                spent += a[j];
                curr = curr + m * k - a[j];
                if (j == n) {
                    res = min(res, spent);
                } else if (pos + m + 1 <= lef[j + 1]) {
                    res = min(res, spent + curr + dp[j + 1][0]);
                } else {
                    res = min(res, spent + curr + dp[j + 1][1]);
                }
                pos += m;
                if (curr == 0) {
                    curr = k;
                    pos++;
                }
                pos = max(pos, lef[j + 1]);
            }
            dp[i][tip] = res;
        }
    }
    if (dp[1][0] >= INF) cout << -1; else cout << dp[1][0];
    return 0;
}