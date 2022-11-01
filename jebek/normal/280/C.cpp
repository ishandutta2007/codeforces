#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
long double ans,h[100100];
bool mark[100100];
vector<int>G[100100];

void dfs(int v)
{
    mark[v]=true;
    ans+=1/h[v];
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            h[u]=h[v]+1;
            dfs(u);
        }
    }
}

int main()
{
    cout.precision(8);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    h[1]=1;
    dfs(1);
    cout<<ans<<endl;
}