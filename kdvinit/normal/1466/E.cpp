/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int freq[61]={0};
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        for(int j=0;j<=60;j++)
        {
            freq[j]+=x%2;
            x/=2;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int sand=0,sor=0;

        int cnt=1,x=a[i];
        for(int j=0;j<=60;j++)
        {
            int y=freq[j]*(x%2);
            sand+=(y*cnt);
            sand%=mod;
            cnt*=2;
            cnt%=mod;
            x/=2;
        }

        cnt=1;
        x=a[i];
        for(int j=0;j<=60;j++)
        {
            int z=n*(x%2);
            int y=max(freq[j],z);
            sor+=(y*cnt);
            sor%=mod;
            cnt*=2;
            cnt%=mod;
            x/=2;
        }

        ans+=((sand*sor)%mod);
        ans%=mod;
        //cout<<i<<" -> "<<sand<<" "<<sor<<endl;
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