#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[205][205][205];
ll r[205], g[205], b[205];
ll dfs(ll rr, ll gg, ll bb) {
    if (dp[rr][gg][bb]) return dp[rr][gg][bb];
    ll mmax = 0;
    if (rr * gg) mmax = max(mmax, dfs(rr - 1, gg - 1, bb) + r[rr] * g[gg]);
    if (rr * bb) mmax = max(mmax, dfs(rr - 1, gg, bb - 1) + r[rr] * b[bb]);
    if (gg * bb) mmax = max(mmax, dfs(rr, gg - 1, bb - 1) + g[gg] * b[bb]);
    return dp[rr][gg][bb] = mmax;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll rr, gg, bb;
    cin >> rr >> gg >> bb;
    for (int i = 1; i <= rr; i++) cin >> r[i];
    for (int i = 1; i <= gg; i++) cin >> g[i];
    for (int i = 1; i <= bb; i++) cin >> b[i];
    sort(r + 1, r + 1 + rr);
    sort(g + 1, g + 1 + gg);
    sort(b + 1, b + 1 + bb);
    cout << dfs(rr, gg, bb);
}