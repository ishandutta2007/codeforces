#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll pw(ll x,ll  y)
{
    if(y==0)return 1;
    ll p=pw(x,y/2);
    p=(p*p)%mod;
    if(y%2)p=(p*x)%mod;
    return p;
}
vector<pair<int,pair<ll,ll> > >v[200009];
ll p[200009],mx[200009],cur[200009],ans;

vector<pair<int,int> > cal(int x)
{
    vector<pair<int,int> >res;
    while(x>1)
    {
        int u=p[x];
        int f=0;
        while(x%u==0){f++;x/=u;}
        res.push_back({u,f});
    }
    return res;
}
ll inv(int x)
{
    return pw(x,mod-2);
}
void dfs(int x,int pr,ll val)
{
    ans=(ans+val)%mod;
    for(int i=0; i<v[x].size();i++)
    {
        if(v[x][i].first==pr)continue;
        ll u=v[x][i].second.first;
        ll r=v[x][i].second.second;
        ll f=(val*u)%mod;
        f=(f*inv(r))%mod;
        dfs(v[x][i].first,x,f);
    }
}
void go(int x,int pr)
{
    for(int i=0; i<v[x].size();i++)
    {
        if(v[x][i].first==pr)continue;
        int u=v[x][i].second.first;
        int r=v[x][i].second.second;
        vector<pair<int,int> >g,h;
        g=cal(u);
        for(int i=0;i<g.size();i++)cur[g[i].first]+=g[i].second;
        h=cal(r);
        for(int i=0;i<h.size();i++){cur[h[i].first]-=h[i].second;mx[h[i].first]=min(mx[h[i].first],cur[h[i].first]);}
        go(v[x][i].first,x);
        for(int i=0;i<g.size();i++)cur[g[i].first]-=g[i].second;
        for(int i=0;i<h.size();i++)cur[h[i].first]+=h[i].second;


    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=2;i<=1000;i++)
    {
        if(p[i])continue;
        for(int j=i*i;j<=200000;j+=i)p[j]=i;
    }
    for(int i=2;i<=200000;i++)if(p[i]==0)p[i]=i;
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){mx[i]=cur[i]=0;v[i].clear();}
    for(int i=0;i<n-1;i++)
    {
        int x,y,u,r;
        cin>>x>>y>>u>>r;
        int g=__gcd(u,r);
        u/=g;
        r/=g;
        v[x].push_back({y,{r,u}});
        v[y].push_back({x,{u,r}});

    }
   go(1,0);
   ll tmp=1;
   for(int i=1;i<=n;i++)
   {
       mx[i]*=-1;
       if(mx[i]!=0)tmp=(tmp*pw(i,mx[i]))%mod;
   }
   ans=0;
   dfs(1,0,tmp);
   cout<<ans<<endl;

}
}