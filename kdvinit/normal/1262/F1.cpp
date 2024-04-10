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

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    if(k==1) { cout<<0<<endl; return; }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int y=(i%n)+1;
        if(a[i]!=a[y]) cnt++;
    }

    int ans=0;

    for(int i=0;i<cnt;i++)
    {
        int temp;
        if((cnt-i)%2==1)
        {
            temp=Power(2,cnt-i-1);
            temp%=mod;
        }
        else
        {
            temp=Power(2,cnt-i);
            temp%=mod;
            int x=(cnt-i)/2;
            temp-=nCr(cnt-i,x);
            if(temp<0) temp+=mod;
            temp%=mod;
            temp*=Mod_Inv(2);
            temp%=mod;
        }
        temp*=Power(k-2,i);
        temp%=mod;
        temp*=nCr(cnt,i);
        temp%=mod;
        ans+=temp;
        ans%=mod;
    }

    ans*=Power(k,n-cnt);
    ans%=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}