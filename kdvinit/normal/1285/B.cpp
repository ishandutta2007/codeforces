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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int sum=0;
    for(int i=1;i<n;i++)
    {
        sum+=a[i];
        if(sum<=0) { cout<<"NO"<<endl; return; }
    }

    sum=0;
    for(int i=n;i>1;i--)
    {
        sum+=a[i];
        if(sum<=0) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}