#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[200009],pr[200009];
vector<int>ed[200009];
bool vis[200009];
void go(int x,int p)
{
    pr[x]=p;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)go(ed[x][i],x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int st,en;
        cin>>n>>k>>st>>en;
        for(int i=0;i<k;i++)cin>>a[i];
        for(int i=1;i<=n;i++){ed[i].clear();vis[i]=0;}
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            ed[u].push_back(v);
            ed[v].push_back(u);

        }
        go(st,0);
        int ans=0;
        vis[st]=1;
        while(en!=st){ans++;vis[en]=true;en=pr[en];}

        for(int i=0;i<k;i++)
        {
            int u=a[i];
            while(!vis[u]){ans+=2;vis[u]=true;u=pr[u];}
        }
        cout<<ans<<endl;
    }

    return 0;

}