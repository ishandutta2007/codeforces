#include <iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

typedef pair<int,int> pii;
const int MAXN=10000;
bool mark[MAXN];
int ans[MAXN],n,a;
deque<pii>d[MAXN];
vector<int>G[MAXN],W1[MAXN],W[MAXN],child[MAXN];

void add(int ind,pii P)
{
    d[ind].push_front(P);
    int i=0;
    while(i<d[ind].size()-1 && d[ind][i]<d[ind][i+1])
    {
        swap(d[ind][i],d[ind][i+1]);
        i++;
    }
}

void dfs1(int v)
{
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            child[v].push_back(u);
            W[v].push_back(W1[v][i]);
            dfs1(u);
        }
    }
}

void dfs(int v,int q)
{
    mark[v]=true;
    for(int i=0;i<child[v].size();i++)
    {
        int u=child[v][i],w=W[v][i];
        for(int j=0;j<w && d[u].size()>0;j++)
        {
            add(v,d[u].back());
            if(v==1)
                ans[d[u].back().second]=q;
            d[u].pop_back();
        }
        dfs(u,q);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        d[i].push_back(pii(a,i));
    }
    for(int i=1;i<n;i++)
    {
        int v,u,w;
        cin>>v>>u>>w;
        G[v].push_back(u);
        G[u].push_back(v);
        W1[v].push_back(w);
        W1[u].push_back(w);
    }
    dfs1(1);
    for(int i=1;i<=n;i++)
        dfs(1,i);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}