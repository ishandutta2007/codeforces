#include<bits/stdc++.h>
using namespace std;
int a[200009],ans[200009];
vector<int>r[200009];
void df(int i,bool bl,int sum,int par)
{if(sum==1)return ;
//cout<<i<<" "<<sum<<endl;
if(bl==1)
{int res=__gcd(sum,a[i]);
if(res==1||res==ans[i])return ;
if(res>ans[i]){ans[i]=res;}
for(int j=0;j<r[i].size();j++){if(r[i][j]!=par)df(r[i][j],1,res,i);}
return ;}
int res1=__gcd(sum,a[i]);
int res2=sum;
if(res2>ans[i])ans[i]=res2;
if(res2==1)return;

if(res1!=res2){for(int j=0;j<r[i].size();j++){if(r[i][j]==par)continue;df(r[i][j],1,res2,i);df(r[i][j],0,res1,i);}return;}
for(int j=0;j<r[i].size();j++){if(r[i][j]==par)continue;df(r[i][j],0,res1,i);}
return;
}
int main()
{ios::sync_with_stdio(0);
int n,x,y;
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=0;i<n-1;i++)
{cin>>x>>y;r[x].push_back(y);r[y].push_back(x);}
df(1,0,a[1],-1);
df(1,0,0,-1);
for(int i=1;i<=n;i++)
cout<<max(1,ans[i])<<" ";
return 0;
}