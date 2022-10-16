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

    int dec[n+1],inc[n+1];
    dec[1]=a[1];
    inc[1]=0;

    for(int i=2;i<=n;i++)
    {
        if(a[i]<inc[i-1]) { cout<<"NO"<<endl; return; }

        if( a[i]-dec[i-1] >= inc[i-1] ) { dec[i]=dec[i-1]; inc[i]=a[i]-dec[i]; }
        else
        {
            inc[i]=inc[i-1];
            dec[i]=a[i]-inc[i];
        }
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}