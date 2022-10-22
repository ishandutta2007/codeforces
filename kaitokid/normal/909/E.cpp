#include <bits/stdc++.h>

using namespace std;
int num[100009],pro[100009],n,m,ans;
vector<int>v[100009];
queue<int>q[2];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>pro[i];
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        num[x]++;
        v[y].push_back(x);
    }
    for(int i=0;i<n;i++)
        if(!num[i])q[pro[i]].push(i);
while(!q[0].empty()||!q[1].empty())
{
    while(!q[0].empty())
    {
        int u=q[0].front();
        q[0].pop();
        for(int i=0;i<v[u].size();i++){int g=v[u][i];num[g]--;if(!num[g])q[pro[g]].push(g);}
    }
if(q[1].empty())break;
ans++;
while(!q[1].empty())
    {
        int u=q[1].front();
        q[1].pop();
        for(int i=0;i<v[u].size();i++){int g=v[u][i];num[g]--;if(!num[g])q[pro[g]].push(g);}
    }
}
cout<<ans;
    return 0;
}