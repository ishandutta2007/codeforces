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

    int a[n+1], lst=-1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]==0) lst=i;
    }

    if(lst==-1)
    {
        cout<<n+1<<" ";
        for(int i=1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
        return;
    }

    for(int i=1; i<=lst; i++) cout<<i<<" ";
    cout<<n+1<<" ";
    for(int i=lst+1; i<=n; i++) cout<<i<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}