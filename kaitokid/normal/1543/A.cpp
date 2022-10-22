#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a==b){cout<<0<<" "<<0<<endl;continue;}
        ll u=abs(a-b);
        ll ans=min((a%u),u-(a%u));
        cout<<u<<" "<<ans<<endl;

    }
    return 0;
}