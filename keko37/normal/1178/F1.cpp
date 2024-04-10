#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 505;
const int MOD = 998244353;

int n, m;
int c[MAXN];
int pos[MAXN][MAXN], dp[2][MAXN][MAXN];

void precompute () {
    for (int i=1; i<=n; i++) {
        pos[i][i] = i;
        for (int j=i+1; j<=n; j++) {
            pos[i][j] = pos[i][j-1];
            if (c[pos[i][j-1]] > c[j]) pos[i][j] = j;
        }
    }
}

int calc (int tip, int a, int b) {
    if (a > b) return 1;
    if (a == b) return 1;
    if (dp[tip][a][b] != -1) return dp[tip][a][b];
    int res = 0;
    if (tip == 0) {
        res = calc(1, a, pos[a][b] - 1) * 1LL * calc(1, pos[a][b] + 1, b) % MOD;
    } else {
        res = calc(0, a, b);
        for (int k = a+1; k <= b; k++) {
            res += calc(1, a, k - 1) * 1LL * calc(0, k, b) % MOD;
            if (res >= MOD) res -= MOD;
        }
    }
    dp[tip][a][b] = res;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    precompute();
    cout << calc(1, 1, n);
    return 0;
}