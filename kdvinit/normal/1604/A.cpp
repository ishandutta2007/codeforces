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

    int a[n+1], xtra=0;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        int tmp = (a[i]-i-xtra);
        if(tmp<0) continue;
        xtra+=tmp;
    }

    cout<<xtra<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}