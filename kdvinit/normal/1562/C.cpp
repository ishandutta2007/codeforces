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

    int a[n+1], all1=1;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] = x-'0';
        if(a[i]==0) all1=0;
    }

    if(all1==1) { cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl; return; }

    int f0, l0;
    for(int i=1; i<=n; i++) if(a[i]==0) l0=i;
    for(int i=n; i>=1; i--) if(a[i]==0) f0=i;

    int m = (n+1)/2;
    if(f0<=m) cout<<f0<<" "<<n<<" "<<f0+1<<" "<<n<<endl;
    else cout<<1<<" "<<l0<<" "<<1<<" "<<l0-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}