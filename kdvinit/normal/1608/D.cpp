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

    int a[n+1];
    int pos_bw=1;
    int pos_wb=1;

    int alr_bb=0;
    int alr_ww=0;
    int tp[6]={0};

    /*
    1 = ?W
    2 = W?
    3 = ?B
    4 = B?
    5 = ??
    */

    for(int i=1; i<=n; i++)
    {
        char x, y;
        cin>>x>>y;

        if(x=='B') pos_wb=0;
        if(x=='W') pos_bw=0;
        if(y=='W') pos_wb=0;
        if(y=='B') pos_bw=0;

        if(x=='B' && y=='W') continue;
        if(x=='W' && y=='B') continue;
        if(x=='B' && y=='B') alr_bb++;
        if(x=='W' && y=='W') alr_ww++;

        if(x=='?' && y=='W') tp[1]++;
        if(x=='W' && y=='?') tp[2]++;
        if(x=='?' && y=='B') tp[3]++;
        if(x=='B' && y=='?') tp[4]++;
        if(x=='?' && y=='?') tp[5]++;
    }

    int dif = alr_ww-alr_bb-tp[3]-tp[4]-tp[5];
    if(dif>0) { cout<<0<<endl; return; }

    int m = tp[1]+tp[2]+tp[3]+tp[4]+(2*tp[5]);
    int ans = nCr(m, -dif);
    if(alr_bb==0 && alr_ww==0)
    {
        int tmp = Power(2, tp[5]);
        ans -= tmp; ans += (pos_bw+pos_wb);
        ans%=mod; if(ans<0) ans+=mod;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}