/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e4;
const int mod = 998244353;
int fact[N];

void solve()
{
    int n;
    cin>>n;

    if(n%2==1) cout<<0<<endl;
    else
    {
        int ans = (fact[n/2]*fact[n/2])%mod;
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[1]=1;
    for(int i=2; i<N; i++) fact[i]=(fact[i-1]*i)%mod;

    int t; cin>>t;
    while(t--) solve();
    return 0;
}