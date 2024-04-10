/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mod 1000000007
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
    int n,k;
    cin>>n>>k;

    int a[n+1],freq[n+1]={0};
    for(int i=1;i<=n;i++) { cin>>a[i]; freq[a[i]]++; }
    sort(a+1,a+n+1);
    int l=a[n+1-k];

    int x=freq[l];
    int y=0;
    for(int i=n+1-k;i<=n;i++)
    {
        if(a[i]==l) y++;
        else break;
    }

    cout<<nCr(x,y)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}