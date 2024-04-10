#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,a[110000],v[110000][8],pc[128],p[110000]; ll dp[110000][128];
bool cmp(int x,int y){ return a[x]>a[y];}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&v[i][j]);
    sort(p+1,p+n+1,cmp);
    int upperlim=(1<<m)-1;
    for (int s=1;s<=upperlim;s++) pc[s]=pc[s>>1]+(s&1);
    memset(dp,0xcf,sizeof(dp));
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int s=0;s<=upperlim;s++){
            dp[i][s]=dp[i-1][s]+(i-pc[s]<=k?a[p[i]]:0);
            for (int j=1;j<=m;j++)
                if (s&(1<<(j-1))) dp[i][s]=max(dp[i][s],dp[i-1][s^(1<<(j-1))]+v[p[i]][j]);
        }
    printf("%lld\n",dp[n][upperlim]);
    return 0;
}