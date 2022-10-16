/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int val(int n,int m)
{
    int y=n%10,ans=0,x;
    n/=10;

    for(int i=1;i<=10;i++)
    {
        x=m*i;
        x%=10;
        ans+=x;
    }

    ans*=n;

    for(int i=1;i<=y;i++)
    {
        x=m*i;
        x%=10;
        ans+=x;
    }

    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    n/=m;
    m%=10;

    int ans=val(n,m);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}