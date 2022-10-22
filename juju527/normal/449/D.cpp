#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<21),mod=1e9+7;
int a[maxn],pw[maxn];
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
void FWTand(int *f,int lim,int opt){
    opt=add(opt+mod);
    for(int mid=1;mid<lim;mid<<=1)
        for(int j=0;j<lim;j+=(mid<<1))
            for(int k=0;k<mid;k++)
                f[j+k]=add(f[j+k]+1ll*opt*f[j+k+mid]%mod);
    return ;
}
int main(){
    int n,m=0;
    n=read();
    pw[0]=1;
    for(int i=1;i<=n;i++){
        int v;
        v=read();
        a[v]++;
        m=max(m,v);
        pw[i]=2ll*pw[i-1]%mod;
    }
    int lim=1;
    while(lim<=m)lim<<=1;
    FWTand(a,lim,1);
    for(int i=0;i<lim;i++)a[i]=pw[a[i]];
    FWTand(a,lim,-1);
    if(a[0]==pw[n])a[0]--;
    printf("%d\n",a[0]);
    return 0;
}