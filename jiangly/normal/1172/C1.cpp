#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005,P=998244353,MAXM=3005;
int n,m;
int a[MAXN],w[MAXN],s[2],dp[MAXM][MAXM],binom[MAXM][MAXM],ans[MAXN];
int Pow(int a,int b){
    int ans=1;
    for(;b>0;a=1ll*a*a%P,b>>=1)
        if(b&1)
            ans=1ll*ans*a%P;
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;++i)
        s[a[i]]+=w[i];
    dp[0][0]=1;
    for(int i=1;i<=m;++i){
        dp[i][0]=1ll*dp[i-1][0]*(s[1]+i-1)%P*Pow(s[0]+s[1]+i-1,P-2)%P;
        dp[i][i]=1ll*dp[i-1][i-1]*(s[0]-i+1)%P*Pow(s[0]+s[1]-i+1,P-2)%P;
        for(int j=1;j<i;++j)
            dp[i][j]=(1ll*dp[i-1][j]*(s[1]+i-1-j)%P*Pow(s[0]+s[1]+i-1-j*2,P-2)+1ll*dp[i-1][j-1]*(s[0]-j+1)%P*Pow(s[0]+s[1]+i-j*2+1,P-2))%P;
    }
    for(int i=0;i<=m;++i){
        binom[i][0]=binom[i][i]=1;
        for(int j=1;j<m;++j)
            binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%P;
    }
    int res=1;
    for(int y=1;y<=m;++y){
        res=1ll*res*(s[0]-y+1)%P;
        int inv=Pow(res,P-2)%P;
        for(int i=1;i<=n;++i)
            if(a[i]==0){
                int tmp=0;
                for(int x=1;x<=y;++x){
                    int res=1ll*x*binom[y][x]%P;
                    for(int j=1;j<=x;++j)
                        res=1ll*res*(w[i]-j+1)%P;
                    for(int j=1;j<=y-x;++j)
                        res=1ll*res*(s[0]-w[i]-j+1)%P;
                    tmp=(tmp+res)%P;
                }
                ans[i]=(ans[i]+1ll*tmp*inv%P*dp[m][y])%P;
            }
    }
    res=1;
    for(int y=1;y<=m;++y){
        res=1ll*res*(s[1]+y-1)%P;
        int inv=Pow(res,P-2)%P;
        for(int i=1;i<=n;++i)
            if(a[i]==1){
                int tmp=0;
                for(int x=1;x<=y;++x){
                    int res=1ll*x*binom[y][x]%P;
                    for(int j=1;j<=x;++j)
                        res=1ll*res*(w[i]+j-1)%P;
                    for(int j=1;j<=y-x;++j)
                        res=1ll*res*(s[1]-w[i]+j-1)%P;
                    tmp=(tmp+res)%P;
                }
                ans[i]=(ans[i]+1ll*tmp*inv%P*dp[m][m-y])%P;
            }
    }
    for(int i=1;i<=n;++i)
        if(a[i]==0)
            printf("%d\n",(w[i]-ans[i]+P)%P);
        else
            printf("%d\n",(w[i]+ans[i])%P);
    return 0;
}