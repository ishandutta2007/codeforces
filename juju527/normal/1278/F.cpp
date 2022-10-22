#include<bits/stdc++.h>
using namespace std;
const int maxk=1e7+5,mod=998244353;
int n,m,k;
int iv[maxk];
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
inline int power(int x,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return ans;
}
bool bj[maxk];
int len;
int p[maxk];
int idk[maxk];
void pre(){
    idk[1]=1;
    for(int i=2;i<=k;i++){
        if(!bj[i])p[++len]=i,idk[i]=power(i,k);
        for(int j=1;1ll*p[j]*i<=k&&j<=len;j++){
            int v=i*p[j];
            bj[v]=1;
            idk[v]=1ll*idk[i]*idk[p[j]]%mod;
            if(i%p[j]==0)break;
        }
    }
    iv[1]=1;
    for(int i=2;i<=k;i++)iv[i]=sub(-1ll*(mod/i)*iv[mod%i]%mod);
    return ;
}
namespace task1{
    void solve(){
        int res=0,v=power(m,1ll*(mod-2)*n%(mod-1));
        int pw=power(m-1,n),c=1,ivm=power(m-1,mod-2);
        for(int x=0;x<=n;x++){
            res=add(res+1ll*c*pw%mod*idk[x]%mod);
            c=1ll*c*iv[x+1]%mod*(n-x)%mod;
            pw=1ll*pw*ivm%mod;
        }
        printf("%d\n",1ll*v*res%mod);
        exit(0);
    }
};
namespace task2{
    int s[maxk];
    void solve(){
        int ivm=power(m,mod-2);
        s[k]=1;
        int v=1ll*(m-1)*ivm%mod,c=1,pw=1;
        for(int i=k-1;i>=0;i--){
            c=1ll*c*iv[k-i]%mod*(n-i-1)%mod;
            pw=1ll*pw*(mod-ivm)%mod;
            s[i]=add(1ll*v*s[i+1]%mod+1ll*c*pw%mod);
        }
        int res=0;
        c=1;pw=1;
        for(int i=0;i<=k;i++){
            res=add(res+1ll*idk[i]*c%mod*pw%mod*s[i]%mod);
            c=1ll*c*iv[i+1]%mod*(n-i)%mod;
            pw=1ll*pw*ivm%mod;
        }
        printf("%d\n",res);
        exit(0);
    }
};
int main(){
    n=read();m=read();k=read();
    if(m==1){printf("%d\n",power(n,k));return 0;}
    pre();
    if(n<=k)task1::solve();
    else task2::solve();
    return 0;
}