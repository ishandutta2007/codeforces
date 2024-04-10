#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,x,y;

int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)

{
    cin>>x>>y>>n;
    ll ans=y;
    ll d=(n-y)/x;
    ans+=d*x;
    cout<<ans<<endl;
}    return 0;
}