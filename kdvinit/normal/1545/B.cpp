/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
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

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    char x;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        a[i]=x-'0';
    }

    int m = 0, r=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) { m++; continue; }

        int cnt=0;
        while(i<=n && a[i]==1) { cnt++; i++; }
        i--;

        r+=(cnt/2);
    }
    //cout<<m<<" "<<r<<endl;

    if(r==0) { cout<<1<<endl; return; }
    int ans = nCr(m+r, r);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}