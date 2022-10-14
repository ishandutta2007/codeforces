#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAXN = 105;

int n = 10, cnt;
int x[MAXN], y[MAXN], par[MAXN];
int a[MAXN][MAXN], col[MAXN][MAXN];
ld dp[MAXN];

void precompute () {
    for (int i = 2; i <= 6; i++) {
        for (int j = 1; j < i; j++) dp[i] += dp[j];
        dp[i] = (ld) (dp[i] + 6) / (i - 1);
    }
}

void calc (int ind) {
    ld res = 10000000000LL;
    for (int mask = 0; mask < (1 << 6); mask++) {
        ld tmp = 0;
        for (int j = 0; j < 6; j++) {
            int pos = ind - j - 1;
            if (mask & (1 << j)) tmp += dp[par[pos]]; else tmp += dp[pos];
        }
        res = min(res, tmp / 6 + 1);
    }
    dp[ind] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                cnt++;
                col[i][j] = cnt;
                x[cnt] = i; y[cnt] = j;
                par[cnt] = col[i - a[i][j]][j];
            }
        } else {
            for (int j = n-1; j >= 0; j--) {
                cnt++;
                col[i][j] = cnt;
                x[cnt] = i; y[cnt] = j;
                par[cnt] = col[i - a[i][j]][j];
            }
        }
    }
    precompute();
    for (int i = 7; i <= 100; i++) {
        calc(i);
    }
    cout << fixed << setprecision(15) << dp[100];
    return 0;
}