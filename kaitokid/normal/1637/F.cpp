#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
ll h[200009];
vector<ll>v[200009];
ll r;
ll go(int x,int pr)
{
    if(x!=r)
    {
        ll u=0;
        for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=pr)u=max(u,go(v[x][i],x));
        if(h[x]>u)ans+=h[x]-u;
        return max(h[x],u);
    }
vector<ll>g;
g.push_back(0);
for(int i=0;i<v[x].size();i++)
        g.push_back(go(v[x][i],x));
sort(g.begin(),g.end());
reverse(g.begin(),g.end());
ans+=2*h[x]-g[0]-g[1];
}
int main()
{
    ll n;
    cin>>n;
    r=0;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        if(h[i]>h[r])r=i;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    go(r,0);
    cout<<ans;
    return 0;
}