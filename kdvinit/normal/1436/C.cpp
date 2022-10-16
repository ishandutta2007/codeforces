/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int mod=1e9+7;
#define $Fact_Length 1001     //Max length here is 519160

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

void solve()
{
    int n,x,pos;
    cin>>n>>x>>pos;

    int a[n];
    for(int i=0;i<n;i++)
    {
        if(i<pos) a[i]=x-1;
        if(i==pos) a[i]=x;
        if(i>pos) a[i]=x+1;
    }

    int used[n]={0};
    int left=0,right=n;
    while(left<right)
    {
        int middle=(left+right)/2;
        used[middle]=1;
        if(a[middle]<=x) left=middle+1;
        else right=middle;
    }

    int sml=0,grt=0;
    for(int i=0;i<n;i++)
    {
        if(used[i]==0) continue;
        if(i<pos) sml++;
        if(i>pos) grt++;
    }

    int ans=1;
    ans*=nCr(x-1,sml); ans%=mod;
    ans*=Factorial[sml]; ans%=mod;
    ans*=nCr(n-x,grt); ans%=mod;
    ans*=Factorial[grt]; ans%=mod;
    n-=sml;
    n-=grt;
    n--;
    ans*=Factorial[n];
    ans%=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}