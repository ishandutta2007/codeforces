/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353 ;

int val(int x)
{
    int ans=0;
    int cnt=11;
    while(x!=0)
    {
        int y=x%10;
        ans+=(y*cnt);
        ans%=mod;
        cnt*=100;
        cnt%=mod;
        x/=10;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int x,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans+=val(x);
        //cout<<x<<" "<<val(x)<<endl;
        ans%=mod;
    }
    ans*=n;
    ans%=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}