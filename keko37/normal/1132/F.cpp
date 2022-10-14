#include<bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, sol = MAXN;
string s;
int dp[MAXN][MAXN];
vector <int> a;

int calc (int x, int y) {
    if (x > y) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    if (x == y) return 1;
    int res = MAXN;
    for (int i=x+1; i<=y; i++) {
        if (a[i] == a[x]) res = min(res, calc(x+1, i-1) + calc(i, y));
    }
    res = min(res, 1 + calc(x+1, y));
    dp[x][y] = res;
    return res;
}

int main () {
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (i == 0 || s[i] != s[i-1]) a.push_back(s[i] - 'a');
    }
    cout << calc(0, a.size()-1);
    return 0;
}