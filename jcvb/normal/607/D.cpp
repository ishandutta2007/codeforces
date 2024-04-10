#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
//ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

struct edge{
    int v,next;
}e[222222];int etot=0;int g[222222];
void ae(int u,int v){
    e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
struct que{
    int opt,u,v,id;
}qu[222222];
int v1,q;
int n;


int lef[222222],rig[222222];int ind=0;
int dfn[222222],rdfn[222222];int ind2=0;
void dfs(int u){
    lef[u]=++ind;
    dfn[u]=++ind2;
    for (int i=g[u];~i;i=e[i].next)dfs(e[i].v);
    rig[u]=++ind;
    rdfn[u]=ind2;
}
int bit[444444];
void bitupd(int x,int d){
    for(;x<=2*n;x+=x&-x)bit[x]=1ll*bit[x]*d%mo;
}
int bitque(int x){
    int ans=1;
    for (;x;x-=x&-x)ans=1ll*ans*bit[x]%mo;
    return ans;
}

int sz[222222];


int seg[888888],tag[888888];
int l1,r1,d;
void build(int l,int r,int x){
    tag[x]=1;
    if(l!=r){
        int mid=l+r>>1;
        build(l,mid,x<<1);
        build(mid+1,r,x<<1|1);
    }
}
void pd(int x){
    seg[x<<1]=1ll*seg[x<<1]*tag[x]%mo;
    seg[x<<1|1]=1ll*seg[x<<1|1]*tag[x]%mo;
    tag[x<<1]=1ll*tag[x<<1]*tag[x]%mo;
    tag[x<<1|1]=1ll*tag[x<<1|1]*tag[x]%mo;
    tag[x]=1;
}
void segupd(int l,int r,int x){
    if(l1<=l && r<=r1){
        seg[x]=1ll*seg[x]*d%mo;
        tag[x]=1ll*tag[x]*d%mo;
    }else{
        int mid=l+r>>1;
        if(tag[x]!=1)pd(x);
        if(l1<=mid)segupd(l,mid,x<<1);
        if(r1>mid)segupd(mid+1,r,x<<1|1);
        seg[x]=(seg[x<<1]+seg[x<<1|1])%mo;
    }
}
int I;
void segupd1(int l,int r,int x){
    if(l==r){
        seg[x]=d;
    }else{
        int mid=l+r>>1;
        if(tag[x]!=1)pd(x);
        if(I<=mid)segupd1(l,mid,x<<1);
        else segupd1(mid+1,r,x<<1|1);
        seg[x]=(seg[x<<1]+seg[x<<1|1])%mo;
    }
}
void segque(int l,int r,int x){
    if(l1<=l && r<=r1){
        d=(d+seg[x])%mo;
    }else{
        int mid=l+r>>1;
        if(tag[x]!=1)pd(x);
        if(l1<=mid)segque(l,mid,x<<1);
        if(r1>mid)segque(mid+1,r,x<<1|1);
    }
}

void updsz(int u,int del){
    bitupd(lef[u],del);
    bitupd(rig[u],qp(del,mo-2));
    d=del;
    l1=dfn[u],r1=rdfn[u];
    segupd(1,n,1);
    sz[u]++;
}
int main(){
    memset(g,-1,sizeof(g));
    gn(v1);gn(q);
    n=1;
    for (int i=1;i<=q;i++){
        gn(qu[i].opt);
        if(qu[i].opt==1){
            gn(qu[i].u);gn(qu[i].v);
            qu[i].id=++n;
            ae(qu[i].u,n);
        }else gn(qu[i].u);
    }
    dfs(1);
    for (int i=1;i<=n;i++)sz[i]=1;
    for (int i=1;i<=2*n;i++)bit[i]=1;
    build(1,n,1);
    I=1,d=v1;
    segupd1(1,n,1);

    for (int i=1;i<=q;i++){
        if(qu[i].opt==1){
            int del=1ll*(sz[qu[i].u]+1)*qp(sz[qu[i].u],mo-2)%mo;
            updsz(qu[i].u,del);
            I=dfn[qu[i].id];d=1ll*bitque(lef[qu[i].u])*qu[i].v%mo;
            segupd1(1,n,1);
        }else{
            l1=dfn[qu[i].u],r1=rdfn[qu[i].u];d=0;
            segque(1,n,1);
            int x=1ll*sz[qu[i].u]*qp(bitque(lef[qu[i].u]),mo-2)%mo;
            x=1ll*x*d%mo;
            printf("%d\n",x);
        }
    }
    return 0;
}