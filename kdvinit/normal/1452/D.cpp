/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

#define mod 998244353
#define $Fact_Length 500001     //Max length here is 519160

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

/** Takes n&r as input and Returns : nCr%mod **/
int nCr(int $n,int $r)
{
    if($n<$r) return 0;
    int $ans=Factorial[$n]; $ans%=mod;
    $ans*=Mod_Inv(Factorial[$r]); $ans%=mod;
    $ans*=Mod_Inv(Factorial[$n-$r]); $ans%=mod;
    return $ans;
}

/**Takes n&r as input and Returns : nPr%mod n!/(n-r)! **/
int nPr(int $n,int $r)
{
    int $ans=Factorial[$n]; $ans%=mod;
    $ans*=Mod_Inv(Factorial[$n-$r]); $ans%=mod;
    return $ans;
}


void solve()
{
    int n;
    cin>>n;

    if(n%2==0)
    {
        int k=n/2;
        int ans=0;
        for(int i=0;i<=k-1;i++)
        {
            ans+=nCr(k+i,(2*i)+1);
            ans%=mod;
        }
        int y=Power(2,n);
        y%=mod;
        y=Mod_Inv(y);
        ans*=y;
        ans%=mod;
        cout<<ans<<endl;
    }
    else
    {
        int k=n/2;
        int ans=0;
        for(int i=0;i<=k;i++)
        {
            ans+=nCr(k+i,(2*i));
            ans%=mod;
        }
        int y=Power(2,n);
        y%=mod;
        y=Mod_Inv(y);
        ans*=y;
        ans%=mod;
        cout<<ans<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}