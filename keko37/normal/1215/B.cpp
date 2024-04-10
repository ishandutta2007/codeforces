#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n, x, y;
llint a[MAXN], dp[2][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        dp[0][i] = dp[0][i-1];
        dp[1][i] = dp[1][i-1];
        if (a[i] < 0) swap(dp[0][i], dp[1][i]);
        if (a[i] > 0) dp[0][i]++; else dp[1][i]++;
        x += dp[0][i];
        y += dp[1][i];
    }
    cout << y << " " << x;
    return 0;
}