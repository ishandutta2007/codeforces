#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[2009];
int vis[2009][2009],n,m,x,y,c,r;
int main()
{ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
cin>>r>>c;
cin>>x>>y;
r--,c--;
for(int i=0;i<n;i++)
    cin>>s[i];
deque<pair<int,int> >q;
memset(vis,-1,sizeof vis);
q.push_back({r,c});
vis[r][c]=0;
while(!q.empty())
{
    int u=q.front().first,v=q.front().second;
    q.pop_front();
    if(u>0&&(vis[u-1][v]==-1||vis[u-1][v]>vis[u][v])&&s[u-1][v]=='.'){vis[u-1][v]=vis[u][v];q.push_front({u-1,v});}
    if(u<n-1&&(vis[u+1][v]==-1||vis[u+1][v]>vis[u][v])&&s[u+1][v]=='.'){vis[u+1][v]=vis[u][v];q.push_front({u+1,v});}
    if(v>0&&(vis[u][v-1]==-1||vis[u][v-1]>vis[u][v])&&s[u][v-1]=='.'){vis[u][v-1]=vis[u][v];q.push_front({u,v-1});}
    if(v<m-1&&(vis[u][v+1]==-1||vis[u][v+1]>vis[u][v]+1)&&s[u][v+1]=='.'){vis[u][v+1]=vis[u][v]+1;q.push_back({u,v+1});}

}
    int ans=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++)
{
     if(vis[i][j]==-1||vis[i][j]>y)continue;
    int z=vis[i][j]+(c-j);
    if(z<=x)ans++;
}}
cout<<ans;
    return 0;
}