#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 400005;
const int LIM = 20;

int n;
int a[MAXN];
int br[21][MAXN];
vector <int> v[21];
llint p[21][21];
llint dp[1 << 22];

void precompute (int x, int y) {
    llint res = 0;
    for (auto pos : v[x]) {
        res += br[y][pos];
    }
    p[x][y] = res;
}

llint calc (int mask) {
    if (__builtin_popcount(mask) == LIM) return 0;
    if (dp[mask] != -1) return dp[mask];
    llint res = 1e18;
    for (int i=1; i<=LIM; i++) {
        if (mask & (1 << i)) continue;
        llint tmp = 0;
        for (int j=1; j<=LIM; j++) {
            if ((mask & (1 << j)) || j == i) continue;
            tmp += p[i][j];
        }
        res = min(res, tmp + calc(mask | (1 << i)));
    }
    return dp[mask] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
        for (int j=1; j<=LIM; j++) {
            br[j][i] = br[j][i-1];
        }
        br[a[i]][i]++;
    }
    for (int i=1; i<=LIM; i++) {
        for (int j=1; j<=LIM; j++) {
            precompute(i, j);
        }
    }
    cout << calc(0);
    return 0;
}