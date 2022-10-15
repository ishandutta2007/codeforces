/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;
const int Fact_Length = 1e5 + 1;     //Max length

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}

void solve()
{
    int n, m, k, r, c;
    cin>>n>>m>>k>>r>>c;

    int a1x, a1y, b1x, b1y;
    cin>>a1x>>a1y>>b1x>>b1y;

    int tot = n*m;
    int cmn=r*c;
    if(a1x==b1x && a1y==b1y) cmn=0;
    tot-=cmn;

    int ans = Power(k, tot);
    cout<<ans<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}