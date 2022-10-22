#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int co[200];
/*ll bigMod (ll a, ll e)
 { ll d=a%e;
ll v=MOD%e;
ll ans=0;
while(d!=0){ans++;d=(d+v)%e;}
return ans;


} 
*/
int ans;
int main()
{
int n;
cin>>n;
for(int i=n;i>0;i-=2)ans+=i;
cout<<ans;
return 0;}