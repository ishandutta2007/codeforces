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

    int ans=0;
    for(int i=2;i<=n;i++)
    {
        ans+=abs(a[i]-a[i-1]);
    }

    int temp=abs(a[2]-a[1]);
    int y=abs(a[n]-a[n-1]);
    temp=max(temp,y);

    for(int i=2;i<n;i++)
    {
        if(a[i]<a[i-1] && a[i]<a[i+1])
        {
            int x=abs(a[i]-a[i+1]);
            int z=abs(a[i]-a[i-1]);
            y=2*min(x,z);
            temp=max(temp,y);
        }
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
            int x=abs(a[i]-a[i+1]);
            int z=abs(a[i]-a[i-1]);
            y=2*min(x,z);
            temp=max(temp,y);
        }
    }

    ans-=temp;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}