#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=300000;
int n,m,h[MAXN],par[MAXN];
typedef pair<int,int> pii;
vector<int>G[MAXN],ans1,ans2,ans3;
bool mark[MAXN],f[MAXN];
pii P[MAXN];

void ok(int v,int u,int a,int b)
{
    cout<<"YES"<<endl;
    if(h[u]>h[b])
        swap(u,b),swap(a,v);
  //  cout<<v<<" "<<u<<" "<<a<<" "<<b<<endl;
    int w=b;
    ans1.push_back(b);
    ans2.push_back(b);
    while(w!=u)
    {
        w=par[w];
        ans1.push_back(w);
    }
    ans1.push_back(v);
    ans2.push_back(a);
    while(h[v]>h[a])
    {
        v=par[v];
        ans1.push_back(v);
    }
    while(h[v]<h[a])
    {
        a=par[a];
        ans2.push_back(a);
    }
    while(v!=a)
    {
        a=par[a];
        ans2.push_back(a);
        v=par[v];
        ans1.push_back(v);
    }
    while(v!=b)
    {
        ans3.push_back(v);
        v=par[v];
    }
    ans3.push_back(b);
    reverse(ans3.begin(),ans3.end());
    cout<<ans1.size()<<" ";
    for(int i=0;i<ans1.size();i++)
        cout<<ans1[i]<<" ";
    cout<<endl;
    cout<<ans2.size()<<" ";
    for(int i=0;i<ans2.size();i++)
        cout<<ans2[i]<<" ";
    cout<<endl;
    cout<<ans3.size()<<" ";
    for(int i=0;i<ans3.size();i++)
        cout<<ans3[i]<<" ";
    cout<<endl;
    exit(0);
}

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
            dfs(u);
        }
        else if(h[u]+1<h[v])
        {
           int w=v;
           while(w!=u)
           {
              // cout<<w<<" "<<u<<" "<<f[w]<<endl;
               if(f[w])
                   ok(P[w].first,P[w].second,v,u);
               f[w]=true;
               P[w]=pii(v,u);
               w=par[w];
           }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
            dfs(i);
    cout<<"NO"<<endl;
}