#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
vector<int>a[200009];
int pr[200009];
int par(int x)
{
if(pr[x]==x)return x;
pr[x]=par(pr[x]);
return pr[x];



}
void dfs(int i,int p)
{
if(a[i].size()!=2)return ;
if(p!=0&&pr[i]==i)
{ans++;return ;}
int d=0;
if(a[i][0]==p)d=1;
dfs(a[i][d],i);

}
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)pr[i]=i;
cin>>m;
int x,y;
for(int i=0;i<m;i++)
{
cin>>x>>y;
pr[par(y)]=par(x);
a[x].push_back(y);
a[y].push_back(x);


}
for(int i=1;i<=n;i++) {
if(pr[i]!=i)continue;
dfs(i,0);



}
cout<<ans;


}