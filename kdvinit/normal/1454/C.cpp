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

    int a[n+1],cnt=1,x;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        if(x==a[cnt]) continue;
        a[++cnt]=x;
    }
    if(cnt==1) { cout<<0<<endl; return; }

    int freq[n+1]={0};
    for(int i=1;i<=cnt;i++)
    {
        freq[a[i]]++;
    }

    int ans=n;
    for(int i=1;i<=n;i++)
    {
        if(freq[i]==0) continue;

        if(a[1]==i && a[cnt]==i)
        {
            ans=min(freq[i]-1,ans);
        }
        else if(a[1]==i || a[cnt]==i)
        {
            ans=min(freq[i],ans);
        }
        else
        {
            ans=min(freq[i]+1,ans);
        }
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