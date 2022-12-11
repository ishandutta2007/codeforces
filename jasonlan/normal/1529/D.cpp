#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1001000,maxm=0,maxz=0,mod=998244353;
int n,f[maxn],sum[maxn];
int prime[maxn],tnt;
int g[maxn],gcnt[maxn];
bool vis[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int qpow(int x,int k){
    int res=1;
    while(k){
        if(k&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        k>>=1;
    }
    return res;
}
int qmod(int x){
    return x>=mod?x-mod:x;
}
void reset(){
    g[1]=1;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prime[++tnt]=i;
            g[i]=gcnt[i]=2;
        }
        for(int j=1,k;(k=prime[j]*i)<=n;++j){
            vis[k]=true;
            if(i%prime[j]==0){
                g[k]=1ll*g[i]*qpow(gcnt[i],mod-2)%mod*(gcnt[i]+1)%mod;
                gcnt[k]=gcnt[i]+1;
                break;
            }
            g[k]=1ll*g[i]*2%mod;
            gcnt[k]=2;
        }
    }
}
void proc(){
    n=read();
    reset();
    for(int i=1;i<=n;++i){
        f[i]=qmod(sum[i-1]+ g[i] );
        sum[i]=qmod(sum[i-1]+f[i]);
    }
    cout<<f[n]<<endl;
}
int main(){
    int T=1;
    while(T--)proc();
    return 0;
}