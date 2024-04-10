#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],n;
ll k;
int f[200009],vis[200009];
bool cyc;
vector<int>v[200009];
int lmt;
int go(int x)
{
    if(vis[x]==2)return f[x];
    if(vis[x]==1){cyc=true;return 0;}
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(a[u]>lmt)continue;
        f[x]=max(f[x],go(u));
    }
    vis[x]=2;
    f[x]++;
    return f[x];

}
bool ch(int x)
{
    for(int i=1;i<=n;i++)f[i]=0,vis[i]=0;
    int mx=0;
    cyc=false;
    lmt=x;
    for(int i=1;i<=n;i++)
        {
            if(a[i]<=lmt)mx=max(mx,go(i));
        }
        if(cyc || mx>=k)return true;
        return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    int l=1,r=1e9;
    if(!ch(r)){cout<<-1;return 0;}
    while(l<r)
    {
        int mid=(l+r)/2;
        if(ch(mid))r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}