#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int Type=1;
const int maxn=301000;
int n;
int a[maxn],c[maxn];
int f[20][maxn],ver;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int GetT(){
    if(Type==1)return 1;
    return read();
}
int findf(int p){
    for(int i=19;~i;--i)
        if(a[f[i][p]])p=f[i][p];
    return p;
}
void insert(){
    scanf("%d%d%d",&f[0][ver],&a[ver],&c[ver]);
    for(int i=1;i<=19;++i)
        f[i][ver]=f[i-1][f[i-1][ver]];
}
void query(){
    int p,w;
    long long ans=0,answ=0;
    scanf("%d%d",&p,&w);
    while(w){
        if(!a[p])break;
        int t=findf(p);
        if(w<=a[t]){
            ans+=1ll*c[t]*w;
            answ+=w;
            a[t]-=w;
            w=0;
        }
        else{
            ans+=1ll*c[t]*a[t];
            answ+=a[t];
            w-=a[t];
            a[t]=0;
        }
    }
    printf("%lld %lld\n",answ,ans);
    fflush(stdout);
}
void proc(){
    scanf("%d%d%d",&n,&a[0],&c[0]);
    for(int i=1,op;i<=n;++i){
        scanf("%d",&op);
        ver=i;
        if(op==1)insert();
        else query();
    }
}
int main(){
    int T=GetT();
    while(T--)proc();
    return 0;
}