#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define mid (l+r>>1)
const int mn=1e5+10;
ll seg[mn*3][2][2],F[2][2]={{1,1},{1,0}},I[2][2]={{1,0},{0,1}};
ll laz[mn*3][2][2];
inline void add(ll c[2][2],ll a[2][2],ll b[2][2]){
    c[0][0]=(a[0][0]+b[0][0])%mod;
    c[0][1]=(a[0][1]+b[0][1])%mod;
    c[1][0]=(a[1][0]+b[1][0])%mod;
    c[1][1]=(a[1][1]+b[1][1])%mod;
}
ll t[2][2];
inline void mult(ll a[2][2],ll b[2][2]){
    memset(t,0,sizeof(t));
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)t[i][k]=(t[i][k]+a[i][j]*b[j][k])%mod;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)a[i][j]=t[i][j];
}
ll tt[2][2];
inline void po(ll a[2][2],ll b){
    memcpy(tt,I,sizeof(tt));
    for(;b;b>>=1,mult(a,a))if(b&1)mult(tt,a);
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)a[i][j]=tt[i][j];
}
inline void prop(int x){
    if(memcmp(laz[x],I,sizeof(I))!=0){
        ll a[2][2];
        mult(seg[x],laz[x]);
        if(x*2<mn*3){
            mult(laz[x*2],laz[x]);
            mult(laz[x*2+1],laz[x]);
        }
        memcpy(laz[x],I,sizeof(I));
    }
}
inline void eval(int x){
    prop(x);
    prop(x*2);
    prop(x*2+1);
    add(seg[x],seg[x*2],seg[x*2+1]);
}
void init(int x,int l,int r){
    memcpy(laz[x],I,sizeof(I));
    if(l==r){
        int n;
        scanf("%lld",&n);
        ll a[2][2];
        memcpy(a,F,sizeof(a));
        po(a,n);
        memcpy(seg[x],a,sizeof(a));
    }
    else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        eval(x);
    }
}
ll ch[2][2];
void update(int x,int l,int r,int a,int b){
    prop(x);
    if(l==a&&r==b)mult(laz[x],ch);
    else{
        if(b<=mid)update(x*2,l,mid,a,b);
        else if(a>mid)update(x*2+1,mid+1,r,a,b);
        else update(x*2,l,mid,a,mid),update(x*2+1,mid+1,r,mid+1,b);
        eval(x);
    }
}
ll ans[2][2];
void query(int x,int l,int r,int a,int b){
    prop(x);
    if(l==a&&r==b)add(ans,ans,seg[x]);
    else{
        if(b<=mid)query(x*2,l,mid,a,b);
        else if(a>mid)query(x*2+1,mid+1,r,a,b);
        else query(x*2,l,mid,a,mid),query(x*2+1,mid+1,r,mid+1,b);
    }
}
int main()
{
    int n,m,x;
    scanf("%d%d",&n,&m);
    init(1,1,n);
    while(m--){
        int a,b,c;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d%d",&a,&b,&c);
            memcpy(ch,F,sizeof(ch));
            po(ch,c);
            update(1,1,n,a,b);
        }
        else{
            scanf("%d%d",&a,&b);
            memset(ans,0,sizeof(ans));
            query(1,1,n,a,b);
            printf("%lld\n",ans[0][1]);
        }
    }
}