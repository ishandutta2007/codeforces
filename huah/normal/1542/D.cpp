#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=505,mod=998244353;
int n,tot,x[N],hs[N],rk[N],vis[N];
int dp[N][N][2];
int Dp(int y)
{
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;k<=1;k++)
        {
            dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%mod;
            if(rk[i+1]) dp[i+1][j+(rk[i+1]<y)][k|(rk[i+1]==y)]=(dp[i+1][j+(rk[i+1]<y)][k|(rk[i+1]==y)]+dp[i][j][k])%mod;
            else
            {
                if(j!=0||k!=1)
                    dp[i+1][max(0,j-1)][k]=(dp[i+1][max(0,j-1)][k]+dp[i][j][k])%mod;
            }
        }
    int ans=0;
    for(int j=0;j<=n;j++) ans=(ans+dp[n][j][1])%mod;
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='+') scanf("%d",&x[i]),hs[++tot]=x[i];
    }
    sort(hs+1,hs+1+tot);
    for(int i=1;i<=n;i++)
        if(x[i]) x[i]=lower_bound(hs+1,hs+1+tot,x[i])-hs,vis[x[i]]++;
    for(int i=1;i<=tot;i++) vis[i]+=vis[i-1];
    for(int i=n;i>=1;i--)
        if(x[i]) rk[i]=vis[x[i]]--;
    ll ans=0;
    for(int i=1;i<=n;i++)
        if(x[i]) ans=(ans+1ll*hs[x[i]]*Dp(rk[i])%mod)%mod;
    printf("%lld\n",ans);
}