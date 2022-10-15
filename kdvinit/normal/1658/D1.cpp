/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int l, r;
    cin>>l>>r;

    int n = r-l+1;
    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int org[20]={0}, nw[20]={0};

    for(int i=l; i<=r; i++)
    {
        int x = i;
        for(int j=0; j<20; j++)
        {
            if(x%2==1) org[j]++;
            x/=2;
        }
    }

    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        for(int j=0; j<20; j++)
        {
            if(x%2==1) nw[j]++;
            x/=2;
        }
    }

    int ans=0;
    for(int j=0; j<20; j++)
    {
        int x = 1<<j;
        if(org[j]!=nw[j]) ans+=x;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}