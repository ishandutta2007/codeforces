#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
    ll ans=(a+b)/3;
    ans=min(ans,min(a,b));
    cout<<ans<<endl;
    }
    return 0;
}