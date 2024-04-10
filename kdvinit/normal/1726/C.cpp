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
    n*=2;

    int a[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='(') a[i]=1;
    }

    int ans=1;
    for(int i=2; i<=n; i++)
    {
        if(a[i]==1 && a[i-1]==1) ans++;
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