/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int x[n+1], y[n+1];
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];

    for(int i=1;i<=n;i++)
    {
        int mx=0;
        for(int j=1;j<=n;j++)
        {
            int tmp = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            mx=max(mx,tmp);
        }
        if(mx<=k)
        {
            cout<<1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}