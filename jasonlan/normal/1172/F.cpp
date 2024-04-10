#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mid ((l+r)>>1)
#define ls (p<<1)
#define rs (ls|1)
using namespace std;
typedef long long ll;
const ll INF=1e18;
const int maxn=1001000;
int n,m,mod;
int a[maxn];
ll sum[maxn<<2];
vector <ll> c[maxn<<2];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void update(int p,int l,int r){
    sum[p]=sum[ls]+sum[rs];
    for(int i=0,j=0;i<=mid-l+1;++i){
        ll lim=c[ls][i+1]-1ll*i*mod+sum[ls];
        if(j==r-mid+1)--j;
        for(;j<=r-mid;++j){
            if(c[rs][j]>=lim){
                --j;break;
            }
            c[p][i+j]=min(c[p][i+j],max(c[ls][i],c[rs][j]-(sum[ls]-1ll*i*mod)));
        }
    }
}
void build(int p,int l,int r){
    c[p].resize(r-l+3);
    for(int i=0;i<=r-l+2;++i)
        c[p][i]=(i?INF:-INF);
    if(l==r){
        sum[p]=a[l];
        c[p][1]=mod-a[l];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(p,l,r);
}
ll query(int p,int lr,int rr,int l,int r,ll add){
    if(lr<=l&&r<=rr){
        int cnt=upper_bound(c[p].begin(),c[p].end(),add)-c[p].begin()-1;
        return add+sum[p]-1ll*cnt*mod;
    }
    if(lr<=mid){
        if(rr>mid)return query(rs,lr,rr,mid+1,r,query(ls,lr,rr,l,mid,add));
        return query(ls,lr,rr,l,mid,add);
    }
    return query(rs,lr,rr,mid+1,r,add);
}
int main(){
    n=read();m=read();mod=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    for(int i=1,l,r;i<=m;++i){
        l=read();r=read();
        printf("%lld\n",query(1,l,r,1,n,0));
    }
    return 0;
}