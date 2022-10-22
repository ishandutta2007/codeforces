#include <iostream>

using namespace std;
int n,d,e;
int main()
{
  ios::sync_with_stdio(0);
  cin>>n>>d>>e;
  int mn=min(5*e,d),mx=max(5*e,d);
  int ans=n;
  while(n>=0)
  {
      ans=min(ans,n%mn);
      n-=mx;

  }

  cout<<ans;
    return 0;
}