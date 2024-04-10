/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
const int $Fact_Length = 1e6+1;     //Max length here is 519160

/**Takes a&b as input and Returns : The power (a,b), (a^b)%mod **/
int Power(int $a,int $b)
{
    int $result=1; $a%=mod;
    while($b) {   if($b%2==1)  $result*=$a;     $a*=$a;     $a%=mod;     $result%=mod;    $b/=2; }
    return $result;
}

/** It give the modulo inverse of a, (1/a)%mod **/
int Mod_Inv(int $a)
{
    $a%=mod; $a=Power($a,mod-2); return $a;
}

int Factorial[$Fact_Length];

/** It make the above Factorial array to i! array**/
int Make_Factorial()
{
    Factorial[0]=1;
    for(int i=1;i<$Fact_Length;i++) { Factorial[i]=i*Factorial[i-1]; Factorial[i]%=mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

int nCr(int $n,int $r)
{
    if($n<$r || $n<0 || $r<0) return 0;
    int $ans=Factorial[$n]; $ans%=mod;
    $ans*=Mod_Inv(Factorial[$r]); $ans%=mod;
    $ans*=Mod_Inv(Factorial[$n-$r]); $ans%=mod;
    return $ans;
}

void solve()
{
    int n;
    cin>>n;

    int ans=0;
    for(int i=0; i<=n; i+=2)
    {
        int tmp = nCr(i, n-i) + nCr(i-1, n-i-1); tmp%=mod;
        tmp*=2; tmp%=mod;
        tmp*=Factorial[i]; tmp%=mod;
        ans+=tmp; ans%=mod;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}