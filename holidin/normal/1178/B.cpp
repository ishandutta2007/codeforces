#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e6 + 1;
const int mod = 998244353;
vector <int> ans;
int a[N];
long long dp[5][N];
string s;

int main() {
    int i, j, k, n, w, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    dp[0][0] = 1;
    for (i = 0; i < s.size(); ++i) {
        for (j = 0; j < 4; ++j)
            dp[j][i + 1] += dp[j][i];
        if (i < s.size() - 1 && s[i] == s[i + 1] && s[i] == 'v') {
            dp[1][i + 2] += dp[0][i];
            dp[3][i + 2] += dp[2][i];
        }
        if (s[i] == 'o')
            dp[2][i + 1] += dp[1][i];
    }
    cout << dp[3][s.size()];
}