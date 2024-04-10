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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans=0;
    for(int i=2; i<n; i++) ans+=(a[i]+1)/2;

    int odd=0, xtra=0, xp=-1;
    for(int i=2; i<n; i++)
    {
        if(a[i]%2==1) odd++;
        if(a[i]>=2)
        {
            xtra++;
            xp=i;
        }
    }

    if(odd>0 && xtra==0) ans=-1;
    if(odd==1 && n==3) ans=-1;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}