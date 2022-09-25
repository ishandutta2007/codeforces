#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<LL> dp[2][14];
char s[14][15];
int Log[1 << 14];
LL ans[1 << 13];
vector<int> v[15];
int iv[1 << 14];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1) cin >> s[i];
    int full = (1 << n) - 1;
    for(int i = 2; i < (1 << n); i += 1) Log[i] = Log[i >> 1] + 1;
    for(int mask = 1; mask < (1 << n); mask += 1){
        iv[mask] = v[__builtin_popcount(mask)].size();
        v[__builtin_popcount(mask)].push_back(mask);
    }
    for(int i = 0; i < n; i += 1) dp[1][i].resize(v[1].size());
    for(int i = 0; i < n; i += 1) dp[1][i][iv[1 << i]] = 1;
    for(int i = 1; i < n; i += 1){
        int u = i & 1, vv = u ^ 1;
        for(int j = 0; j < n; j += 1) dp[vv][j].resize(v[i + 1].size() << i);
        for(int j = 0; j < n; j += 1){
            for(int k = 0; k < (int)dp[u][j].size(); k += 1){
                int mask = v[i][k >> (i - 1)], ksam = k & ((1 << (i - 1)) - 1);
                for(int c = full ^ mask; c; c -= c & -c){
                    int d = Log[c & -c];
                    //cout << u << " " << i << " " << k << " " << dp[u][i][k] << endl;
                    //cout << vv << " " << d << " " << ((iv[mask | (1 << d)] << i) | (ksam << 1) | (s[j][d] - '0')) << endl;
                    dp[vv][d][(iv[mask | (1 << d)] << i) | (ksam << 1) | (s[j][d] - '0')] += dp[u][j][k];
                }
            }
            dp[u][j].clear(); 
        }
    }
    for(int i = 0; i < n; i += 1)
        for(int k = 0; k < (1 << (n - 1)); k += 1) ans[k] += dp[n & 1][i][k];
    for(int i = 0; i < (1 << (n - 1)); i += 1) cout << ans[i] << " ";
    return 0;
}