#include <cstring>
#include <iostream>
#define int long long
using namespace std;
int dp[100005][2];
inline int f2(int x) {
    if (x == 0) return -1;
    int cnt = 0, X = x;
    while (x % 2 == 0) x >>= 1, ++cnt;
    if (cnt & 1)
        return ((int)1 << (int)cnt);
    else
        return f2(X - ((int)1 << (int)cnt));
}
inline int cal2(int y, int x) {
    int now = f2(x), qwq = 1;
    if (x == 1) return 0;
    if (now == -1 && y == 1) return 0;
    if (now == -1 && y == 2) return 1;
    int t = 1;
    while (x / t > 2) t <<= 1;
    if (f2(x) == -1) now = t;
    if (y <= x / now) return y & 1;
    while (y > x / now) now >>= 1, qwq ^= 1;
    return (y % 2 == 0) && qwq;
}
inline int f(int x) {
    if (x == 0) return -1;
    int cnt = 0, X = x;
    while (x % 2 == 0) x >>= 1, ++cnt;
    if (cnt & 1)
        return f(X - ((int)1 << (int)cnt));
    else
        return ((int)1 << (int)cnt);
}
inline int cal(int y, int x) {
    int now = f(x), qwq = 1;
    if (x == 1) return 1;
    if (now == -1 && y == 1) return 0;
    if (now == -1 && y == 2) return 1;
    int t = 1;
    while (x / t > 2) t <<= 1;
    if (f(x) == -1) now = t;
    if (y <= x / now) return y & 1;
    while (y > x / now) now >>= 1, qwq ^= 1;
    return (y % 2 == 0) && qwq;
}
pair<int, int> a[100005], b[100005];
signed main(int argc, char** argv) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        b[i] = {cal(a[i].first, a[i].second) ^ 1,
                cal2(a[i].first, a[i].second) ^ 1};
    }
    dp[n][b[n].first] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i][b[i].first] |= dp[i + 1][0];
        dp[i][b[i].second] |= dp[i + 1][1];
    }
    cout << dp[1][1] << " ";
    memset(dp, 0, sizeof dp);
    dp[n][b[n].second] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i][b[i].first] |= dp[i + 1][0];
        dp[i][b[i].second] |= dp[i + 1][1];
    }
    cout << dp[1][1];
    return 0;
}