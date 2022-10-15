/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int Fact_Length = 2e5 + 1;     //Max length

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

int calc(int n, int tn, int nd, int tp, int pd)
{
    tn -= nd; tp-=pd;
    if(tn<0 || tp<0) return -1;
    int ans = nCr(tn+tp, tn);
    return ans;
}

void solve()
{
    int n, l, r;
    cin>>n>>l>>r;

    int d1 = 1-l;
    int d2 = r-n;

    int y = min(d1, d2);
    y%=mod;

    int m = (n/2);
    int ans = (y*nCr(n, m));    ans%=mod;

    if(n%2==1) { ans += (y*nCr(n, m));    ans%=mod; }

    for(int i=y+1; 1; i++)
    {
        int nge = l+i;
        int ple = r-i;

        if(nge-ple>1) break;

        int nd = n-ple;     nd=max(nd, (int)0);
        int pd = nge-1;     pd=max(pd, (int)0);

        //cout<<i<<" "<<nd<<" "<<pd<<endl;

        if(n%2==0)
        {
            int x = calc(n, m, nd, m, pd);
            if(x==-1) break;
            ans+=x; ans%=mod;
        }
        else
        {
            int x1 = calc(n, m, nd, n-m, pd);
            if(x1!=-1) { ans+=x1; ans%=mod; }

            int x2 = calc(n, n-m, nd, m, pd);
            if(x2!=-1) { ans+=x2, ans%=mod; }

            if(x1==-1 && x2==-1) break;
        }
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