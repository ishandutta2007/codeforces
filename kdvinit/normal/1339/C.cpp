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

    int mx=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]<=a[i]) continue;
        mx=max(mx,a[i-1]-a[i]);
        a[i]=a[i-1];
    }

    int ans=0,val=0,tmp=1;
    while(val<mx)
    {
        val+=tmp;
        ans++;
        tmp*=2;
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