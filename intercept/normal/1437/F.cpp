#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=5009;
int n;
int a[M],c[M],d[M],cnt[M];
int dp[M][M];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],c[i]=a[i];
    sort(c+1,c+n+1);
    int m=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(a[j]*2<=c[i])d[i]++;
            if(a[j]==c[i])cnt[i]++;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        int sum=0;
        for(int j=1,l=0;j<=m;++j){
            while(c[l]*2<=c[j])sum=(sum+dp[i-1][l])%mod,l++;
            dp[i][j]=1ll*sum*cnt[j]%mod;
            if(d[j]>=i-2){
                dp[i][j]=(dp[i][j]+1ll*dp[i-1][j]*(d[j]-(i-2))%mod)%mod;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
/*
3
1 1 2

*/