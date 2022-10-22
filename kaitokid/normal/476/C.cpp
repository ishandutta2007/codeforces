#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =2e9+14;
int main()
{ios::sync_with_stdio(0);
ll a,b;
cin>>a>>b;
ll ans=0;
for(int i=1;i<b;i++)
{
ll st=(i*b+i)%MOD;

ll plus=(i*b)%MOD;

ll en =(st+(a-1)*plus)%MOD;
ll p=(st+en)/2;
p=(p*a)%MOD;
if((st+en)%2!=0)
p=(p+a/2)%MOD;
ans=(ans+p)%MOD;


}
cout<<ans%(MOD/2);
return 0;}