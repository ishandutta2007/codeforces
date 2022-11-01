#include <iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN=200000;
int cnt[MAXN],t[MAXN],b[MAXN],n,q,a[MAXN],MAX[MAXN],c[MAXN],p[MAXN],ans[MAXN];
vector<int>vec[MAXN],child[MAXN],G[MAXN];
bool mark[MAXN];

void eras(int v)
{
    for(int u:child[v])
        eras(u);
    cnt[t[a[v]]]--;
    t[a[v]]--;
}

void add(int v)
{
    for(int u:child[v])
        add(u);
    t[a[v]]++;
    cnt[t[a[v]]]++;
}

void dfs(int v)
{
    for(int u:child[v])
        if(u!=p[v])
        {
            dfs(u);
            eras(u);
        }
    if(p[v])
        dfs(p[v]);
    t[a[v]]++;
    cnt[t[a[v]]]++;
    for(int u:child[v])
        if(p[v]!=u)
            add(u);
    for(int i=0;i<vec[v].size();i++)
        ans[vec[v][i]]=cnt[b[vec[v][i]]];
}

void dfs1(int v)
{
    mark[v]=true;
    for(int u:G[v])
    {
        if(!mark[u])
        {
            child[v].push_back(u);
            dfs1(u);
            if(c[u]>MAX[v])
            {
                MAX[v]=c[u];
                p[v]=u;
            }
            c[v]+=c[u];
        }
    }
    c[v]++;
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int v,u;
        scanf("%d %d",&v,&u);
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=0;i<q;i++)
    {
        int v;
        scanf("%d %d",&v,&b[i]);
        vec[v].push_back(i);
    }
    dfs1(1);
    dfs(1);
    for(int i=0;i<q;i++)
        printf("%d\n",ans[i]);
}