#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=400009;
int n,m,t;
int b[309],c[309],inv[309];
int s[M<<2],vis[M<<2];
bitset<80> p[M<<2],P,vp[M<<2],v[309];
void pu(int now){
    p[now]=p[now<<1]|p[now<<1|1];
    s[now]=1ll*s[now<<1]*s[now<<1|1]%mod;
}
void build(int now,int l,int r){
    vis[now]=s[now]=1;
    if(l==r){
        return;
    }
    int mid=l+r>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
}
void pd(int now,int l,int r){
    if(vis[now]!=1){
        int &x=vis[now],mid=l+r>>1;
        vis[now<<1]=1ll*vis[now<<1]*x%mod;
        s[now<<1]=1ll*s[now<<1]*kpow(x,mid-l+1)%mod;
        vis[now<<1|1]=1ll*vis[now<<1|1]*x%mod;
        s[now<<1|1]=1ll*s[now<<1|1]*kpow(x,r-mid)%mod;
        x=1;
        p[now<<1]|=vp[now];
        p[now<<1|1]|=vp[now];
        vp[now<<1]|=vp[now];
        vp[now<<1|1]|=vp[now];
    }
}
void update(int now,int l,int r,int x,int y,int z){
    if(x<=l&&r<=y){
        vp[now]|=v[z];
        p[now]|=v[z];
        s[now]=1ll*s[now]*kpow(z,r-l+1)%mod;
        vis[now]=1ll*vis[now]*z%mod;
        return;
    }
    pd(now,l,r);
    int mid=l+r>>1;
    if(x<=mid)update(now<<1,l,mid,x,y,z);
    if(y>mid)update(now<<1|1,mid+1,r,x,y,z);
    pu(now);
}
int query(int now,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        P|=p[now];
        return s[now];
    }
    pd(now,l,r);
    int mid=l+r>>1,ans=1;
    if(x<=mid)ans=1ll*ans*query(now<<1,l,mid,x,y)%mod;
    if(y>mid)ans=1ll*ans*query(now<<1|1,mid+1,r,x,y)%mod;
    return ans;
}
int main(){
    for(int i=1;i<=300;++i)inv[i]=kpow(i,mod-2);
    for(int i=2;i<=300;++i){
        int x=i;
        for(int j=2;j<x;++j){
            while(x%j==0)x/=j;
        }
        if(x==i)c[b[i]=++t]=i;
        x=i;
        for(int j=2;j<=x;++j){
            if(x%j==0)v[i][b[j]]=1;
            while(x%j==0)x/=j;
        }
    }   

    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        update(1,1,n,i,i,x);
    }
    for(int i=1;i<=m;++i){
        char C[10];
        int l,r;
        cin>>C>>l>>r;
        if(C[0]=='T'){
            P.reset();
            int ans=query(1,1,n,l,r);
            for(int i=1;i<=t;++i){
                if(P[i])ans=1ll*ans*inv[c[i]]%mod*(c[i]-1)%mod;
            }
            cout<<ans<<endl;
        }
        else{
            int z;
            cin>>z;
            update(1,1,n,l,r,z);
        }
    }
    return 0;
}
/*
4 1
5 9 1 2
TOTIENT 3 4
*/