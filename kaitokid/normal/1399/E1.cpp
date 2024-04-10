#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll>a[200009],fuck;
ll f[200009];
//set<pair<ll,pair<ll,ll> >st;
vector<pair<pair<ll,ll>,ll> >adj;
ll go(int x,int pr)
{
    if(x!=1&&a[x].size()==1)return f[x]=1;
    ll u=0;
    for(int i=0;i<a[x].size();i++)
        if(a[x][i]!=pr)u+=go(a[x][i],x);
    return f[x]=u;
}
int main()
{
ios::sync_with_stdio(0);
ll n,s,t;
cin>>t;
while(t--)
{
    fuck.clear();
    cin>>n>>s;
    adj.clear();
    for(int i=1;i<=n;i++)a[i].clear();
    for(int i=0;i<n-1;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(v);
        a[v].push_back(u);
        adj.push_back({{u,v},w});

    }
    go(1,0);
    ll rr=0;
    for(int i=0;i<n-1;i++)
    {
        ll u=min(f[adj[i].first.first],f[adj[i].first.second]);
        ll v=adj[i].second;
        rr+=u*v;
        while(v>0){ll ee=v/2;ll p=u*v-(u*ee);fuck.push_back(p);v/=2;}
    }
    sort(fuck.begin(),fuck.end());
    ll res=0;
    ll d=fuck.size()-1;
    while(rr>s)
    {
        res++;
        rr-=fuck[d];
        d--;
    }
        cout<<res<<endl;
}
    return 0;
}