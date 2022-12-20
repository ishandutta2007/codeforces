#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 512;
const int mod = 998244353;
int a[N];
long long dp[N][N];

long long f(int l, int r) {
    if (l > r)
        dp[l][r] = 1;
    if (dp[l][r] == -1) {
        dp[l][r] = 0;
        int num = l, i, j;
        for (i = l; i <= r; ++i)
        if (a[i] < a[num])
            num = i;
        long long l1 = 0, r1 = 0;
        for (i = l; i <= num; ++i)
            l1 = (l1 + f(l, i - 1) * f(i, num - 1)) % mod;
        for (j = num; j <= r; ++j)
            r1 = (r1 + f(num + 1, j) * f(j + 1, r)) % mod;
        dp[l][r] = (l1 * r1) % mod;
    }
    return dp[l][r];
}

int main() {
    int i, j, k, n, w, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
        dp[i][j] = -1;
    cout << f(1, n);
}