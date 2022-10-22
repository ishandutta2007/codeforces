#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n;
vector<int>ed[200009],r[200008];
ll a[200009],b[200009],d[200009];
bool vis[200008];
ll go (int x)
{
    if(d[x]!=-1e18)return d[x];
    d[x]=a[x];
    for(int i=0;i<ed[x].size();i++)
    {
        ll u=go(ed[x][i]);
        if(u>0){d[x]+=u;r[x].push_back(ed[x][i]);}
        else r[ed[x][i]].push_back(x);
    }
    return d[x];
}
void fuck(int x)
{
    if(vis[x])return;
    vis[x]=true;
    for(int i=0;i<r[x].size();i++)fuck(r[x][i]);
    cout<<x<<" ";
}
int main()
{

    ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++){cin>>a[i];d[i]=-1e18;}
for(int i=1;i<=n;i++){cin>>b[i];if(b[i]!=-1)ed[b[i]].push_back(i);}
ll ans=0;
for(int i=1;i<=n;i++)
{
    //cout<<i<<" "<<go(i)<<endl;
    ans+=go(i);
}
cout<<ans<<endl;
for(int i=1;i<=n;i++)fuck(i);
    return 0;
}