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

    int a[n];
    for(int i=0; i<n; i++) a[i]=i;

    int cur=1;
    while(2*cur<=n-1) cur*=2;

    swap(a[0], a[cur-1]);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}