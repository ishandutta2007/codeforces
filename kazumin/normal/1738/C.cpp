#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 105;

int n, a[MN], t, dp[MN][MN][2][2][2]; //evs, odds, a parity, b parity, whose turn = does alice win?

int rec(int e, int o, int pa, int pb, int t) {
    if (dp[e][o][pa][pb][t] != -1) return dp[e][o][pa][pb][t];
    if (e == 0 && o == 0) return dp[e][o][pa][pb][t] = !pa;
    if (!t) {
        int ret = 0;
        if (e) ret |= rec(e - 1, o, pa, pb, t ^ 1);
        if (o) ret |= rec(e, o - 1, pa ^ 1, pb, t ^ 1);
        return dp[e][o][pa][pb][t] = ret;
    } else {
        int ret = 1;
        if (e) ret &= rec(e - 1, o, pa, pb, t ^ 1);
        if (o) ret &= rec(e, o - 1, pa, pb ^ 1, t ^ 1);
        return dp[e][o][pa][pb][t] = ret;
    }
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        int e = 0, o = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2) o++;
            else e++;
        }
        memset(dp, -1, sizeof(dp));
        if (rec(e, o, 0, 0, 0)) printf("Alice\n");
        else printf("Bob\n");
    }

    return 0;
}