#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int maxn=22,maxm=0,mod=31607;
int n;
int a[maxn][maxn],c[maxn][maxn],inv;
int popcount[1<<maxn];
int C1[maxn],C2[1<<maxn],C3[1<<maxn];
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
int qmod(int x){
    return x-(x>=mod?mod:0);
}
int qdec(int x){
    return x+(x<0?mod:0);
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
void reset(){
    inv=qpow(10000,mod-2);
    for(int i=1;i<(1<<n);++i)
        popcount[i]=popcount[i^(i&-i)]+1;
}
int Do1(){
    //GetC1
    for(int i=0;i<n;++i){
        C1[i]=1;
        for(int j=0;j<n;++j)
            C1[i]=1ll*C1[i]*c[i][j]%mod;
    }
    int ans=0;
    for(int i=1;i<(1<<n);++i){
        int res=1;
        for(int j=0;j<n;++j)
            if((i>>j)&1)
                res=1ll*res*C1[j]%mod;
        if(popcount[i]&1)ans=qmod(ans+res);
        else ans=qdec(ans-res);
    }
    return ans;
}
int Do2(){
    //
    for(int i=0;i<n;++i){
        C1[i]=1;
        for(int j=0;j<n;++j)
            C1[i]=1ll*C1[i]*c[j][i]%mod;
    }
    //
    for(int i=0;i<(1<<n);++i)
        C2[i]=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            C3[1<<j]=c[i][j];
        C3[0]=1;
        for(int j=0;j<(1<<n);++j)
            C3[j]=1ll*C3[j&-j]*C3[j^(j&-j)]%mod;
        for(int j=0;j<(1<<n);++j){
            C2[j]=1ll*C2[j]*qdec(1-C3[j])%mod;
            C3[j]=0;
        }
    }
    int ans=0;
    for(int i=1;i<(1<<n)-1;++i){
        //
        int res=1;
        for(int j=0;j<n;++j)
            if((i>>j)&1)res=1ll*res*C1[j]%mod;
        res=1ll*res*C2[((1<<n)-1)^i]%mod;
        if(popcount[i]&1)ans=qmod(ans+res);
        else ans=qdec(ans-res);
    }
    return ans;
}
int Do3(){
    //1.
    int d=1;
    for(int i=0;i<n;++i)
        d=1ll*d*c[i][i]%mod,c[i][i]=1;
    int res=1;
    res=qdec(res-Do1());
    res=qdec(res-Do2());
    for(int i=0;i<n;++i)
        c[i][i]=a[i][i];
    return 1ll*res*d%mod;
}
int Do4(){
    int d=1;
    for(int i=0;i<n;++i)
        d=1ll*d*c[i][n-i-1]%mod,c[i][n-i-1]=1;
    int res=qdec(1-Do1());
    res=qdec(res-Do2());
    res=qdec(res-Do3());
    return 1ll*res*d%mod;
}
void proc(){
    n=read();
    reset();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            a[i][j]=c[i][j]=1ll*read()*inv%mod;
    //2^21
    //2^21*21
    //1
    //
    int ans=0;
    ans=qmod(ans+Do1());
    ans=qmod(ans+Do2());
    ans=qmod(ans+Do3());
    ans=qmod(ans+Do4());
    printf("%d\n",ans);
}
int main(){
    int T=1;
    while(T--)proc();
    return 0;
}