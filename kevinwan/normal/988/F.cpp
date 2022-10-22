#include<bits/stdc++.h>
using namespace std;
#define lastof(v) v[v.size()-1]
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
const int mn=2e3+10;
int ra[mn];
int p[mn],w[mn];
int dp[mn][mn];
int main(){
    int a,n,m;
    scanf("%d%d%d",&a,&n,&m);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        ra[l]++,ra[r]--;
    }
    for(int i=1;i<a;i++)ra[i]+=ra[i-1];
    for(int i=1;i<=m;i++){
        scanf("%d%d",p+i,w+i);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<=a;i++){
        int bes=0x3f3f3f3f;
        for(int j=0;j<=m;j++)bes=min(bes,dp[i][j]);
        dp[i][0]=bes;
        for(int j=1;j<=m;j++)if(p[j]==i)dp[i][j]=bes;
        if(!ra[i])dp[i+1][0]=dp[i][0];
        for(int j=1;j<=m;j++)dp[i+1][j]=dp[i][j]+w[j];
    }
    printf("%d",dp[a][0]==0x3f3f3f3f?-1:dp[a][0]);
}