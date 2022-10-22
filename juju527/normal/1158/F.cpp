#include<bits/stdc++.h>
using namespace std;
const int maxn=3005,maxc=3005,mod=998244353;
int n,c;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return res;
}
namespace task1{
    int f[maxn][maxn];
    int cnt[maxc];
    int pw[maxn],iv[maxn];
    int dp[maxn][maxn],suf[maxn][maxn];
    void solve(){
        pw[0]=1;for(int i=1;i<=n;i++)pw[i]=add(pw[i-1]+pw[i-1]);
        for(int i=1;i<=n;i++)iv[i]=power(pw[i]-1,mod-2);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c;j++)cnt[j]=0;
            int v=1,zero=c;
            for(int j=i;j<=n;j++){
                if(!cnt[a[j]])zero--,v=1ll*v*sub(pw[cnt[a[j]]+1]-1)%mod;
                else v=1ll*v*iv[cnt[a[j]]]%mod*sub(pw[cnt[a[j]]+1]-1)%mod;
                cnt[a[j]]++;
                if(zero>0)continue;
                if(a[i]==a[j])f[i][j]=0;
                else{
                    int w=1ll*v*iv[cnt[a[i]]]%mod*pw[cnt[a[i]]-1]%mod;
                    w=1ll*w*iv[cnt[a[j]]]%mod;
                    f[i][j]=w;
                }
            }
        }
        for(int i=0;i<=n;i++)dp[i][0]=pw[n-i];dp[n+1][0]=1;
        for(int i=n+1;i>=0;i--)suf[i][0]=add(suf[i+1][0]+dp[i][0]);
        int lim=n/c;
        for(int j=1;j<=lim;j++){
            for(int i=n;i>=1;i--){
                for(int k=i+1;k<=n;k++)
                    dp[i][j]=add(dp[i][j]+1ll*f[i][k]*suf[k+1][j-1]%mod);
                suf[i][j]=add(suf[i+1][j]+dp[i][j]);
            }
        }
        for(int i=0;i<=n;i++)
            printf("%d ",sub(suf[1][i]-suf[1][i+1]-(i==0)));
        return ;
    }
};
namespace task2{
    const int maxs=(1<<12)+5;
    int f[2][maxn][maxs];
    void solve(){
        int lim=n/c,S=(1<<c);
        f[0][0][0]=1;
        for(int i=0;i<n;i++){
            int now=i&1,nxt=now^1;
            for(int j=0;j<=lim;j++)for(int s=0;s<S-1;s++)f[nxt][j][s]=0;
            for(int j=0;j<=lim;j++){
                int v=a[i+1];
                for(int s=0;s<S-1;s++){
                    int t=s,val=f[now][j][s];
                    f[nxt][j][t]=add(f[nxt][j][t]+val);
                    t|=(1<<v-1);
                    if(t==S-1)f[nxt][j+1][0]=add(f[nxt][j+1][0]+val);
                    else f[nxt][j][t]=add(f[nxt][j][t]+val);
                }
            }
        }
        for(int i=0;i<=n;i++){
            int res=0;
            for(int s=0;s<S-1;s++)res=add(res+f[n&1][i][s]);
            printf("%d ",res-(i==0));
        }
        return ;
    }
};
namespace task3{
    int fc[maxn],iv[maxn];
    int C(int n,int m){return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
    void solve(){
        fc[0]=1;for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
        iv[n]=power(fc[n],mod-2);for(int i=n-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
        for(int i=0;i<=n;i++)printf("%d ",C(n,i)-(i==0));
        return ;
    }
}
int main(){
    n=read();c=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(c==1)task3::solve();
    else if(c>11)task1::solve();
    else task2::solve();
    return 0;
}