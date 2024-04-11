#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
#define pb push_back
#define fi first
#define se second
 
using namespace std;
 
//typedef long long ll;
//#define int ll
 
const int mod = 31607;
int rev[mod];
 
int bpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b%2)
        {
            res*=a;
            res%=mod;
        }
        b/=2;
        a*=a;
        a%=mod;
    }
    return res;
}
 
int n;
int a[25][25];
int rows[25][2500000];
int stolb[25];
 
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i=0; i<mod; i++)
        rev[i] = bpow(i, mod-2);
 
    cin>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>a[i][j], a[i][j] *= rev[10000], a[i][j]%=mod;
 
    for (int mask=0; mask < (1<<n); mask++)
    {
        int bt = 0;
        if (mask!=0)
            while (((1<<bt) & mask) == 0)
                bt++;
 
        for (int i=0; i<n; i++)
            if (mask == 0)
                rows[i][mask] = 1;
            else
                rows[i][mask] = (rows[i][ mask&(mask-1) ] * a[i][bt]) % mod;
    }
    for (int i=0; i<n; i++)
    {
        stolb[i] = 1;
        for (int j = 0; j < n; j++)
            stolb[i] = (stolb[i] * a[j][i]) % mod;
    }
 
    int ans = 0;
    for (int mask = 1; mask < (1<<(n+3)); mask++)
    {
        int d0 = (mask >> n) & 1;
        int d1 = (mask >> (n+1)) & 1;
        int l = (mask >> (n+2)) & 1;
 
        int p = 1;
        for (int i=0; i<n; i++)
            if ((mask>>i)&1)
                p*=stolb[i], p%=mod;
        for (int i=0; i<n; i++)
            if (((mask >> i) & 1) == 0)
        {
            if (d0)
                p*=a[i][i], p%=mod;
            if (d1)
            {
                if ((n-1-i == i) and (d0))
                {
                }
                else
                {
                    p*=a[n-1-i][i];
            p%=mod;
                }
            }
        }
        if (l)
        {
            int pr1m = 1;
            int rmask = 0;
            for (int i=0; i<n; i++)
                if (((mask>>i) & 1) == 0)
                    rmask+=(1<<i);
            for (int i=0; i<n; i++)
            {
                int px = rows[i][rmask];
                if (d0)
                    if ((rmask >> i)&1)
                    {
                        px *= rev[a[i][i]];
                        px%=mod;
                    }
                if (d1)
                    if ((rmask >> (n-1-i))&1)
                {
                    if ((n-1-i == i) and (d0 == 1))
                    {
 
                    }
                    else
                    {
 
                    px *= rev[a[i][n-1-i]];
                    px%=mod;
                    }
 
                }
//                int px = 1;
//                for (int j=0; j<n; j++)
//                    if (((mask >> j) & 1) == 0)
//                    {
//                        if ((d0==1) and (i==j))
//                            continue;
//                        if ((d1==1) and (i+j==n-1))
//                            continue;
//                        px*=a[i][j];
//                        px%=mod;
//                    }
                pr1m = (pr1m * (mod + 1 - px)) % mod;
            }
            p = (p * (mod + 1 - pr1m)) % mod;
        }
 
//        cout<<mask<<" "<<d0<<" "<<d1<<" "<<l<<" "<<p<<"\n";
 
        int bt = __builtin_popcount(mask);
        if (bt%2)
            ans+=p;
        else
            ans-=p;
        ans = (ans % mod + mod)%mod;
    }
    cout<<ans<<"\n";
}