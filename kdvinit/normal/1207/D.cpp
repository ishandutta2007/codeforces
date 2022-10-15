/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long


const int mod = 998244353;
const int Fact_Length = 3e5 + 2;     //Max length

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



void solve()
{
    int n;
    cin>>n;

    array<int, 2> ab[n+1];
    array<int, 2> ba[n+1];

    for(int i=1; i<=n; i++)
    {
        int x, y;
        cin>>x>>y;

        ab[i] = {x, y};
        ba[i] = {y, x};
    }

    int a1=1, a2=1, a3=1;

    sort(ab+1, ab+n+1);
    sort(ba+1, ba+n+1);

    for(int i=1; i<=n; i++)
    {
        int j=i;
        while(j<=n && ab[j][0]==ab[i][0]) j++;

        int len = j-i;
        i=j-1;

        a1*=Factorial[len];
        a1%=mod;
    }

    for(int i=1; i<=n; i++)
    {
        int j=i;
        while(j<=n && ba[j][0]==ba[i][0]) j++;

        int len = j-i;
        i=j-1;

        a2*=Factorial[len];
        a2%=mod;
    }

    a3=1;
    for(int i=2; i<=n; i++)
    {
        if(ab[i-1][1]>ab[i][1]) { a3=0; break; }
    }

    if(a3==1)
    {
        for(int i=1; i<=n; i++)
        {
            int j=i;
            while(j<=n && ab[j]==ab[i]) j++;

            int len = j-i;
            i=j-1;

            a3*=Factorial[len];
            a3%=mod;
        }
    }

    int ans = Factorial[n] - a1 - a2 + a3;
    ans%=mod;
    if(ans<0) ans+=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}