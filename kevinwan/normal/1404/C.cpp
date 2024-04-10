#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int seg[mn*4],laz[mn*4];
#define mid ((l+r)>>1)
inline void prop(int x){
    if(!laz[x])return;
    seg[x]+=laz[x];
    if(x*2+1<mn*4){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
inline void eval(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=min(seg[x*2],seg[x*2+1]);
}
void upd(int x,int l,int r,int a,int b,int c){
    if(l==a&&r==b)laz[x]+=c,prop(x);
    else{
        prop(x);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
int gt(int x,int l,int r){
    if(l==r)return l;
    else{
        prop(x),prop(x*2+1);
        if(!seg[x*2+1])return gt(x*2+1,mid+1,r);
        else return gt(x*2,l,mid);
    }
}
vector<pii>v[mn];
int a[mn],ans[mn],bit[mn];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    memset(seg,0x3f,sizeof(seg));
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        v[a+1].push_back({n-b,i});
    }
    for(int i=n;i>=1;i--){
        if(i>=a[i])upd(1,1,n,i,i,-inf+i-a[i]);
        while(!seg[1]){
            int x=gt(1,1,n);
            upd(1,1,n,x,x,inf);
            upd(1,1,n,x,n,-1);
            up(x,1);
        }
        for(pii p:v[i]){
            ans[p.second]=qu(p.first);
        }
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}