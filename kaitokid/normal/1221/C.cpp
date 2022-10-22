#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int q,n,a[60];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

cin>>q;
while(q--)
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=(a+b+c)/3;
    ans=min(ans,a);
    ans=min(ans,b);
    cout<<ans<<endl;
}
  return 0;
}