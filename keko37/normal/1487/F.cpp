#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 55;

int n;
int dp[MAXN][MAXN * 2][MAXN * 2];
string s;

int calc (int pos, int br, int one) {
    if (pos == n + 1) return 0;
    if (dp[pos][br + MAXN][one + MAXN] != -1) return dp[pos][br + MAXN][one + MAXN];
    int c = s[pos] - '0';
    int res = 1e9;
    if (pos == n-1) br += one / 11, one -= one / 11 * 11;
    if (pos == n) br += one;
    res = min(res, calc(pos + 1, c, one) + abs(c - br) * (n + 1 - pos));
    if (pos < n) {
        res = min(res, calc(pos + 1, c-1 - 9, one - 1) + abs(c-1 - br) * (n + 1 - pos));
        res = min(res, calc(pos + 1, c+1 + 9, one + 1) + abs(c+1 - br) * (n + 1 - pos));
    }
    return dp[pos][br + MAXN][one + MAXN] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = s.size();
    s = "0" + s;
    cout << calc(0, 0, 0);
    return 0;
}