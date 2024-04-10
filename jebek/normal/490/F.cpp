#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=10000;
vector<int>vec,G[MAXN],ind[MAXN];
int n,a[MAXN],ans,f[MAXN];
bool mark[MAXN];

void dfs(int v)
{
    mark[v]=true;
    if(vec.size()==0 || vec.back()<a[v])
    {
        ind[vec.size()].push_back(v);
        f[v]=vec.size();
        vec.push_back(a[v]);
    }
    else
    {
        int k=lower_bound(vec.begin(),vec.end(),a[v])-vec.begin();
        vec[k]=a[v];
        f[v]=k;
        ind[k].push_back(v);
    }
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
            dfs(u);
    }
    int k=f[v];
    ans=max(ans,(int)vec.size());
    ind[k].pop_back();
    if(ind[k].size()==0)
        vec.pop_back();
    else
        vec[k]=a[ind[k].back()];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        memset(mark,false,sizeof mark);
        dfs(i);
    }
    cout<<ans<<endl;
}