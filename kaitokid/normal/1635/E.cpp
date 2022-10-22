#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
vector<int>ed[200009];
int cl[200009];
int t[200009],x[200009],y[200009];
bool g;
void go(int x,int c)
{
    if(cl[x]==c)return;
    if(cl[x]!=0){g=false;return;}
    cl[x]=c;
    c=3-c;
    for(int i=0;i<ed[x].size();i++)go(ed[x][i],c);
}
int vis[200009];
vector<int>topo;
void dfs(int x)
{
    if(vis[x]==1){g=false;return;}
    if(vis[x]==2)return;
    vis[x]=1;
    for(int i=0;i<ed[x].size();i++)dfs(ed[x][i]);
    vis[x]=2;
    topo.push_back(x);
}
int ans[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>t[i]>>x[i]>>y[i];
        ed[x[i]].push_back(y[i]);
        ed[y[i]].push_back(x[i]);
    }
    g=true;
    for(int i=1;i<=n;i++)if(cl[i]==0)go(i,1);
    if(g==false){cout<<"NO";return 0;}
    for(int i=1;i<=n;i++)ed[i].clear();
    for(int i=0;i<m;i++)
    {
        if(t[i]==1)
        {
            if(cl[x[i]]==1)ed[y[i]].push_back(x[i]);
            else ed[x[i]].push_back(y[i]);
            continue;
        }

            if(cl[x[i]]==2)ed[y[i]].push_back(x[i]);
            else ed[x[i]].push_back(y[i]);
    }
    for(int i=1;i<=n;i++)
    if(vis[i]==0)dfs(i);
    if(g==false){cout<<"NO";return 0;}
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)ans[topo[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(cl[i]==1)cout<<"L ";else cout<<"R ";
        cout<<ans[i]<<endl;
    }

    return 0;
}