#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pow npow
using namespace std;

int M=1e9+7;
int pow(int a, int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    int x=pow(a, b/2);
    x*=x;
    x%=M;
    x*=pow(a, b%2);
    x%=M;
    return x;
}

int f[100500];

int c[4010][4010];

int cnk(int n, int k)
{
//    int x= (((f[n]*pow(f[k], M-2))%M)*pow(f[n-k], M-2))%M;
//    if (x!=c[n][k])
//        cout<<"WAR\n";
    return c[n][k];
}

int dp[100500][2];


main()
{

    f[0]=1;
    for (int i=1; i<100500; i++)
    {
        f[i]=(f[i-1]*i)%M;
    }
    int n;
    cin>>n;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=i; j++)
    {
        if (j==0)
            c[i][j]=1;
        else
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
    }
//    dp[1][0]=1;
//    dp[1][1]=1;
    dp[0][0]=1;
    dp[0][1]=0;
    for (int i=1; i<=n; i++)
    {
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
        dp[i][0]=2*dp[i-1][0];
        dp[i][0]%=M;
        dp[i][1]%=M;
        for (int j=1; j<i; j++)
        {
            dp[i][1]+=dp[i-j-1][1]*cnk(i-1, j);
            dp[i][0]+=dp[i-j-1][0]*cnk(i-1, j);
            dp[i][0]%=M;
            dp[i][1]%=M;
        }
    }
    cout<<dp[n][1]<<"\n";
    return 0;
}