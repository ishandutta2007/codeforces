#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
const int mn=5e5+5;
ll t[2][2];
inline void mult(ll c[2][2],ll a[2][2],ll b[2][2]){
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)c[i][k]=(c[i][k]+a[i][j]*b[j][k])%mod;
}
inline void add(ll c[2][2],ll a[2][2],ll b[2][2]){
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)c[i][j]=(a[i][j]+b[i][j])%mod;
}
#define mid (l+r>>1)
ll seg[mn*3][2][2],laz[mn*3][2][2],p[mn][2][2],psa[mn][2][2];
inline void prop(int x,int l,int r){
    if(laz[x][0][0]==0&&laz[x][0][1]==0&&laz[x][1][0]==0&&laz[x][1][1]==0)return;
    ll ad[2][2];
    memset(ad,0,sizeof(ad));
    mult(ad,psa[r-l],laz[x]);
    add(seg[x],seg[x],ad);
    if(l!=r){
        add(laz[x*2],laz[x*2],laz[x]);
        memset(ad,0,sizeof(ad));
        mult(ad,laz[x],p[mid+1-l]);
        add(laz[x*2+1],laz[x*2+1],ad);
    }
    memset(laz[x],0,sizeof(laz[x]));
}
inline void update(int x,int l,int r){
    prop(x*2,l,mid),prop(x*2+1,mid+1,r);
    add(seg[x],seg[x*2],seg[x*2+1]);
}
void upd(int x,int l,int r,int a,int b,int c){
    prop(x,l,r);
    if(a==l&&b==r)add(laz[x],laz[x],p[c]);
    else{
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c+mid+1-a);
        update(x,l,r);
    }
}
ll ar[mn],ret[2][2];
void qu(int x,int l,int r,int a,int b){
    prop(x,l,r);
    if(a==l&&b==r)add(ret,ret,seg[x]);
    else{
        if(b<=mid)qu(x*2,l,mid,a,b);
        else if(a>mid)qu(x*2+1,mid+1,r,a,b);
        else qu(x*2,l,mid,a,mid),qu(x*2+1,mid+1,r,mid+1,b);
    }
}
int main()
{
    p[0][0][0]=p[0][1][1]=p[1][0][0]=p[1][1][0]=p[1][0][1]=1;
    int n,m,i;
    for(i=2;i<mn;i++)mult(p[i],p[i-1],p[1]);
    memcpy(psa[0],p[0],sizeof(p[0]));
    for(i=1;i<mn;i++)add(psa[i],psa[i-1],p[i]);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%lld",ar+i),ar[i]+=ar[i-1];
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            upd(1,1,n,b,c,1);
        }
        else{
            memset(ret,0,sizeof(ret));
            qu(1,1,n,b,c);
            ll ans=ar[c]-ar[b-1]+ret[1][0];
            ans%=mod;
            if(ans<0)ans+=mod;
            printf("%lld\n",ans);
        }
    }
}