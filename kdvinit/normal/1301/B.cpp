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

    int mx=0,mn=1e10,l=1e10;
    if(a[1]==-1 && a[2]!=-1) { mx=max(mx,a[2]); mn=min(mn,a[2]); }
    if(a[n]==-1 && a[n-1]!=-1) { mx=max(mx,a[n-1]); mn=min(mn,a[n-1]); }
    for(int i=2;i<n;i++)
    {
        if(a[i]!=-1) continue;
        if(a[i-1]!=-1) { mx=max(mx,a[i-1]); mn=min(mn,a[i-1]); }
        if(a[i+1]!=-1) { mx=max(mx,a[i+1]); mn=min(mn,a[i+1]); }
    }

    int k=(mx+mn)/2;
    if(mn==l) k=0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1) a[i]=k;
    }

    int m=0;
    for(int i=2;i<=n;i++)
    {
        int x=abs(a[i]-a[i-1]);
        m=max(m,x);
    }

    cout<<m<<" "<<k<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}