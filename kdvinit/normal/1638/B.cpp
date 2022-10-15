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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int mxe=0, mxo=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]%2==0)
        {
            if(a[i]<mxe) { cout<<"No"<<endl; return; }
            mxe=a[i];
        }
        else
        {
            if(a[i]<mxo) { cout<<"No"<<endl; return; }
            mxo=a[i];
        }
    }

    cout<<"Yes"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}