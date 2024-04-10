#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    ll n,r;
    cin>>n>>r;
    ll ans=0;
    if(r>=n){ans++;r=(n-1);}
    ans+=(r*(r+1))/2;
    cout<<ans<<endl;
}
return 0;
}