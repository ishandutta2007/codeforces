#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll seg[mn*3][5],laz[mn*3],e[mn],k[mn];
vector<int>g[mn],in[mn];
vector<ll>d[mn];
ll dep[mn],v[mn];
int f[mn],l[mn];
int cur=0;
void dfs(int x,int p){
    f[x]=l[x]=cur;
    v[cur++]=dep[x];
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        k[in[x][i]]=y;
        dep[y]=dep[x]+d[x][i];
        dfs(y,x);
        l[x]=cur;
        v[cur++]=dep[x];
    }
}
void prop(int x){
    seg[x][0]+=laz[x];
    seg[x][1]-=2*laz[x];
    seg[x][2]-=laz[x];
    seg[x][3]-=laz[x];
    if(x<mn*3/2){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
void eval(int x){
    prop(x*2);
    prop(x*2+1);
    seg[x][0]=max(seg[x*2][0],seg[x*2+1][0]);
    seg[x][1]=max(seg[x*2][1],seg[x*2+1][1]);
    seg[x][2]=max(max(seg[x*2][2],seg[x*2+1][2]),seg[x*2][0]+seg[x*2+1][1]);
    seg[x][3]=max(max(seg[x*2][3],seg[x*2+1][3]),seg[x*2][1]+seg[x*2+1][0]);
    seg[x][4]=max(max(seg[x*2][4],seg[x*2+1][4]),max(seg[x*2][2]+seg[x*2+1][0],seg[x*2][0]+seg[x*2+1][3]));
}
#define mid (l+r>>1)
void init(int x,int l,int r){
    if(l==r)laz[x]=v[l];
    else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        eval(x);
    }
}
void update(int x,int l,int r,int a,int b,ll c){
    if(a==l&&b==r)laz[x]+=c;
    else{
        prop(x);
        if(b<=mid)update(x*2,l,mid,a,b,c);
        else if(a>mid)update(x*2+1,mid+1,r,a,b,c);
        else update(x*2,l,mid,a,mid,c),update(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q,i;
    ll w;
    cin>>n>>q>>w;
    ll la=0;
    for(i=0;i<n-1;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].push_back(b);
        in[a].push_back(i);
        d[a].push_back(c);
        g[b].push_back(a);
        in[b].push_back(i);
        d[b].push_back(c);
        e[i]=c;
    }
    dfs(1,-1);
    int m=cur;
    init(1,0,m);
    while(q--){
        int a;
        ll b;
        cin>>a>>b;
        a=(a+la)%(n-1);
        b=(b+la)%w;
        update(1,0,m,f[k[a]],l[k[a]],b-e[a]);
        e[a]=b;
        prop(1);
        printf("%lld\n",la=seg[1][4]);
    }
}