#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll
int mod;

int dp[500][500];
int pow2[500];
int rf[500];
int cnk[500][500];

int bpow(int a, int b)
{
    int res=1;

    while (b>0)
    {
        if (b&1)
        {
            res*=a;
            res%=mod;
        }
        b>>=1;
        a*=a;
        a%=mod;
    }
    return res;
}


int f(int n, int k)
{
//    if (dp[n][k] != -1)
//        return dp[n][k];
//    if (k>n)
//        return 0;
//    if ((n<0) or (k<0))
//        return 0;
//    if (n==0)
//        return (k==0);
//    if (k==0)
//        return (n==0);
//
//    if (2*k-1 < n)
//        return 0;
//    if (n==1)
//    {
//        return (k==1);
//    }
//    if (n==2)
//    {
//        return (k==2);
//    }
//
//    return dp[n][k] = (f(n-1, k-1) + f(n-2, k-1))%mod;

//    if (dp[n][k] != -1)
//        return dp[n][k];
    if ((n<0) or (k<0))
        return 0;
    if (k>n)
        return dp[n][k] = 0;
    if (n==0)
        return dp[n][k] = (k==0);
    if (k==0)
        return dp[n][k] = (n==0);

    if (2*k-1 < n)
        return dp[n][k] = 0;
    if (n==1)
    {
        return dp[n][k] = (k==1);
    }
    if (n==2)
    {
        return dp[n][k] = 2*(k==2);
    }

    if (n==3)
    {
        return dp[n][k] = 2*(k==2) + 4*(k==3);
    }

            #define f(a, b) dp[a][b]
    int res = 2*f(n-1, k-1) + 2*f(n-2, k-1);
    res += 2*(k-1)*f(n-3, k-2);

    int ans = 0;
    for (int i=3; i<=(n+2)/2; i++)
    {
        int rt = n + 1 - i;
        if (rt < i)
            continue;
        int coeff;
        if (rt == i)
            coeff = 1;
        else
            coeff=2;
        //7 100000007
        int j0 = max((i-1)/2, k-n+i-1);
        int j1 = min(min(i, k-(n-i)/2+1), k-1);
    for (int j=j0; j<=j1; j++)
        {
            /// i-1, n-i
            {
                int nt =
                       (f(i-2, j)*f(n-i-1, k-1-j)) + (f(i-2, j)*f(n-i, k-1-j)) + (f(i-1, j)*f(n-i-1, k-1-j));
                ans = (ans + coeff * (nt%mod) * cnk[k-1][j])%mod;
            }
            #undef f(a, b)
        }
    }

    return dp[n][k] = (res + ans)%mod;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    memset(dp, 255, sizeof(dp));


    int n;
    cin>>n>>mod;
    pow2[0]=1;
    for (int i=1; i<500; i++)
        pow2[i] = (2*pow2[i-1])%mod;
    rf[0] = 1;
    for (int i=1; i<500; i++)
        rf[i] = (i*rf[i-1])%mod;
    for (int i=0; i<500; i++)
        for (int j=0; j<=i; j++)
            cnk[i][j] = (((rf[i] * bpow(rf[j], mod-2))%mod)*bpow(rf[i-j], mod-2))%mod;
//    cout<<cnk[5][2]<<"\n";

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            f(i, j);

    int res=0;
    for (int i=0; i<=n; i++)
        res+=dp[n][i];
//    for (int i=0; i<=n; i++)
//        res+=(f(n, i)*rf[i])%mod, res%=mod;

//    for (int i=1; i<=n; i++)
//        for (int j=0; j<=n; j++)
//            cout<<i<<" "<<j<<" "<<f(i, j)<<"\n";


    cout<<res%mod<<"\n";
}


//int dp[500];
//
//int f(int n)
//{
//    if (dp[n] != -1)
//        return dp[n];
//
//    if (n==0)
//        return 1;
//    if (n==1)
//        return 1;
//    if (n==2)
//        return 2;
//    if (n==3)
//        return 6;
//    int res = 2*f(n-1) + 2*f(n-2) + 2*f(n-3);
//
//    for (int i=3; i<=n-2; i++)
//    {
//        res += f(i-1) * f(n-i-1);
//        res += f(i-2) * f(n-i-1);
//        res += f(i-2) * f(n-i);
//        res%=mod;
//    }
//    return dp[n] = (res%mod);
//
//}
//
//main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    memset(dp, 255, sizeof(dp));
//
//    int n;
//    cin>>n>>mod;
////    int res=0;
////    for (int i=0; i<=n; i++)
////        res+=f(n, i);
////
////    for (int i=1; i<=n; i++)
////        for (int j=0; j<=n; j++)
////            cout<<i<<" "<<j<<" "<<f(i, j)<<"\n";
//
//
//    cout<<f(n)<<"\n";
//}