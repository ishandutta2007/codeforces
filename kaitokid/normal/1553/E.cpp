#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300009],pos[300009];
int fr[300009],n,m;
int b[300009];
bool vis[300009];
bool ch(int x)
{
    for(int i=0;i<n;i++)vis[i]=false;
    int z=1;
    for(int i=x;i<n;i++)b[i]=z++;
    for(int i=0;i<x;i++)b[i]=z++;
    int cy=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i])continue;
        vis[i]=true;
        cy++;
        int u=pos[b[i]];
        while(u!=i)
        {
            vis[u]=true;
            u=pos[b[u]];
        }

    }
   if(n-cy<=m)return true;
   return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
        fr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int r=i-a[i]+1;
        if(r<0)r+=n;
        fr[r]++;
    }
    vector<int>ans;
    int u=(n/3);
    for(int i=0;i<n;i++)
    {
        if(fr[i]<u)continue;
        if(ch(i))ans.push_back(i);

    }
    cout<<ans.size()<<" ";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
    }
    return 0;
}