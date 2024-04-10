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

    array<int, 2> a[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i][0]; a[i][1]=i; }
    sort(a+1, a+n+1);

    cout<<a[n][1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}