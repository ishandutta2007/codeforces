/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    int nC2[n+1]={0};
    for(int i=2;i<=n;i++) nC2[i]=( (i*(i-1))/2 );

    int j=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        while(j<=n && a[j]<=a[i]+2) j++;

        ans+=nC2[j-i-1];
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