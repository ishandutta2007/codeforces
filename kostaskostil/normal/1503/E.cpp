#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int MOD = 998244353;

int bpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b&1)
            res*=a, res%=MOD;
        b>>=1;
        a*=a;

        a%=MOD;
    }
    return res;
}

int rev(int x)
{
    return bpow(x, MOD-2);
}

const int nmax = 4321;
int fact[nmax];
int rfact[nmax];

int cnk(int n, int k)
{
    return (((fact[n]*rfact[k])%MOD)*rfact[n-k])%MOD;
}

int incseq(int n, int k)
{
    return cnk(n+k, k);
}


int counter(int n, int m, int f)
{
    int ans = 0;
    for (int c = 1; c <= n; c++)
    {
            int curr=0;
            for (int r0 = m; r0 >= 1; r0--)
            {
                int curl = (incseq(c, r0 - 1) * incseq(c - 1, m - r0))%MOD;

                    for (int l1 = r0+1+f; l1 <= m; l1++)
                    {
                        curr += incseq(n - (c+1), l1 - 1) * incseq(n - c, m - l1);
                        curr %= MOD;
                        break;
                    }
                ans+=curl*(curr%MOD);
                ans%=MOD;
            }
    }
    return (2*ans)%MOD;
}

main()
{
    fact[0]=rfact[0]=1;
    for (int i=1; i<nmax; i++)
        fact[i]=i*fact[i-1], fact[i]%=MOD, rfact[i]=rev(fact[i]);

    int n, m;
    cin>>n>>m;
    cout<<(counter(n, m, 0)+counter(m, n, 1))%MOD<<"\n";
}