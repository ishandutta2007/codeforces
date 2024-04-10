/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int mx = (n-1)/2;
    if(k>mx) { cout<<-1<<endl; return; }

    int a[n+1];
    for(int i=1; i<=n; i++) a[i]=i;

    for(int i=2; i<=n; i+=2)
    {
        if(k==0) break;
        k--;
        swap(a[i], a[i+1]);
    }

    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}