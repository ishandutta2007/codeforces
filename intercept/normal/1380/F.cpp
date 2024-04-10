#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
const int M=5e5+9;
int n,m;
int va[M<<2],la[M<<2],ra[M<<2],ma[M<<2],lv[M<<2],rv[M<<2];
void add(int &x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
void pu(int now){
    lv[now]=lv[now<<1];
    rv[now]=rv[now<<1|1];
    va[now]=1ll*va[now<<1]*va[now<<1|1]%mod;
    la[now]=1ll*va[now<<1]*la[now<<1|1]%mod;
    ra[now]=1ll*ra[now<<1]*va[now<<1|1]%mod;
    ma[now]=1ll*ra[now<<1]*la[now<<1|1]%mod;
    if(rv[now<<1]==1){
        int x=10+lv[now<<1|1];
        int v=19-x;
        add(va[now],1ll*la[now<<1]*ra[now<<1|1]%mod*v%mod);
        add(la[now],1ll*la[now<<1]*ma[now<<1|1]%mod*v%mod);
        add(ra[now],1ll*ma[now<<1]*ra[now<<1|1]%mod*v%mod);
        add(ma[now],1ll*ma[now<<1]*ma[now<<1|1]%mod*v%mod);
    }
}
void update(int now,int l,int r,int x,int v){
    if(l==r){
        va[now]=v+1;
        la[now]=1;
        ra[now]=1;
        ma[now]=0;
        lv[now]=rv[now]=v;
        return;
    }
    int mid=l+r>>1;
    x<=mid?update(now<<1,l,mid,x,v):update(now<<1|1,mid+1,r,x,v);
    pu(now);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%1d",&x);
        update(1,1,n,i,x);
    }
    for(int i=1;i<=m;++i){
        int x,d;
        scanf("%d%d",&x,&d);
        update(1,1,n,x,d);
        printf("%d\n",va[1]);
    }
    return 0;
}