/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
const int Fact_Length = 3e5 + 1;     //Max length

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

int cnt_x(int a[], int n, int x)
{
    int cnt=0;
    for(int i=1; i<=n; i++) if(a[i]==x) cnt++;
    return cnt;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int mx1=0;
    for(int i=1; i<=n; i++) if(a[i]>mx1) mx1=a[i];

    int mx2=0;
    for(int i=1; i<=n; i++) if(a[i]>mx2 && a[i]!=mx1) mx2=a[i];

    int ans = Factorial[n];
    int m = mx1-mx2;

    int c1=cnt_x(a, n, mx1);
    int c2=cnt_x(a, n, mx2);

    if(c1>1) { cout<<ans<<endl; return; }
    if(m>1) { cout<<0<<endl; return; }

    ans *= (c2); ans%=mod;
    ans *= Mod_Inv(c2+1); ans%=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}