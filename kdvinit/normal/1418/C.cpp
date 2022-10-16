/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1],ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n<4)
    {
        ans=a[1];
        cout<<ans<<endl;
        return;
    }
    int dpf[n+1]={0};
    int dpm[n+1]={0};
    dpf[1]=a[1];
    dpf[2]=a[1]+a[2];
    dpm[1]=n+10;
    dpm[2]=a[1];

    for(int i=3;i<=n;i++)
    {
        int x=0,y=0;
        x=dpm[i-2]+a[i-1]+a[i];
        y=dpm[i-1]+a[i];
        dpf[i]=min(x,y);

        x=dpf[i-2];
        y=dpf[i-1];
        dpm[i]=min(x,y);
    }

    ans=min(dpf[n],dpm[n]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}