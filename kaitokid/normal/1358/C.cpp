#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t;
int main()
{
    ios::sync_with_stdio(0);
cin>>t;
   ll a,b,x,y;
   while(t--)
   {
       cin>>a>>b>>x>>y;
       ll ans=(x-a)*(y-b)+1;
       cout<<ans<<endl;
   }
    return 0;
}