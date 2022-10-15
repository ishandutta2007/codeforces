/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int ans=0, a[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'0';
    }

    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) continue;
        ans+=(a[i]+1);
    }

    if(a[n]!=0) ans--;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}