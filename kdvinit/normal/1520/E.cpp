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

    int a[n+1]={0}, cnt=0;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='*') a[++cnt]=i;
    }

    int ans = 0, m = (cnt+1)/2;
    for(int i=1; i<=cnt; i++)
    {
        ans+=abs(a[i]-(a[m]-m+i));
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