#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int a0[1000500];
int dp[1000500][3][3];
int n, m, k;

int f(int i, int a, int b)
{
    if (dp[i][a][b]!=-1)
        return dp[i][a][b];
    if (i==m)
    {
        int d1=a0[i-1]-b;
        int d2=a0[i-2]-(a+b);
    int d=min(d1, d2);
    int v=0;
    for (int j=0; j<=min(2ll, d); j++)
        if (a0[i]>=j)
            v=max(v, j+(d2-j)/3+(d1-j)/3+(a0[i]-j)/3);
    return v;
    }


    int d1=0; int d2=0;
    if (i>2)
    {
        d1=a0[i-1]-b;
        d2=a0[i-2]-(a+b);
    }
    int d=min(d1, d2);
    int v=0;
    for (int j=0; j<=min(2ll, d); j++)
        if (a0[i]>=j)
            v=max(v, j+f(i+1, b, j)+(d2-j)/3);
    //cout<<i<<" "<<a<<" "<<b<<" "<<v<<"\n";
    return dp[i][a][b]=v;
}

main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>k, a0[k]++;
   // for (int i=1; i<=m; i++)
     //   cout<<a0[i]<<" ";
    //cout<<"\n";
    memset(dp, 255, sizeof(dp));
    cout<<f(1, 0, 0)<<"\n";
    return 0;
}