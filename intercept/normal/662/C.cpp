#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m;
int p[M],dp[1<<20][21],d[2][21];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=1;j<=m;++j){
            int x;
            scanf("%1d",&x);
            p[j]|=x<<i;
        }
    }
    for(int i=1;i<=m;++i){
        dp[p[i]][0]++;
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<1<<n;i+=1<<(k+1)){
            for(int j=i;j<i+(1<<k);++j){
                for(int t=0;t<=n;++t){
                    d[0][t]=dp[j][t];
                    d[1][t]=dp[j+(1<<k)][t];
                }
                for(int t=0;t<=n;++t){
                    dp[j][t]=d[0][t];
                    if(t)dp[j][t]+=d[1][t-1];
                    dp[j+(1<<k)][t]=d[1][t];
                    if(t)dp[j+(1<<k)][t]+=d[0][t-1];
                }
            }
        }
    }
    int ans=n*m;
    for(int i=0;i<1<<n;++i){
        int sum=0;
        for(int k=0;k<=n/2;++k){
            sum+=dp[i][k]*k;
        }
        for(int k=n/2+1;k<=n;++k){
            sum+=dp[i][k]*(n-k);
        }
        ans=min(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}