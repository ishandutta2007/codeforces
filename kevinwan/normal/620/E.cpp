#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=4e5+10;
vector<int> g[mn];
int o[mn],s[mn];
ll v[mn];
ll seg[mn<<1],laz[mn<<1];
int cnt=0,n;
inline void apply(int x){
    if(laz[x]){
        seg[x]=laz[x];
        if(x<n){
            laz[x*2]=laz[x*2+1]=laz[x];
        }
        laz[x]=0;
    }
}
inline void down(int x){
    for(int sh=31-__builtin_clz(x);sh>=0;sh--){
        int i=x>>sh;
        apply(i);
        apply(i^1);
    }
}
inline void up(int x){
    for(x>>=1;x;x>>=1)seg[x]=(seg[x*2]|seg[x*2+1]);
}
inline void update(int l,int r,ll x){
    l+=n,r+=n;
    down(l),down(r);
    int l0=l,r0=r;
    while(l<=r){
        if(l&1)laz[l++]=x;
        if(!(r&1))laz[r--]=x;
        l>>=1,r>>=1;
    }
    down(l0),down(r0),up(l0),up(r0);
}
inline ll query(int l,int r){
    l+=n,r+=n;
    down(l),down(r);
    ll ans=0;
    while(l<=r){
        if(l&1)ans|=seg[l++];
        if(!(r&1))ans|=seg[r--];
        l>>=1,r>>=1;
    }
    return ans;
}
void dfs(int x,int p){
    o[x]=cnt++;
    s[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        s[x]+=s[y];
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int m,i,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>v[i],v[i]=1LL<<v[i]-1;
    for(i=0;i<n-1;i++)cin>>a>>b,g[a].push_back(b),g[b].push_back(a);
    dfs(1,0);
    for(i=1;i<=n;i++)seg[n+o[i]]=v[i];
    for(i=n-1;i;i--)seg[i]=(seg[i*2]|seg[i*2+1]);
    while(m--){
        cin>>a;
        if(a==1){
            cin>>a>>b;
            update(o[a],o[a]+s[a]-1,1LL<<b-1);
        }
        else{
            cin>>a;
            printf("%d\n",__builtin_popcountll(query(o[a],o[a]+s[a]-1)));
        }
    }
}