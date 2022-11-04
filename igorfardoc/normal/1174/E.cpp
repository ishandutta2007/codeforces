#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int p2[21];
int p3[14];
int n;

int f(int x, int y) {
    return n / ((ll)p2[x] * p3[y]);
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    p2[0] = 1;
    p3[0] = 1;
    int x = 0;
    for(int i = 1; i < 21; i++) {
        p2[i] = 2 * p2[i - 1];
        if(p2[i] <= n) x = i;
    }
    for(int i = 1; i < 14; i++) {
        p3[i] = 3 * p3[i - 1];
    }
    ll am = 0;
    vvi dp(x + 1, vi(2, 0));
    dp[x][0] = 1;
    if((ll)p2[x - 1] * 3 <= n) dp[x - 1][1] = 1;
    for(int i = 1; i < n; i++) {
        while(dp[dp.size() - 1][0] == 0) dp.pop_back();
        auto dp1 = dp;
        for(int j = 0; j < dp.size(); j++) {
            for(int k = 0; k < dp[j].size(); k++) {
                dp1[j][k] = 0;
            }
        }
        for(int j = 0; j < dp.size(); j++) {
            for(int k = 0; k < dp[j].size(); k++) {
                //cout << j << ' ' << k << endl;
                dp1[j][k] = (dp1[j][k] + (ll)dp[j][k] * (f(j, k) - i)) % mod;
                //cout << 2 << endl;
                if(j != 0) {
                    dp1[j - 1][k] = (dp1[j - 1][k] + (ll)dp[j][k] * (f(j - 1, k) - f(j, k))) % mod;
                }
                if(k != 0) {
                    dp1[j][k - 1] = (dp1[j][k - 1] + (ll)dp[j][k] * (f(j, k - 1) - f(j, k))) % mod;
                }
                ++am;
            }
        }
        dp = dp1;
    }
    cout << dp[0][0];
}