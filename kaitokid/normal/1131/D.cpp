#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
int vis[2009],pr[2009];
string s[1009];
bool bl=false;
vector<int>eq[2009],ls[2009];
int p(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=p(pr[x]);
}
int go(int x)
{
    if(bl)return 0;
    if(vis[x]==0){bl=true;return 0;}
if(vis[x]>0)return vis[x];
vis[x]=0;
int ans=0;
for(int i=0;i<ls[x].size();i++)
    ans=max(ans,go(ls[x][i]));
return vis[x]=ans+1;
}
int main()
{
    ios::sync_with_stdio(0);
   cin>>n>>m;
   memset(vis,-1,sizeof vis);
   for(int i=1;i<=n+m;i++)pr[i]=i;
   for(int i=0;i<n;i++)
   {
       cin>>s[i];
       for(int j=0;j<m;j++)
        if(s[i][j]=='=')pr[p(i+1)]=p(n+j+1);}
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
  {
      if(s[i][j]=='>')ls[p(i+1)].push_back(p(j+n+1));
      if(s[i][j]=='<')ls[p(j+n+1)].push_back(p(i+1));
  }
  for(int i=1;i<=n+m;i++)
  {
      if(p(i)==i)go(i);
      if(bl){cout<<"No";return 0;}
  }
  cout<<"Yes\n";
  for(int i=1;i<=n;i++)
    cout<<vis[p(i)]<<" ";
  cout<<endl;
  for(int i=n+1;i<=n+m;i++)cout<<vis[p(i)]<<" ";
    return 0;
}