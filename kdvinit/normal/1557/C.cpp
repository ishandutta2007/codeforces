/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

void solve()
{
    int n, k;
    cin>>n>>k;

    if(k==0) { cout<<1<<endl; return; }

    if(n%2==1)
    {
        int ans = Power(2, n-1)+1;
        ans%=mod;
        ans = Power(ans, k);
        ans%=mod;
        cout<<ans<<endl;
    }
    else
    {
        int ans = Power(2, n-1)-1;
        ans%=mod;

        int tmp1 = ans;

        ans = Power(ans, k);
        ans%=mod;

        for(int i=1; i<=k; i++)
        {
            int tmp = Power(tmp1, (i-1));
            tmp%=mod;
            tmp *= Power(2, ((k-i)*n));
            tmp %= mod;
            ans+=tmp;
            ans%=mod;
        }

        ans%=mod;
        if(ans<0) ans+=mod;
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}