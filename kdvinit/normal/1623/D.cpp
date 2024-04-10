/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a,mod-2); }

set<int> tim;
int mx;

void put_tim(int x1, int x2, int n)
{
    int f, p1, p2;

    if(x1<=x2)
    {
        f = x2-x1;
        p1 = (2*n-2*x2);
        p2 = 2*x2-2;
    }
    else
    {
        f = n-x1 + n-x2;
        p1 = 2*x2-2;
        p2 = (2*n-2*x2);
    }

    int cur=f;
    for(int i=1; 1; i++)
    {
        if(cur>=mx) break;
        tim.insert(cur);
        if(i%2==1) cur+=p1;
        else cur+=p2;
    }
}

void solve()
{
    int n, m, x1, y1, x2, y2, p;
    cin>>n>>m>>x1>>y1>>x2>>y2>>p;

    tim.clear();
    mx = (2*n-2)*(2*m-2);

    put_tim(x1, x2, n);
    put_tim(y1, y2, m);

    p*=Mod_Inv(100);
    p%=mod;

    int notp=(1-p);
    notp%=mod;
    if(notp<0) notp+=mod;

    int np=1;
    int tot=0;

    for(int x: tim)
    {
        int cur = (x*p)%mod;
        cur = (cur*np)%mod;
        tot += cur;     tot%=mod;
        np*=notp;       np%=mod;
    }

    tot += ((np*mx)%mod);    tot%=mod;
    int dv = (1-np); dv%=mod; if(dv<0) dv+=mod;

    int ans = (tot*Mod_Inv(dv))%mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}