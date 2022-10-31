#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 80+2;
const int INF = 1e9+7;
int dp[2][N][N*2][N*N/2],pref[N],A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        pref[i] = pref[i-1]+1-A[i];
    }
    for(int i = 0;i<N;++i){
        for(int j = 0;j<N*2;++j){
            for(int k = 0;k<N*N/2;++k){
                dp[1][i][j][k] = dp[0][i][j][k] = -INF;
            }
        }
    }
    dp[0][0][n][0] = 0;
    int t = 0;
    for(int pos = 0;pos<n;++pos){
        for(int zero1 = 0;zero1<=pos;++zero1){
            for(int dif = n+pos;dif>=n-pos && pref[pos]+(dif-n)-zero1>=0;--dif){
                for(int k = 0;k<=pos*(pos+1)/2;++k){
                    if (dp[t][zero1][dif][k]<0)
                        continue;
                    if (A[pos+1]==1){
                        dp[t^1][0][dif][k+abs(dif-n)] = max(dp[t^1][0][dif][k+abs(dif-n)],dp[t^0][zero1][dif][k]);
                        dp[t^1][zero1+1][dif+1][k+abs(dif+1-n)] = max(dp[t^1][zero1+1][dif+1][k+abs(dif+1-n)],dp[t^0][zero1][dif][k]+(pref[pos]+(dif-n)-zero1));
                    }
                    else{
                        dp[t^1][0][dif-1][k+abs(dif-1-n)] = max(dp[t^1][0][dif-1][k+abs(dif-1-n)],dp[t^0][zero1][dif][k]);
                        dp[t^1][zero1+1][dif][k+abs(dif-n)] = max(dp[t^1][zero1+1][dif][k+abs(dif-n)],dp[t^0][zero1][dif][k]+(pref[pos]+(dif-n)-zero1));
                    }
                }
            }
        }
        t^=1;
        for(int zero1 = 0;zero1<=pos;++zero1){
            for(int dif = n+pos;dif>=n-pos && pref[pos]+(dif-n)-zero1>=0;--dif){
                for(int k = 0;k<=pos*(pos+1)/2;++k){
                    dp[t^1][zero1][dif][k] = -INF;
                }
            }
        }
    }
    int prev = 0;
    for(int k = 0;k<=n*(n-1)/2;++k){
        int res = 0;
        for(int zero1 = 0;zero1<=n;++zero1){
            res = max(res,dp[t][zero1][n][k]);
        }
        prev = max(prev,res);
        cout<<prev<<' ';
    }
    cout<<endl;

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();

    return 0;
}