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
    int n,m;
    cin>>n>>m;

    int freq[101]={0},x,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        freq[x]=1;
    }

    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(freq[x]==1) ans++;
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