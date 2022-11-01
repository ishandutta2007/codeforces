#include<bits/stdc++.h>
using namespace std;
int cot=0,n,m,k,d[200005],f[200005];
vector<int>v[200005];
bool vis[200005],vv[200005];
queue<int>q;
void dfs(int x,int index)
{
    f[x]=index;
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]]) dfs(v[x][i],index);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        d[x]++;
        d[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(d[1]<k) {printf("NO\n");return 0;}
    vis[1]=true;
    for(int i=0;i<v[1].size();i++)
    {
        if(!vis[v[1][i]])
            dfs(v[1][i],++cot);
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<v[1].size();i++)
    {
        if(!vis[f[v[1][i]]])
        {
            vv[v[1][i]]=true;
            vis[f[v[1][i]]]=true;
            q.push(v[1][i]);
        }
    }
    if(q.size()>k) {printf("NO\n");return 0;}
    for(int i=0;i<v[1].size()&&q.size()<k;i++)
    {
        if(!vv[v[1][i]])
        {
            q.push(v[1][i]);
            vv[v[1][i]]=true;
        }
        if(q.size()==k) break;
    }
    printf("YES\n");
    for(int i=0;i<v[1].size();i++)
    {
        if(vv[v[1][i]])
            printf("%d %d\n",1,v[1][i]);
    }
    vv[1]=true;
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=0;i<v[now].size();i++)
        {
            if(!vv[v[now][i]])
            {
                vv[v[now][i]]=true;
                q.push(v[now][i]);
                printf("%d %d\n",now,v[now][i]);
            }
        }
    }
}