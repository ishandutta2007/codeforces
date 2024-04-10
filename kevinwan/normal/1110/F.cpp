#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e5+10;
vector<pii>g[mn];
int ro[mn],o[mn],s[mn],ct;
ll dep[mn];
void dfs1(int x,int p){
    o[x]=++ct;
    ro[o[x]]=x;
    s[x]=1;
    for(pii y:g[x]){
        if(y.first!=p)dep[y.first]=dep[x]+y.second,dfs1(y.first,x),s[x]+=s[y.first];
    }
}
ll ans[mn];
int l[mn],r[mn];
vector<int>vesh[mn];
ll seg[mn*4],laz[mn*4];
void prop(int x){
    if(!laz[x])return;
    seg[x]+=laz[x];
    if(x*2+1<mn*4){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
void eval(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=min(seg[x*2],seg[x*2+1]);
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,int c){
    if(l==a&&r==b)laz[x]+=c;
    else{
        prop(x);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
ll qu(int x,int l,int r,int a,int b){
    prop(x);
    if(l==a&&r==b)return seg[x];
    else{
        if(b<=mid)return qu(x*2,l,mid,a,b);
        else if(a>mid)return qu(x*2+1,mid+1,r,a,b);
        else return min(qu(x*2,l,mid,a,mid),qu(x*2+1,mid+1,r,mid+1,b));
    }
}
void init(int x,int l,int r){
    if(l==r){
        if(s[ro[l]]==1)seg[x]=dep[ro[l]];
        else seg[x]=0x3f3f3f3f3f3f3f3f;
    }else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        eval(x);
    }
}
int n;
void dfs2(int x,int p){
    for(int y:vesh[x]){
        ans[y]=qu(1,1,n,l[y],r[y]);
    }
    for(pii th:g[x]){
        int y=th.first,w=th.second;
        if(y==p)continue;
        upd(1,1,n,1,n,w);
        upd(1,1,n,o[y],o[y]+s[y]-1,-2*w);
        dfs2(y,x);
        upd(1,1,n,o[y],o[y]+s[y]-1,2*w);
        upd(1,1,n,1,n,-w);
    }
}
int main(){
    int q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back({i,b});
    }
    dfs1(1,1);
    for(int i=0;i<q;i++){
        int a;
        scanf("%d%d%d",&a,l+i,r+i);
        vesh[a].push_back(i);
    }
    init(1,1,n);
    dfs2(1,1);
    for(int i=0;i<q;i++)printf("%lld\n",ans[i]);
}