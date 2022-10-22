#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N=2e5+9;
ll n,sz[N],hvch[N],prch[N],lev[N],pa[N];
vector<pair<ll,ll> >ch[N];
ll edg[N][3],to[N],val[N],pos[N],h[N];
ll MX=1e18;
ll fk(ll x,ll y)
{
    if(x==0)return 0;
    ll u=(MX+x+10)/x;
    if(y>=u)return MX+2;
    return x*y;
}
void dfs1(ll x,ll p)
{
    lev[x]=lev[p]+1;
    pa[x]=p;
    sz[x]=1;
    ll mx=0;
    for(ll i=0;i<ch[x].size();i++)
    {
        if(ch[x][i].first==p)continue;
        dfs1(ch[x][i].first,x);
        sz[x]+=sz[ch[x][i].first];
        if(sz[ch[x][i].first]>sz[mx])mx=ch[x][i].first;
    }
    if(sz[mx]*2>sz[x])hvch[x]=mx;
    else hvch[x]=-1;
}
ll id;
ll sg[4*N];
void dfs2(ll x,ll p,ll u)
{
    if(x==-1)return;
    pos[x]=id;
    h[id++]=val[x];
    prch[x]=u;
    dfs2(hvch[x],x,u);
    for(ll i=0;i<ch[x].size();i++)
        if(ch[x][i].first!=p&&ch[x][i].first!=hvch[x])dfs2(ch[x][i].first,x,ch[x][i].first);
}
ll cal(ll x,ll st,ll en,ll u,ll v)
{
    if(v<u||u>en||v<st)return 1;
    if(st>=u&&en<=v)return sg[x];
    ll mid=st+(en-st)/2;
    return fk(cal(2*x+1,st,mid,u,v),cal(2*x+2,mid+1,en,u,v));
}
ll go(ll x,ll y)
{
    ll ans=1;
    while(prch[x]!=prch[y])
    {
        if(lev[prch[x]]<lev[prch[y]])swap(x,y);
        ans=fk(ans,cal(0,0,n-1,pos[prch[x]],pos[x]));
        x=pa[prch[x]];
    }
    if(lev[x]>lev[y])swap(x,y);
    ans=fk(ans,cal(0,0,n-1,pos[x]+1,pos[y]));
      return ans;

}
void build(ll x=0,ll st=0,ll en=n-1)
{
    if(st==en)
    {
        sg[x]=h[st];
        return;
    }
    ll mid=st+(en-st)/2;
    build(2*x+1,st,mid);
    build(2*x+2,mid+1,en);
    sg[x]=fk(sg[2*x+1],sg[2*x+2]);

}
void chn(ll x,ll st,ll en,ll u,ll v)
{
    if(u>en||u<st)return;
    if(st==en){sg[x]=v;return;}
    ll mid=st+(en-st)/2;
    chn(2*x+1,st,mid,u,v);
    chn(2*x+2,mid+1,en,u,v);
    sg[x]=fk(sg[2*x+1],sg[2*x+2]);
}
int main()
{
    ll m;
 scanf("%lld%lld",&n,&m);
 for(ll i=1;i<=n;i++)ch[i].clear();
 for(ll i=1;i<n;i++)
{

 scanf("%lld%lld%lld",&edg[i][0],&edg[i][1],&edg[i][2]);
    ch[edg[i][0]].push_back({edg[i][1],edg[i][2]});
    ch[edg[i][1]].push_back({edg[i][0],edg[i][2]});
}
dfs1(1,0);
for(ll i=1;i<n;i++)
{
    if(pa[edg[i][0]]==edg[i][1])to[i]=edg[i][0];
    else to[i]=edg[i][1];
    val[to[i]]=edg[i][2];
}
dfs2(1,0,1);
build();
ll t;
while(m--)
{
    ll u,v,z;
    scanf("%lld%lld%lld",&t,&u,&v);
    if(t==2)
        chn(0,0,n-1,pos[to[u]],v);
      else{scanf("%lld",&z);
      printf("%lld\n",(z/go(u,v)));
            }

}

    return 0;
}