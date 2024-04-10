#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s;
        cin>>n>>s;
        ll ans=s/(n*n);
        cout<<ans<<endl;
    }
    return 0;
}