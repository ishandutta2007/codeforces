#include<bits/stdc++.h>
using namespace std;

int n,sum=1,ans,f[300000];
bool mark[300000];

void dfs(int v)
{
  mark[v]=true;
  if(!mark[f[v]])
    dfs(f[v]);
}

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>f[i];
      f[i]--;
    }
  for(int i=0;i<n;i++)
    {
      int tmp;
      cin>>tmp;
      sum+=tmp;
    }
  for(int i=0;i<n;i++)
    if(!mark[i])
      ans++,dfs(i);
  cout<<(ans==1?0:ans)+(sum%2)<<endl;
}