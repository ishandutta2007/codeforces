#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=400;
bool mark[MAXN],isprime[30000];
vector<int>ans[MAXN],G[MAXN],v1,v2;
int n,k,c[MAXN][MAXN],a[MAXN],s,t;

void dfs1(int v)
{
    mark[v]=true;
    ans[k].push_back(v);
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
            dfs1(u);
    }
}

bool dfs(int v)
{
    if(v==t)
        return true;
    mark[v]=true;
    for(int i=0;i<=n+1;i++)
    {
        int u=i;
        if(!mark[u] && c[v][u]>0 && dfs(u))
       {
           c[v][u]--;
           c[u][v]++;
           return true;
       }
    }
    return false;
}

void run()
{
    for(int i=2;i<=20000;i++)
        if(!isprime[i])
        {
            for(int j=i*i;j<=20000;j+=i)
                isprime[j]=true;
        }
}

int main()
{
    run();
    cin>>n;
    s=0,t=n+1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            v1.push_back(i);
        else
            v2.push_back(i);
    }
    if(v1.size()!=v2.size())
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int i=0;i<v1.size();i++)
    {
        c[s][v1[i]]=2;
        c[v2[i]][t]=2;
        for(int j=0;j<v2.size();j++)
        {
            if(!isprime[a[v1[i]]+a[v2[j]]])
            {
                c[v1[i]][v2[j]]=1;
            }
        }
    }
    for(int i=0;i<2*v1.size();i++)
    {
        if(dfs(s))
            memset(mark,false,sizeof mark);
        else
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
     for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            if(!isprime[a[v1[i]]+a[v2[j]]] && c[v1[i]][v2[j]]==0)
            {
                G[v1[i]].push_back(v2[j]);
                G[v2[j]].push_back(v1[i]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(!mark[i])
        {
            dfs1(i);
            k++;
        }
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<ans[i].size()<<" ";
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}