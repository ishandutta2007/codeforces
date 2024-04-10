#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
long long dp[1000005][4];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,r1,r2,r3,d;
    cin>>a>>r1>>r2>>r3>>d;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    dp[1][0]=tab[1]*r1+r3;
    dp[1][1]=min(r2+r1,(tab[1]+2)*r1)+d*2;
    dp[1][3]=1e16;
    dp[1][2]=1e16;
    for(int x=2;x<=a;x++)
    {
        dp[x][0]=tab[x]*r1+r3+min(dp[x-1][0],min(dp[x-1][2],dp[x-1][3]));
        dp[x][2]=tab[x]*r1+r3+dp[x-1][1];
        dp[x][1]=min(r2+r1,(tab[x]+2)*r1)+d*2+min(dp[x-1][0],min(dp[x-1][2],dp[x-1][3]));
        dp[x][3]=min(r2+r1,(tab[x]+2)*r1)+dp[x-1][1];
    }
    cout<<d*(a-1)+min(min(dp[a][0] , dp[a][1]) , min(dp[a][2] - d , dp[a][3]));
	return 0;
}