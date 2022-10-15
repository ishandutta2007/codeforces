#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e2 + 3;
const int mod = 1e8;

int n1, n2, k1, k2;
int dp[maxn][maxn][2];

int add(const int &a, const int &b){
    return (a + b > mod ? a + b - mod : a + b);
}

int DP(int i1, int i2, bool turn){
    if(i1 < 0 || i2 < 0) return 0;
    if(i1 == 0 && i2 == 0) return 1;

    int &res = dp[i1][i2][turn];
    if(res != -1) return res;
    res = 0;

    if(!turn) for(int i = 1; i <= k1; ++i)
        res = add(res, DP(i1 - i, i2, !turn));
    else for(int i = 1; i <= k2; ++i)
        res = add(res, DP(i1, i2 - i, !turn));

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j) dp[i][j][0] = dp[i][j][1] = -1;

    cin >> n1 >> n2 >> k1 >> k2;
    cout << add(DP(n1, n2, 0), DP(n1, n2, 1));
}