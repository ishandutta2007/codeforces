#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
ll t,n,k;
cin>>t;
while(t--)
{
    cin>>n>>k;
    if(k>=n){cout<<1<<endl;continue;}
  ll v=sqrt(n)+1;
  ll u=1;
  for(ll i=2;i<v;i++)
  {
      if(n%i!=0)continue;
      if(i<=k)u=max(u,i);
    if((n/i)<=k)u=max(u,n/i);
  }
  cout<<(n/u)<<endl;
}

    return 0;
}