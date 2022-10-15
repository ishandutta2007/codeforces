/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a,mod-2); }

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    int ans = 0;
    int cf=1, nm=n, dn=1;
    for(int i=m; i>=1; i--)
    {
        int x = (2*i);
        int tmp = (cf*x)%mod;
        tmp = (tmp*k)%mod;
        ans = (ans+tmp)%mod;
        cf = (cf*nm)%mod;
        cf = (cf*Mod_Inv(dn))%mod;
        nm--;
        dn++;
    }

    int tmp = Power(2, n);
    ans = (ans*Mod_Inv(tmp))%mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}