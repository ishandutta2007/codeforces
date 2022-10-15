/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x,y,n;
    cin>>x>>y>>n;

    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int mx=0,is=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=mx)
        {
            mx=a[i];
            is=i;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(i==is) continue;
        int z = ( (b[i]-1) / x ) + 1 ;
        y-=(a[i]*z);
    }

    int z = ( (b[is]-1)/x ) + 1 ;
    z--;
    y-=(a[is]*z);

    if(y>0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}