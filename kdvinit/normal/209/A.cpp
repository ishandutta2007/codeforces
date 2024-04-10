/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    int ans = 1;

    int sum[2]={0};
    sum[0]=0;
    sum[1]=1;

    for(int i=2; i<=n; i++)
    {
        if(i%2==0)
        {
            int cur = 1+sum[1];
            sum[0] += cur; sum[0]%=mod;
            ans += cur; ans%=mod;
        }
        else
        {
            int cur = 1+sum[0];
            sum[1] += cur; sum[1]%=mod;
            ans += cur; ans%=mod;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}