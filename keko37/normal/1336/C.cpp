#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 3005;
const int MOD = 998244353;

int n, m, sol;
string s, t;
int dp[MAXN][MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}

int f (int a, int b) {
    if (a > b) return 1;
    if (dp[a][b] != -1) return dp[a][b];
    int res = 0;
    int ind = b - a;
    if (a >= m || s[ind] == t[a]) res = add(res, f(a + 1, b));
    if (b >= m || s[ind] == t[b]) res = add(res, f(a, b - 1));
    return dp[a][b] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> s >> t;
    n = s.size(); m = t.size();
    for (int i = m - 1; i <= n - 1; i++) sol = add(sol, f(0, i));
    cout << sol;
    return 0;
}