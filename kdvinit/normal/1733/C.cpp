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

    if(n==1)
    {
        cout<<0<<endl<<endl;
        return;
    }

    vector<array<int, 2>> ans;
    ans.push_back({1, n});

    if( (a[1]+a[n])%2 == 1) a[n]=a[1];
    else a[1]=a[n];

    int x = a[1]%2;
    for(int i=2; i<n; i++)
    {
        if(a[i]%2==x) ans.push_back({i, n});
        else ans.push_back({1, i});
    }

    cout<<ans.size()<<endl;
    for(auto cur: ans)
    {
        cout<<cur[0]<<" "<<cur[1]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}