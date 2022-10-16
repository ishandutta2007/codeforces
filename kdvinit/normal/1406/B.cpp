/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);
    int ans=1;
    for(int i=n-5+1;i<=n;i++) ans*=a[i];

    for(int j=1;j<=5;j++)
    {
        int temp=1;
        for(int i=n-4+j;i<=n;i++) temp*=a[i];
        for(int i=1;i<=j;i++) temp*=a[i];
        ans=max(ans,temp);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}