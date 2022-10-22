#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[38],b[38],ans;
ll g(ll x)
{
    return (x*(x+1))/2;
}
int main()
{ios::sync_with_stdio(0);
ll t,n,k;
cin>>t;
while(t--)
{
    cin>>n;
  k=n/2;
  ans=0;
  for(ll i=1;i<=k;i++)ans+=2*(i)*i+i+2*(g(k)-g(i));
  ans*=2;
  ans+=2*g(k);
  cout<<ans<<endl;
}
    return 0;
}