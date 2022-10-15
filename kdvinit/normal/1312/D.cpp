/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mod 998244353
#define $Fact_Length 500001     //Max length here is 519160

int Power(int $a,int $b)
{
    int $result=1; $a%=mod;
    while($b) {   if($b%2==1)  $result*=$a;     $a*=$a;     $a%=mod;     $result%=mod;    $b/=2; }
    return $result;
}

int Mod_Inv(int $a)
{
    $a%=mod; $a=Power($a,mod-2); return $a;
}

int Factorial[$Fact_Length];

int Make_Factorial()
{
    Factorial[0]=1;
    for(int i=1;i<$Fact_Length;i++) { Factorial[i]=i*Factorial[i-1]; Factorial[i]%=mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

int nCr(int $n,int $r)
{
    if($n<$r) return 0;
    int $ans=Factorial[$n]; $ans%=mod;
    $ans*=Mod_Inv(Factorial[$r]); $ans%=mod;
    $ans*=Mod_Inv(Factorial[$n-$r]); $ans%=mod;
    return $ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    if(n==2) { cout<<0<<endl; return; }

    int ans=nCr(m,n-1); ans%=mod;
    ans*=(n-2); ans%=mod;
    ans*=Power(2,n-3); ans%=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}