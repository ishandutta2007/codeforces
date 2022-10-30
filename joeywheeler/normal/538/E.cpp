#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> c[200005];
int n;

int dp[200005][2];
int m;

void go(int x, int t, int d=1) {
    bool leaf = true;
    for (int j : c[x]) {
        leaf = false;
        go(j, t, d+1);
    }
    if (leaf) {
        dp[x][t] = 1;
        m++;
    } else {
        if (t == (d&1)) {
            dp[x][t] = 1e9;
            for (int j : c[x]) {
                dp[x][t] = min(dp[x][t], dp[j][t]);
            }
        } else {
            dp[x][t] = 0;
            for (int j : c[x]) {
                dp[x][t] += dp[j][t];
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n-1) {
        int u, v; scanf("%d%d", &u, &v);
        c[u].push_back(v);
    }
    go(1,0); go(1,1);
    m /= 2;
    printf("%d %d\n", m-dp[1][1]+1, dp[1][0]);
}