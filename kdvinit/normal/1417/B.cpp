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

    int a[n+1],p[n+1]={0};
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        if(2*a[i]<k) p[i]=2;
        if(2*a[i]>k) p[i]=1;
    }

    int cnt=0;
    for(int i=1;i<=n;i++) if(p[i]==0) cnt++;

    cnt/=2;
    for(int i=1;i<=n;i++)
    {
        if(p[i]==0)
        {
            if(cnt>0) { p[i]=2; cnt--; }
            else p[i]=1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(p[i]==2) cout<<0<<" ";
        else cout<<1<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}