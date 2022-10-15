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
    int n,k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans=n;
    for(int j=1;j<=100;j++)
    {
        int temp=0;
        int x=j;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=x)
            {
                temp++;
                i+=(k-1);
            }
        }

        ans=min(ans,temp);
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