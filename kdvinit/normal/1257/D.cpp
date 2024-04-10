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

    int m; cin>>m;

    int mxp[n+1]={0};
    while(m--)
    {
        int p,e;
        cin>>p>>e;
        mxp[e]=max(mxp[e], p);
    }

    int mx=0;
    for(int i=n;i>=1;i--)
    {
        mx=max(mxp[i],mx);
        mxp[i]=mx;
    }

    int ans=0,mxv;
    for(int i=1;i<=n;i++)
    {
        ans++;
        int j=1;
        if(a[i]>mx) { cout<<-1<<endl; return; }

        mxv=a[i];
        while(i<=n)
        {
            mxv=max(mxv,a[i]);
            if(mxv>mxp[j]) break;
            i++;
            j++;
        }
        i--;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}