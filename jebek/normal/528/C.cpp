#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;
const int MAXN=110000;
bool mark[MAXN];
int n,m,t1[MAXN],t2[MAXN],par[MAXN],h[MAXN];
vector<pii>ans;
vector<int>G[MAXN],v1,v2;

void dfs(int v)
{
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            h[u]=h[v]+1;
            par[u]=v;
            t1[v]=1-t1[v];t2[u]=1-t2[u];
            dfs(u);
         //   cout<<u<<" "<<t1[u]<<" "<<t2[u]<<endl;
            if((t1[u] && t2[u]) || (t1[u] && v1.size()) || (t2[u] && v2.size()))
                t1[u]=1-t1[u],t2[u]=1-t2[u],t1[v]=1-t1[v],t2[v]=1-t2[v],ans.push_back(pii(u,v));
            else
                ans.push_back(pii(v,u));
            if(t1[u])
            {
                if(v2.size())
                {
                    ans.push_back(pii(u,v2.back()));
                    v2.pop_back();
                }
                else
                    v1.push_back(u);
            }
            if(t2[u])
            {
                if(v1.size())
                {
                    ans.push_back(pii(v1.back(),u));
                    v1.pop_back();
                }
                else
                    v2.push_back(u);
            }
        }
        else
        {
            if(h[u]<=h[v] && u!=par[v])
            {
                ans.push_back(pii(v,u));
                t1[v]=1-t1[v];
                t2[u]=1-t2[u];
            }
            else if(h[u]<h[v])
                par[v]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        if(v!=u)
            G[u].push_back(v);
    }
    dfs(1);
    if(t1[1] && t2[1])
        ans.push_back(pii(1,1));
    else if(t1[1])
    {
        if(v2.size())
        {
            ans.push_back(pii(1,v2.back()));
            v2.pop_back();
        }
        else
            v1.push_back(1);
    }
    else if(t2[1])
    {
        if(v1.size())
        {
            ans.push_back(pii(v1.back(),1));
            v1.pop_back();
        }
        else
            v2.push_back(1);
    }
    while(v1.size())
    {
        ans.push_back(pii(v1.back(),v1.back()));
        ans.push_back(pii(v1[v1.size()-2],v1.back()));
        v1.pop_back(),v1.pop_back();
    }
    while(v2.size())
    {
        ans.push_back(pii(v2.back(),v2.back()));
        ans.push_back(pii(v2.back(),v2[v2.size()-2]));
        v2.pop_back(),v2.pop_back();
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}