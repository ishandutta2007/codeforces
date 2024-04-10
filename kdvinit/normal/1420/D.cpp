/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

#define mod 998244353

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

#define $length 300001
int Factorial[$length];

void Make_Factorial()
{
    Factorial[0]=1;
    for(int i=1;i<$length;i++) { Factorial[i]=i*Factorial[i-1]; Factorial[i]%=mod; }
}


int nCk(int $n,int $k)
{
    static int $Check_Make_Fact1=1; if($Check_Make_Fact1==1) Make_Factorial(); $Check_Make_Fact1=0;     //Checks to apply make factorial just once;
    if($n<$k) return 0;
    int $ans=Factorial[$n]; $ans%=mod;
    $ans*=Mod_Inv(Factorial[$k]); $ans%=mod;
    $ans*=Mod_Inv(Factorial[$n-$k]); $ans%=mod;
    return $ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;

    int infy=1e10;

    int l[n+1],r[n+2];
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];

    sort(l+1,l+n+1);
    sort(r+1,r+n+1);

    r[n+1]=infy;

    int ans=0,cnt;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(r[j]<l[i]) j++;
        cnt=i-j;
        ans+=nCk(cnt,k-1);
        ans%=mod;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}