#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1E3;
int n;
int a[MAX_N];
int p[MAX_N];
int dp[MAX_N + 1][1 << 8];
vector<int> pos[8];
int work(int x) {
    memset(dp, 0xB0, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << 8); ++mask) {
            dp[i + 1][mask] = dp[i][mask];
            if (mask >> a[i] & 1) {
                if (p[i] >= x - 1)
                    dp[i + 1][mask] = max(dp[i + 1][mask], dp[pos[a[i]][p[i] - x + 1]][mask ^ 1 << a[i]] + x);
                if (p[i] >= x)
                    dp[i + 1][mask] = max(dp[i + 1][mask], dp[pos[a[i]][p[i] - x]][mask ^ 1 << a[i]] + x + 1);
            }
        }
    }
    return dp[n][255];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        p[i] = pos[a[i]].size();
        pos[a[i]].push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < 8; ++i)
        cnt += !pos[i].empty();
    if (cnt < 8) {
        cout << cnt << "\n";
        return 0;
    }
    int l = 1, r = n / 8;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (work(mid) > 0)
            l = mid;
        else
            r = mid - 1;
    }
    cout << work(l) << "\n";
    return 0;
}