#include<bits/stdc++.h>
using namespace std;
const int maxn=105,mod=1e9+7;
int n;
bool b[maxn][maxn];
int a[maxn][maxn];
int fc[maxn],iv[maxn];
int pre[maxn][maxn];
int suf[maxn][maxn];
int f[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){
    if(x>=mod)x-=mod;
    return x;
}
inline int sub(int x){
    if(x<0)x+=mod;
    return x;
}
int power(int x,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return ans;
}
int solve(){
    bool chg=0;
    for(int i=2;i<=n;i++){
        int p=i;
        for(int j=i+1;j<=n;j++)if(a[j][i]>a[p][i])p=j;
        if(a[p][i]==0)return 0;
        if(p^i)chg^=1;
        swap(a[i],a[p]);
        int inv=power(a[i][i],mod-2);
        for(int j=i+1;j<=n;j++){
            int v=mod-1ll*a[j][i]*inv%mod;
            for(int k=i;k<=n;k++)a[j][k]=add(a[j][k]+1ll*v*a[i][k]%mod);
        }
    }
    int ans=1;
    for(int i=2;i<=n;i++)ans=1ll*ans*a[i][i]%mod;
    return chg?mod-ans:ans;
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
        int u,v;
        u=read();v=read();
        b[u][v]=b[v][u]=1;
    }
    fc[0]=1;
    for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    iv[n]=power(fc[n],mod-2);
    for(int i=n-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
    pre[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i-1;j++)pre[i][j]=1ll*(mod-i)*pre[i-1][j]%mod;
        for(int j=1;j<=i;j++)pre[i][j]=add(pre[i][j]+pre[i-1][j-1]);
    }
    suf[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=n-i;j++)suf[i][j]=1ll*(mod-i)*suf[i+1][j]%mod;
        for(int j=1;j<=n-i+1;j++)suf[i][j]=add(suf[i][j]+suf[i+1][j-1]);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                if(!b[i][j])a[i][j]=a[j][i]=mod-1,a[i][i]++,a[j][j]++;
                else a[i][j]=a[j][i]=mod-k,a[i][i]+=k,a[j][j]+=k;
            }
//        for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
        int val=solve(),w=1ll*iv[k-1]*iv[n-k]%mod;
//        cout<<"*"<<val<<endl;
        if((n-k)&1)w=mod-w;
        for(int i=0;i<=k-1;i++)
            for(int j=0;j<=n-k;j++)
                f[i+j]=add(f[i+j]+1ll*val*w%mod*pre[k-1][i]%mod*suf[k+1][j]%mod);
    }
    for(int i=0;i<n;i++)printf("%d ",f[i]);
    return 0;
}