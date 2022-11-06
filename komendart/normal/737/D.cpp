#include <bits/stdc++.h>

using namespace std;

const int maxw = 5e7;
const int maxn = 4005;
const int maxk = 90;
const int INF = 1e9;

int n;
int a[maxn];
int pref[maxn];

int dp[maxw];
char used[maxw];

int solve(int l, int r, int k, int turn) {
    int state = turn + 2LL * l + 2LL * 3000 * (r - l + 1) + 2LL * 3000 * 90 * k;
    if (used[state]) {
        return dp[state];
    }
    used[state] = true;
    if (turn) {
        int val1 = (l + k <= r + 1 ) ? solve(l + k, r, k, !turn): -INF;
        int val2 = (l + k + 1 <= r + 1) ? solve(l + k + 1, r, k + 1, !turn): -INF;
        if (val1 == -INF && val2 == -INF) val1 = pref[l - 1] - (pref[n] - pref[r]);
        return dp[state] = max(val1, val2);
    } else {
        int val1 = (l + k <= r + 1) ? solve(l, r - k, k, !turn): INF;
        int val2 = (l + k + 1 <= r + 1) ? solve(l, r - (k + 1), k + 1, !turn): INF;
        if (val1 == INF && val2 == INF) val1 = pref[l - 1] - (pref[n] - pref[r]);
        return dp[state] = min(val1, val2);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    cout << solve(1, n, 1, 1) << '\n';
}