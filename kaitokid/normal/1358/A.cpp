#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll ans=(n*m+1)/2;
        cout<<ans<<endl;
    }
    return 0;
}