#include <bits/stdc++.h>
//#define int long long

using namespace std;

int n;
int dp[2][2][10000];
int a[10000],b[10000];

main()
{
    string s1,s2;
    cin>>s1>>s2;
    n=s1.size();
    for (int i=1; i<=n; i++)
    {
        if (s1[i-1]=='X')
            a[i]=1;
        if (s2[i-1]=='X')
            b[i]=1;
    }

    for (int i=0; i<=1; i++)
        for (int j=0; j<=1; j++)
            dp[i][j][1]=-1000;
    dp[a[1]][b[1]][1]=0;

    for (int i=2; i<=n; i++)
    {
        int r1=a[i];
        int r2=b[i];
        for (int j=0; j<=1; j++)
            for (int k=0; k<=1; k++)
                dp[r1][r2][i]=max(dp[r1][r2][i], dp[j][k][i-1]);

        if ((r1==0) and (a[i-1]==0) and (b[i-1]==0))
            dp[1][r2][i]=max(dp[1][r2][i], dp[0][0][i-1]+1);
        if ((r2==0) and (a[i-1]==0) and (b[i-1]==0))
            dp[r1][1][i]=max(dp[r1][1][i], dp[0][0][i-1]+1);
        if ((r1==0) and (r2==0))
        {
            for (int j=0; j<=1; j++)
                if (a[i-1]==0)
                    dp[1][1][i]=max(dp[1][1][i], dp[0][j][i-1]+1);
            for (int j=0; j<=1; j++)
                if (b[i-1]==0)
                    dp[1][1][i]=max(dp[1][1][i], dp[j][0][i-1]+1);}

        for (int i1=0; i1<=1; i1++)
            for (int j=0; j<=1; j++)
                if ((i1<r1) or (j<r2))
                    dp[i1][j][i]=0;

//        for (int i1=0; i1<=1; i1++)
//        for (int j=0; j<=1; j++)
//            cout<<dp[i1][j][i]<<" ";
//            cout<<"\n";
    }
    int ans=0;
     for (int i=0; i<=1; i++)
        for (int j=0; j<=1; j++)
            ans=max(ans,dp[i][j][n]);
    cout<<ans<<"\n";
    return 0;
}