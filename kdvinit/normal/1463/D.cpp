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
    cin>>n;
    m=2*n;

    int a[n+1],freq[m+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        freq[a[i]]=1;
    }

    int cnt=0,mx=0,mn=0;
    for(int i=1;i<=2*n;i++)
    {
        if(freq[i]==1)
        {
            if(cnt==0) continue;
            cnt--;
            mx++;
        }
        else cnt++;
    }

    cnt=0;
    for(int i=2*n;i>0;i--)
    {
        if(freq[i]==1)
        {
            if(cnt==0) continue;
            cnt--;
            mx++;
        }
        else cnt++;
    }
    mn=n-mn;
    int ans=mx-mn+1;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}