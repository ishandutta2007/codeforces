#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=259;
int n,m;
int a[M];
int dp[M][M][M<<1];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    memset(dp,0X3f,sizeof(dp));
    dp[0][m][m]=0;
    for(int j=m;j>=0;--j)dp[0][j][m]=min(dp[0][j+1][m],dp[0][j][m]);
    for(int i=1;i<n;++i){
        for(int j=0;j<=m;++j){
            for(int k=-m;k<=m;++k){
                int t=k+a[i]-j;
                if(t>=-m&&t<=m)dp[i][j][t+m]=min(dp[i][j][t+m],dp[i-1][j][k+m]+abs(k+a[i]-j));
            }
        }
        for(int j=m;j>=0;--j){
            for(int k=-m;k<=m;++k){
                dp[i][j][k+m]=min(dp[i][j+1][k+m],dp[i][j][k+m]);
            }
        }
    }
    int ans=1e9;
    for(int j=0;j<=m;++j){
        for(int k=-m;k<=m;++k){
            int t=a[n]+k;
            if(t>=0&&t<=j){
                ans=min(ans,dp[n-1][j][k+m]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
1 6
5
*/