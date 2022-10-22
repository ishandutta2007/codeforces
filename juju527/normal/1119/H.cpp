//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5,maxs=(1<<17)+5,mod=998244353,iv2=(mod+1)/2;
int f1[maxs],f2[maxs],f3[maxs];
int g[maxs],ans[maxs];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
inline int power(int x,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return ans;
}
void FWTxor(int *f,int lim,int opt){
    for(int mid=1;mid<lim;mid<<=1){
        for(int j=0;j<lim;j+=(mid<<1)){
            for(int k=0;k<mid;k++){
                int u=f[j+k],v=f[j+k+mid];
                f[j+k]=1ll*opt*add(u+v)%mod;
                f[j+k+mid]=1ll*opt*sub(u-v)%mod;
            }
        }
    }
    return ;
}
int main(){
    int n,k,u,v,w,d=0;
    n=read();k=read();
    u=read();v=read();w=read();
    int val1=add(add(u+v)+w),val2=sub(add(u+v)-w);
    int val3=add(sub(u-v)+w),val4=sub(sub(u-v)-w);
    for(int i=1;i<=n;i++){
        int a,b,c;
        a=read();b=read();c=read();
        d^=a;b^=a;c^=a;
        f1[b]++;f2[c]++;f3[b^c]++;
    }
    FWTxor(f1,1<<k,1);FWTxor(f2,1<<k,1);FWTxor(f3,1<<k,1);
    for(int i=0;i<(1<<k);i++){
        int p1=f1[i],p2=f2[i],p3=f3[i];
        int c1=1ll*add(add(n+p1)+add(p2+p3))*iv2%mod*iv2%mod;
        int c2=sub(1ll*add(n+p1)*iv2%mod-c1);
        int c3=sub(1ll*add(n+p2)*iv2%mod-c1);
        int c4=sub(1ll*add(n+p3)*iv2%mod-c1);
        g[i]=1ll*power(val1,c1)*power(val2,c2)%mod*power(val3,c3)%mod*power(val4,c4)%mod;
    }
    FWTxor(g,1<<k,iv2);
    for(int i=0;i<(1<<k);i++)ans[i^d]=g[i];
    for(int i=0;i<(1<<k);i++)printf("%d ",ans[i]);
    puts("");
    return 0;
}