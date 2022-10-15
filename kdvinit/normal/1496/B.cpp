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

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a, a+n);
    if(a[n-1]==n-1)
    {
        cout<<n+k<<endl;
        return;
    }

    int mex;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i) { mex=i; break; }
    }

    int ans = n;
    int avg = (mex + a[n-1]+1)/2;

    int present = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==avg) { present = 1; break; }
    }

    //cout<<mex<<" "<<avg<<endl;
    if(present==0 && k!=0) ans++;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}