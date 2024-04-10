#include<bits/stdc++.h>
using namespace std;
int tab[1000005][2];
int dp[1000005][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>a>>b;
	for(int x=2;x<=a;x++)
        cin>>tab[x][0];
    for(int x=2;x<=a;x++)
        cin>>tab[x][1];
    dp[1][1]=b;
    for(int x=2;x<=a;x++)
    {
        dp[x][0]=min(dp[x-1][0],dp[x-1][1])+tab[x][0];
        dp[x][1]=min(dp[x-1][0]+b+tab[x][1],dp[x-1][1]+tab[x][1]);
    }
    for(int x=1;x<=a;x++)
        cout<<min(dp[x][0],dp[x][1])<<" ";
	return 0;
}