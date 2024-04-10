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

const int N = 14;
const int M = 1<<N;

int a[N+1], p[N+1][N+1];
int dpG[N+1][M], dp[M];
int n;

bool check(int bm, int ind)
{
    int tmp = 1<<(ind-1);
    return (bm&tmp);
}

void set_pG()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) p[i][j]=0;
            else p[i][j] = (a[i]*Mod_Inv(a[i]+a[j]))%mod;
        }
    }

    int mx = 1<<n;
    for(int i=1; i<=n; i++)
    {
        for(int bm=0; bm<mx; bm++)
        {
            if(check(bm, i)) continue;
            int val = 1;
            for(int j=1; j<=n; j++)
            {
                if(!check(bm, j)) continue;
                val*=p[i][j]; val%=mod;
            }
            dpG[i][bm]=val;
        }
    }
}

int get_G(int bm1, int bm2)
{
    int val=1;
    for(int i=1; i<=n; i++)
    {
        if(!check(bm1, i)) continue;
        val*=dpG[i][bm2]; val%=mod;
    }
    return val;
}

int get_ans()
{
    int mx = 1<<n;
    int ans = 0;
    for(int bm=1; bm<mx; bm++)
    {
        int tmp = get_G(bm, (mx-1-bm));
        int val = 1;
        for(int i=bm; i>0; i = ((i-1)&bm))
        {
            if(i==bm) continue;
            int bm2 = bm - i;
            int t2 = dp[i]*get_G(i, bm2);       t2%=mod;
            val-=t2; val%=mod;
        }
        int x = __builtin_popcount(bm);
        if(x==2) val=0;
        dp[bm]=val;
        val*=tmp; val%=mod; val*=x; val%=mod;
        ans+=val; ans%=mod;
    }
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    set_pG();
    int ans = get_ans(); ans%=mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}