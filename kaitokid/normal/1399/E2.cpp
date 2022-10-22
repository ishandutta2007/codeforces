#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll>a[200009],fuck[2];
ll f[200009];
//set<pair<ll,pair<ll,ll> >st;
vector<pair<pair<ll,ll>,pair<ll,ll> > >adj;
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
    fuck[0].clear();
    fuck[1].clear();
    cin>>n>>s;
    adj.clear();
    for(int i=1;i<=n;i++)a[i].clear();
    for(int i=0;i<n-1;i++)
    {
        ll u,v,w,c;
        cin>>u>>v>>w>>c;
        a[u].push_back(v);
        a[v].push_back(u);
        adj.push_back({{u,v},{w,c}});

    }
    go(1,0);
    ll rr=0;
    for(int i=0;i<n-1;i++)
    {
        ll u=min(f[adj[i].first.first],f[adj[i].first.second]);
        ll v=adj[i].second.first;
        ll g=adj[i].second.second-1;
        rr+=u*v;
        while(v>0){ll ee=v/2;ll p=u*v-(u*ee);fuck[g].push_back(p);v/=2;}
    }
    sort(fuck[0].begin(),fuck[0].end());
    sort(fuck[1].begin(),fuck[1].end());
    ll l=fuck[0].size(),r=fuck[1].size();
    l--,r--;
    ll res=1e18;
    while(l>=0&&rr>s){rr-=fuck[0][l];l--;}
    l++;
    if(rr<=s){res=fuck[0].size()-l;}
    while(r>=0)
    {
        rr-=fuck[1][r];
 if(rr<=s){       while(rr<=s&&l<fuck[0].size()){rr+=fuck[0][l];l++;}
        if(rr>s){l--;rr-=fuck[0][l];}
        ll pp=fuck[0].size()-l;
        pp+=2*(fuck[1].size()-r);
        res=min(res,pp);
 }
r--;
    }
        cout<<res<<endl;
}
    return 0;
}