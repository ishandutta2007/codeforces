#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-(x)))
using namespace std;
const int maxn = 505;
int C[maxn][maxn];
const int mod = 998244353;
int n, x;
int dp[maxn][maxn];
int pw[maxn][maxn];
int main(){
    memset(dp, 0, sizeof dp);
    C[0][0] = 1;
    fors(i,1,maxn){
        C[i][0] = 1;
        fors(j,1,i+1) C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
    }
    fors(i,1,maxn){
        pw[i][0] = 1;
        fors(j,1,maxn) pw[i][j] = (ll)i*pw[i][j-1]%mod;
    }
    cin>>n>>x;
    fors(i,0,x+2) dp[0][i] = 1;
    for(int len = 2; len <= n; ++len){

        int c = len-1;
        for(int d = 1; d <= x; ++d){
            for(int i = 1; i < len; ++i){
                for(int cur = c; cur <= d; cur += c) {
                    dp[len][d] = (dp[len][d] + C[len][i]*(ll)pw[c][i]%mod * dp[len-i][d-cur])%mod;
                }
            }
//            cout<<"?"<<dp[len][d]<<endl;
            for(int cur = c; cur < d; cur += c){
                dp[len][d] = (dp[len][d] + pw[c][len])%mod;
            }
//            cout<<"?"<<dp[len][d]<<endl;
            int t = (d-1)/c;
            int u = t*c;
            dp[len][d] = (dp[len][d] + pw[d-u][len])%mod;
//            cout<<"len:"<<len<<" d:"<<d<<" dp:"<<dp[len][d]<<endl;
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}