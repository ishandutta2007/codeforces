#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,d[200005];
vector<int>v[200005];
bool vis[200005];
queue<int>q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        d[x]++;
        d[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int p=0;
    for(int i=1;i<=n;i++)
        if(d[i]>d[p]) p=i;
    vis[p]=true;
    q.push(p);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<v[now].size();i++)
        {
            if(!vis[v[now][i]])
            {
                vis[v[now][i]]=true;
                printf("%d %d\n",now,v[now][i]);
                q.push(v[now][i]);
            }
        }
    }
}