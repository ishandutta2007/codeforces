/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int mod=998244353;

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n+1],b[k+1],bi[n+1]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=0;
    a[n+1]=0;
    bi[0]=n+1;
    for(int i=1;i<=k;i++)
    {
        cin>>b[i];
        bi[b[i]]=i;
    }

    int ans=1;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        if(bi[x]==0) continue;
        int cnt=0;
        if(bi[x]>bi[a[i-1]]) cnt++;
        if(bi[x]>bi[a[i+1]]) cnt++;
        ans*=cnt;
        ans%=mod;
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