/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,x;
    cin>>n>>x;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int sum=0,y,ans1=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        y=(a[i]-1)/x;
        y++;
        ans1+=y;
    }

    sum=(sum-1)/x;
    sum++;
    cout<<sum<<" "<<ans1<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}