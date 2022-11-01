#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int Dp(ll x)
{
  int ans=0;
  ll k=1,i=2;
  for(;i<=x;i*=2,k++)
      ans+=k-1;
  i--;
  for(ll j=0;j<k-1;j++)
    if(i-(((ll)1)<<j)<=x)
      ans++;
  return ans;
}

int main()
{
  ll a,b;
  cin>>a>>b;
  cout<<Dp(b)-Dp(a-1)<<endl;
}