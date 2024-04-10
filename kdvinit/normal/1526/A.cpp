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

    int m = 2*n;
    int a[m+1];
    for(int i=1; i<=m; i++) cin>>a[i];
    sort(a+1, a+m+1);

    for(int i=1; i<=m; i++)
    {
        int x = (i+1)/2;
        if(i%2==1) cout<<a[x]<<" ";
        else cout<<a[n+x]<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}