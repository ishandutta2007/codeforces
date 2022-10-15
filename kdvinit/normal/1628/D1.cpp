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

    int dp[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(j==0) { dp[i][j]=0; continue; }
            if(i==j) { dp[i][j]=(k*i)%mod; continue; }
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
            dp[i][j] = (dp[i][j]*Mod_Inv(2))%mod;
        }
    }

    cout<<dp[n][m]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}