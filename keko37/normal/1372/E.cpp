#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int n, m;
int poc[MAXN], kraj[MAXN];
int lef[MAXN][MAXN], rig[MAXN][MAXN];
int dp[MAXN][MAXN];

int calc (int lo, int hi) {
    if (lo > hi) return 0;
    if (dp[lo][hi] != -1) return dp[lo][hi];
    int res = 0;
    for (int col = lo; col <= hi; col++) {
        int cnt = 0;
        for (int row = 1; row <= n; row++) {
            if (lo <= lef[row][col] && rig[row][col] <= hi) cnt++;
        }
        res = max(res, cnt * cnt + calc(lo, col - 1) + calc(col + 1, hi));
    }
    return dp[lo][hi] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a, b; cin >> a >> b;
            for (int d = a; d <= b; d++) {
                lef[i][d] = a;
                rig[i][d] = b;
            }
        }
    }
    memset(dp, -1, sizeof dp);
    cout << calc(1, m);
    return 0;
}