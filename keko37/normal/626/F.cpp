#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 205;
const int MOD = 1000000007;

int n, k;
int a[MAXN], dp[MAXN] [MAXN] [1005];

llint f (int x, int y, int s) {
    //cout << "bla " << x << " " << y << " " << s << endl;
    if (s > k || y < 0) return 0;
    if (x == n+1) return (y == 0);
    if (dp[x] [y] [s] != -1) return dp[x] [y] [s];
    llint res = 0;
    res += f(x+1, y, s + (a[x] - a[x-1])*y) * (y + 1);
    res += f(x+1, y+1, s + (a[x] - a[x-1])*y) * (y + 1);
    res += f(x+1, y-1, s + (a[x] - a[x-1])*y);
    res %= MOD;
    dp[x] [y] [s] = res;
    return res;
}

int main () {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    cout << f(1, 0, 0);
    return 0;
}