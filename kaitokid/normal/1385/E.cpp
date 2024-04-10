#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
vector<int>v[2][200009];
vector<pair<int,int> >ed;
int vis[200009];
bool ans;
void go(int x)
{
    if(ans)return;
    vis[x]=1;
    for(int i=0;i<v[1][x].size();i++)
    {
        int u=v[1][x][i];
        if(vis[u]==1){ans=true;return;}
        ed.push_back({x,u});
     if(vis[u]==0)   go(u);
    }
    for(int i=0;i<v[0][x].size();i++)
    {
        int u=v[0][x][i];
        if(vis[u]==2)ed.push_back({x,u});
    }
    vis[x]=2;
}
int main()
{
ios::sync_with_stdio(0);
int t,n,x;
cin>>t;
while(t--)
{
cin>>n>>m;
for(int i=1;i<=n;i++){v[0][i].clear();v[1][i].clear();vis[i]=0;}
ed.clear();
ans=false;
int u,x,y;
for(int i=0;i<m;i++)
{
    cin>>u>>x>>y;
    //if(u==0)ed.push_back({x,y});
v[u][x].push_back(y);
if(u==0)v[u][y].push_back(x);
}
for(int i=1;i<=n;i++)
{
    if(vis[i]==0)go(i);
    if(ans)break;
}
if(ans){cout<<"NO\n";continue;}
cout<<"YES\n";
for(int i=0;i<m;i++)
    cout<<ed[i].first<<" "<<ed[i].second<<endl;
}
    return 0;
}
/*4
3 1
0 1 3
5 5
0 2 1
1 1 5
1 5 4
0 5 2
1 3 5
4 5
1 1 2
0 4 3
1 3 1
0 2 3
1 2 4
4 5
1 4 1
1 1 3
0 1 2
1 2 4
1 3 2
*/