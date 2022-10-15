/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,t;
    cin>>n>>t;

    int a[n+1];
    for(int i=1;i<n;i++) cin>>a[i];

    int i=1;
    while(i<t) i+=a[i];

    if(i==t) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}