/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1], mn = 1e5;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        mn = min(mn, a[i]);
    }

    int all0=1;
    for(int i=1; i<=n; i++) 
    {
        a[i]-=mn;
        if(a[i]!=0) all0=0;
    }
    
    if(all0)
    {
        cout<<-1<<endl;
        return;
    }

    int ans=0;
    for(int i=1; i<=n; i++) ans = GCD(ans, a[i]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}