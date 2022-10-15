/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1], tm[n+1];
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    a[0]=0; b[0]=0;

    for(int i=1;i<=n;i++) cin>>tm[i];

    int time = 0;
    for(int i=1;i<=n;i++)
    {
        time+=(a[i]-b[i-1]+tm[i]);
        if(i==n) break;
        int x = time + ( (b[i]-a[i]+1)/2 );
        time = max(x, b[i]);
    }
    cout<<time<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}