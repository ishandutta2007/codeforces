#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=2e5+10;
const ll mod=1e9+7;

ll sum[mn*4],mi[mn*4],laz[mn*4];
#define mid ((l+r)>>1)
inline void prop(int x,int l,int r){
    if(laz[x]==inf)return;
    sum[x]=laz[x]*(r-l+1);
    mi[x]=laz[x];
    if(x*2+1<mn*4){
        laz[x*2]=laz[x*2+1]=laz[x];
    }
    laz[x]=inf;
}
inline void eval(int x,int l,int r){
    prop(x*2,l,mid),prop(x*2+1,mid+1,r);
    sum[x]=sum[x*2]+sum[x*2+1];
    mi[x]=min(mi[x*2],mi[x*2+1]);
}
void upd(int x,int l,int r,int a,int b,ll c){
    if(l==a&&r==b)laz[x]=c;
    else{
        prop(x,l,r);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x,l,r);
    }
}
int pos(int x,int l,int r,ll t){
    prop(x,l,r);
    if(t<=mi[x])return r+1;
    else if(l==r)return l;
    else{
        int p=pos(x*2,l,mid,t);
        if(p==mid+1)return pos(x*2+1,mid+1,r,t);
        else return p;
    }
}

pll query(int x,int l,int r,int a,ll y){
    prop(x,l,r);
    if(y<mi[x])return {0,0};
    else if(a==l&&y>=sum[x])return {r-l+1,sum[x]};
    else if(a>mid)return query(x*2+1,mid+1,r,a,y);
    else{
        pll p=query(x*2,l,mid,a,y);
        pll q=query(x*2+1,mid+1,r,mid+1,y-p.second);
        return {p.first+q.first,p.second+q.second};
    }
}
ll a[mn];
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)upd(1,1,n,i,i,a[i]);
    while(q--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            int l=pos(1,1,n,c);
            if(l<=b)upd(1,1,n,l,b,c);
        }
        else{
            printf("%lld\n",query(1,1,n,b,c).first);
        }
    }
}