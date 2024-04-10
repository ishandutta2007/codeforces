#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
queue<int>ans;
int n,m,x,y;
vector<int>v[100005];
bool vis[100005];
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    q.push(1);
    vis[1]=true;
    while(!q.empty())
    {
        int now=q.top();q.pop();
        ans.push(now);
        for(int i=0;i<v[now].size();i++)
        {
            if(!vis[v[now][i]])
            {
                vis[v[now][i]]=true;
                q.push(v[now][i]);
            }
        }
    }
    while(!ans.empty())
    {
        int now=ans.front();ans.pop();
        if(ans.empty()) printf("%d\n",now);
        else printf("%d ",now);
    }
}