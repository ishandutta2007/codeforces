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

    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int m=(n+2)/2;
    char x = a[m];

    int ans = 2 - (n%2);
    for(int i=m+1; i<=n; i++)
    {
        if(a[i]==x) ans+=2;
        else break;
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