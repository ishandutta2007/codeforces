#include <iostream>

using namespace std;
typedef long long ll;
ll mod=998244353;
ll n,x,co[200009],ans=1;
int main()
{


  cin>>n;
  for(int i=0;i<2*n-2;i++)
  {
      cin>>x;
      co[x]++;
      ans=(ans*co[x])%mod;
  }
  ans=(ans*n)%mod;
  cout<<ans;
    return 0;
}