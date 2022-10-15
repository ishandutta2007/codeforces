/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 998244353;
const int Fact_Length = 5e5 + 1;     //Max length

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a,mod-2); }

int Factorial[Fact_Length];
// It make the above Factorial[i] = i! array
int Make_Factorial()
{
   Factorial[0]=1;
   for(int i=1;i<Fact_Length;i++) { Factorial[i]=(i*Factorial[i-1])%mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

// Takes n&r as input and Returns : nCr%mod
int nCr(int $n,int $r)
{
   if($n<$r || $n<0 || $r<0) return 0;
   //if($n>Fact_Length) { cout<<"Error"<<endl; return; }
   int $ans=(Factorial[$n]*Mod_Inv(Factorial[$r]))%mod;
   $ans=($ans*Mod_Inv(Factorial[$n-$r]))%mod;
   return $ans;
}

void solve()
{
    int n;
    cin>>n;

    if(n==1) { cout<<1<<endl; return; }
    if(n==2) { cout<<2<<endl; return; }

    int dp[n+1];

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=n; i++)
    {
        dp[i]=dp[i-1];
        int cur = ((i-1)*(dp[i-2]))%mod;
        dp[i] = (dp[i]+cur)%mod;
    }

    int ans = dp[n];

    int f2[n+1];

    f2[0]=1;
    f2[1]=1;
    for(int i=2; i<=n; i++) f2[i]=(i*f2[i-2])%mod;

    for(int i=1; 1; i++)
    {
        if((i*4)>n) break;
        int l = (n-(i*4));      //Ways for remaining without 4

        int c1 = (f2[(2*i - 1)])%mod; //Ways to pair them up;
        int p2 = Power(2, i);

        int k = (2*i);
        int c2 = nCr(n-k, k);       //Ways to select k pairs

        int c12 = (c1*c2)%mod;
        int cur = (dp[l]*c12)%mod;
        cur = (cur*p2)%mod;

        ans = (ans+cur)%mod;
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