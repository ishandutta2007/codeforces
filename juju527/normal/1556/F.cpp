#include<bits/stdc++.h>
using namespace std;
const int maxn=25,maxs=(1<<14)+5,mod=1e9+7;
int a[maxn],iv[maxn][maxn];
int g[maxs],f[maxs];
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
int main(){
    int n,S;
    n=read();S=(1<<n)-1;
    for(int i=0;i<n;i++)a[i]=read();
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)iv[i][j]=power(a[i]+a[j],mod-2);
    for(int s=1;s<=S;s++){
        int cur=1;
        for(int i=0;i<n;i++){
            if(!(s&(1<<i)))continue;
            for(int j=0;j<n;j++){
                if(!((S-s)&(1<<j)))continue;
                cur=1ll*cur*a[i]%mod*iv[i][j]%mod;
            }
        }
        g[s]=cur;
    }
    int res=0;
    for(int s=1;s<=S;s++){
        int cur=g[s];
        for(int t=(s-1)&s;t;t=(t-1)&s){
            int tmp=1;
            for(int i=0;i<n;i++){
                if(!((s-t)&(1<<i)))continue;
                for(int j=0;j<n;j++){
                    if(!(t&(1<<j)))continue;
                    tmp=1ll*tmp*a[i]%mod*iv[i][j]%mod;
                }
            }
            cur=sub(cur-1ll*f[t]*g[s-t]%mod*power(tmp,mod-2)%mod);
        }
        f[s]=cur;
        int num=0;
        for(int i=0;i<n;i++)if(s&(1<<i))num++;
        res=add(res+1ll*num*f[s]%mod);
    }
    printf("%d\n",res);
    return 0;
}