/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int Fact_Length = 1e5 + 1;     //Max length

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

/**Takes n&r as input and Returns : nPr%mod n!/(n-r)! **/
int nPr(int $n,int $r)
{
    int $ans=(Factorial[$n]*Mod_Inv(Factorial[$n-$r]))%mod;
    return $ans;
}

void solve()
{
    int n, k;
    cin>>n>>k;

    int ans=2;
    for(int i=2; i<=n; i++)
    {
        int x = (n-(i-1)*(k-1));
        if(x<i) break;

        ans = (ans + (nCr(x, i)*Mod_Inv(nCr(n, i)))%mod)%mod;
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