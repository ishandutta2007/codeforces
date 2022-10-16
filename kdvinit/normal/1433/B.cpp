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
    int n,cnt=0;
    cin>>n;

    int a[n+1],strt=1,nd=n;
    vector<int> cnt0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    while(a[strt]==0) strt++;
    while(a[nd]==0) nd--;

    int ans=0;
    for(int i=strt;i<=nd;i++)
    {
        if(a[i]==1 && cnt!=0)
        {
            ans+=cnt;
            cnt=0;
        }
        if(a[i]==0) cnt++;
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