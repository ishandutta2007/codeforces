#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=200000;
int n,m,t,ans;
vector<int>vec,topo,G[MAXN],G1[MAXN];
bool mark[MAXN],mark1[MAXN],mark2[MAXN];

void dfs2(int v)
{
    mark1[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark1[u])
            dfs2(u);
    }
    for(int i=0;i<G1[v].size();i++)
    {
        int u=G1[v][i];
        if(!mark1[u])
            dfs2(u);
    }
    vec.push_back(v);
}

void dfs(int v)
{
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
            dfs(u);
    }
    topo.push_back(v);
}

void dfs1(int v)
{
   // cout<<v<<endl;
    mark2[v]=true;
    t++;
    for(int i=0;i<G1[v].size();i++)
    {
        int u=G1[v][i];
        if(!mark2[u])
            dfs1(u);
    }
}

void scc(int v)
{
  //  cout<<"*"<<endl;
    vec.clear();
    topo.clear();
    dfs2(v);
    for(int i=0;i<vec.size();i++)
        if(!mark[vec[i]])
            dfs(vec[i]);
    bool ok=true;
 //   for(int i=0;i<topo.size();i++)
   //     cout<<topo[i]<<" "<<mark2[topo[i]]<<endl;
   // cout<<endl;
    for(int i=topo.size()-1;i>-1 && ok;i--)
        if(!mark2[topo[i]])
        {
            t=0;
        //    cout<<"#"<<endl;
            dfs1(topo[i]);
            if(t>1)
                ok=false;
        }
    if(ok)
        ans--;
}

int main()
{
    cin>>n>>m;
    ans=n;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G1[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!mark1[i])
            scc(i);
    }
    cout<<ans<<endl;
}