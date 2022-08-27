#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
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
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;

int n,q;
struct bs{
    int t[33];
    int tot;
    int le;
};

int head[33];
inline void add(int x){
    for (int i=30;i>=0;i--)if(1<<i&x){
        if(head[i])x^=head[i];
        else{
            head[i]=x;
            return;
        }
    }
}
bs operator+(const bs&a,const bs&b){
    bs c;
    c.tot=0;
    memset(head,0,sizeof(head));
    for (int i=1;i<=a.tot;i++)add(a.t[i]);
    for (int i=1;i<=b.tot;i++)add(b.t[i]);
    add(a.le^b.le);
    c.le=a.le;
    for (int i=30;i>=0;i--)if(head[i])c.t[++c.tot]=head[i];
    return c;
}
bs t[555555];
int tag[555555];
int a[555555];

void pd(int x){
    tag[x<<1]^=tag[x];
    tag[x<<1|1]^=tag[x];
    t[x<<1].le^=tag[x];
    t[x<<1|1].le^=tag[x];
    tag[x]=0;
}
void build(int l,int r,int x){
    if(l==r){
        t[x].le=a[l];
    }else{
        int mid=l+r>>1;
        build(l,mid,x<<1);
        build(mid+1,r,x<<1|1);
        t[x]=t[x<<1]+t[x<<1|1];
    }
}
int l1,r1;
int d;
bs an;

void cov(int l,int r,int x){
    if(l1<=l && r<=r1){
        tag[x]^=d;
        t[x].le^=d;
    }else{
        int mid=l+r>>1;
        if(tag[x])pd(x);
        if(l1<=mid)cov(l,mid,x<<1);
        if(r1>mid)cov(mid+1,r,x<<1|1);
        t[x]=t[x<<1]+t[x<<1|1];
    }
}

void que(int l,int r,int x){
    if(l1<=l && r<=r1){
        an=an+t[x];
    }else{
        int mid=l+r>>1;
        if(tag[x])pd(x);
        if(l1<=mid)que(l,mid,x<<1);
        if(r1>mid)que(mid+1,r,x<<1|1);
    }
}
    
int main(){
    gn(n);gn(q);
    for (int i=1;i<=n;i++){
        gn(a[i]);
    }
    build(1,n,1);
    while(q--){
        int opt;gn(opt);
        gn(l1);gn(r1);
        if(opt==1){
            gn(d);
            cov(1,n,1);
        }else{
            an.tot=0;
            an.le=0;
            que(1,n,1);
            printf("%d\n",1<<an.tot);
        }
    }
    return 0;
}