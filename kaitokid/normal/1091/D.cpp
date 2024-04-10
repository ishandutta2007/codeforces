#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int mod=998244353;
int main()
{
ios::sync_with_stdio(0);
int n;
cin>>n;
ll ans=1;
for(int i=1;i<=n+1;i++)
ans=(ans*i)%mod;
ll d=1;
for(int i=n;i>0;i--)
{
d=(d*i)%mod;
ans-=d;
if(ans<0)ans+=mod;


}
  cout<<ans;  
return 0;
}