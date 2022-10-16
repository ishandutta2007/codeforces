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

    int ans=1;
    int cnt=0;
    int chi=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]>a[i])
        {
            if(cnt==0)
            {
                cnt=chi-1;
                ans++;
                chi=1;
            }
            else { cnt--; chi++; }
        }
        else chi++;
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