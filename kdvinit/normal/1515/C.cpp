/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m, x;
    cin>>n>>m>>x;

    array<int, 2> a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i][0];
        a[i][1]=i;
    }

    sort(a+1, a+n+1);
    int ans[n+1];

    for(int i=1; i<=n; i++)
    {
        int y = (i-1)%m+1;
        ans[a[i][1]]=y;
    }

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}