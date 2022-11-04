#include<bits/stdc++.h>
#define maxn 100
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll dp[maxn][maxn][maxn];
ll opt[maxn * 2 + 2];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    opt[0] = 0;
    for(int i = 1; i < maxn * 2 + 2; i++) {
        for(int last = 1; last <= min(i, n); last++) {
            opt[i] = max(opt[i], opt[i - last] + a[last - 1]);
        }
    }
    vi b;
    int prev = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[prev]) continue;
        b.push_back(i - prev);
        prev = i;
    }
    b.push_back(n - prev);
    int m = b.size();
    for(int len = 1; len <= m; len++) {
        for(int l = 0; l < m + 1 - len; l++) {
            int r = l + len - 1;
            for(int k = 0; k < n; k++) {
                if(l == r) {
                    dp[l][r][k] = opt[b[l] + k];
                    continue;
                }
                dp[l][r][k] = dp[l][r - 1][0] + dp[r][r][k];
                for(int j = r - 2; j >= l; j-=2) {
                    dp[l][r][k] = max(dp[l][r][k], dp[j + 1][r - 1][0] + dp[l][j][min(maxn - 1, k + b[r])]);
                }
            }
        }
    }
    cout << dp[0][m - 1][0];

}