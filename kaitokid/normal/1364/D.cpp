#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int>v[100009];
vector<int>h[2];
int k;
bool vis[100009];
bool p[100009];
int pr[100009];
void fuck(int x,int y)
{
   cout<<2<<endl;
   //cout<<x<<" "<<y<<endl;
   queue<int>q;
   pr[x]=x;
   q.push(x);
   while(!q.empty())
   {
      // cout<<x<<" "<<pr[x]<<endl;
       int u=q.front();
       q.pop();
       for(int i=0;i<v[u].size();i++)if(pr[v[u][i]]==0){if(u==x&&v[u][i]==y)continue;pr[v[u][i]]=u;
       q.push(v[u][i]);}
   }

   vector<int>ans;
   while(y!=x){ans.push_back(y);y=pr[y];}
   ans.push_back(x);
   cout<<ans.size()<<endl;
   for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";

}
void go(int x,int pr,int u)
{
    if(h[0].size()==(k+1)/2||h[1].size()==(k+1)/2)return;
    h[u].push_back(x);
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==pr)continue;
    if(!vis[v[x][i]])    go(v[x][i],x,1-u);
    }
}
int main()
{
    ios::sync_with_stdio(0);
int n,m,x,y;
cin>>n>>m>>k;
for(int i=0;i<m;i++)
{
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
go(1,0,0);
int r;
if(h[0].size()==(k+1)/2)r=0;else r=1;
for(int i=0;i<(k+1)/2;i++)p[h[r][i]]=true;
for(int i=1;i<=n;i++)
{
    if(!p[i])continue;

    for(int j=0;j<v[i].size();j++){if(p[v[i][j]]){fuck(i,v[i][j]);return 0;}}
}
cout<<1<<endl;
for(int i=0;i<(k+1)/2;i++)cout<<h[r][i]<<" ";
      return 0;
}