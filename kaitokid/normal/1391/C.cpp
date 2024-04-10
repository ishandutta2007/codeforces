#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main()
{
ios::sync_with_stdio(0);
ll ans=1,u=1,n;
cin>>n;
ans=n;
for(int i=1;i<=n-1;i++)
{
    ans*=i;
    ans%=mod;
    u*=2;
    u%=mod;
}
ans-=u;
if(ans<0)ans+=mod;
cout<<ans;
    return 0;
}