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

    int freq[2*n+5]={0};
    for(int i=1;i<=n;i++)
    {
        if(freq[a[i]]==0) freq[a[i]]=1;
        else
        {
            a[i]++;
            freq[a[i]]=1;
        }
    }

    int ans=0;
    for(int i=1;i<=(2*n+3);i++)
    {
        if(freq[i]==1) ans++;
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