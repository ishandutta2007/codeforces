#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009],p[100009],g[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
  ll n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<n;i++)
  {
      p[i]=p[i-1];
      if(a[i]>a[i+1])
        p[i]+=a[i]-a[i+1];
  }
  g[n+1]=0;
  for(int i=n;i>1;i--)
  {
      g[i]=g[i+1];
      if(a[i]>a[i-1])
        g[i]+=a[i]-a[i-1];
  }
  while(m--)
  {
      int x,y;
      cin>>x>>y;
      if(y>x){
      cout<<p[y-1]-p[x-1]<<endl;
      continue;}
      if(y<x)
      {
          cout<<g[y+1]-g[x+1]<<endl;
          continue;
      }
      cout<<0<<endl;
  }
    return 0;
}