#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<int>v[100009];
bool draw,bl,vis[100009][2],now[100009];
vector<int>ans;
void go (int x)
{
if(bl)return;
if(ans.size()%2==1&&v[x].size()==0)
{
bl=true;
cout<<"Win\n";
for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
cout<<x;
return;

}
ans.push_back(x);
vis[x][ans.size()%2]++;
now[x]++;

for(int i=0;i<v[x].size();i++)
{
if(now[v[x][i]])draw=true;
if(vis[v[x][i]][(ans.size()+1)%2])continue;
go(v[x][i]);

}

now[x]=false;
ans.pop_back();

}
int main()
{

ios::sync_with_stdio(0);

cin>>n>>m;
int x,l;
for(int i=1;i<=n;i++)
{cin>>l;
while(l--)
{
cin>>x;
v[i].push_back(x);}}
cin>>x;
go(x);
if(bl)return 0;
if(draw)cout<<"Draw";
else cout<<"Lose";

return 0;}