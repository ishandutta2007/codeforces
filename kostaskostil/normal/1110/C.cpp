#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int dp[100];

int res(int q)
{
    int j=27;
    while ((1<<j)>q)
        j--;
    if (q==2*(1<<j)-1)
        return dp[j+1];
    return 2*(1<<j)-1;
}

int res0(int q)
{
    int v=0;
    for (int i=1; i<q; i++)
        v=max(v, __gcd(i^q, i&q));
    return v;
}

main()
{
    int q;
    int n;

dp[1]=0;
dp[2]=1;
dp[3]=1;
dp[4]=5;
dp[5]=1;
dp[6]=21;
dp[7]=1;
dp[8]=85;
dp[9]=73;
dp[10]=341;
dp[11]=89;
dp[12]=1365;
dp[13]=1;
dp[14]=5461;
dp[15]=4681;
dp[16]=21845;
dp[17]=1;
dp[18]=87381;
dp[19]=1;
dp[20]=349525;
dp[21]=299593;
dp[22]=1398101;
dp[23]=178481;
dp[24]=5592405;
dp[25]=1082401;

   // for (int i=1; i<=100; i++)
     //   cout<<i<<" "<<res(i)<<" "<<res0(i)<<"\n";

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>q;
        cout<<res(q)<<"\n";
    }
    return 0;
}