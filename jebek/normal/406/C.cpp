#include <iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN=100000+100;
int n,m,par[MAXN],h[MAXN];
bool mark[MAXN],mark2[MAXN];
vector<int>G[MAXN],child[MAXN];

void dfs(int v)
{
  //  cout<<v<<"*"<<par[v]<<endl;
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            par[u]=v;
            h[u]=h[v]+1;
            dfs(u);
            if(!mark2[u])
            {
                child[v].push_back(u);
            }
        }
        else if(h[u]<h[v]-1)
            child[v].push_back(u);
    }
    //cout<<child[v].size()<<endl;
    for(int i=0;i+1<child[v].size();i+=2)
    {
        printf("%d %d %d\n",child[v][i],v,child[v][i+1]);
    }
    if(child[v].size()%2==1)
    {
        //cout<<v<<"*"<<par[v]<<" "<<child[v].size()<<endl;
        printf("%d %d %d\n",child[v][child[v].size()-1],v,par[v]);
        mark2[v]=true;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int v,u;
        scanf("%d %d",&v,&u);
        G[v].push_back(u);
        G[u].push_back(v);
    }
    if(m%2==1)
    {
        printf("No solution\n");
        return 0;
    }
    dfs(1);
}