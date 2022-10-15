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

    int cnte=0;
    int mn2=100;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(x%2==0) cnte++;

        int cur=0;
        while(x%2==0) { x/=2; cur++; }
        mn2 = min(mn2, cur);
    }

    int ans = mn2 + cnte - 1;
    if(mn2==0) ans+=1;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}