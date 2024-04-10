#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c,d;
	cin>>c>>d;
    string a,b;
    cin>>a>>b;
    int maks = 0;
    for(int x=1;x<=a.size();x++)
        for(int y=1;y<=b.size();y++)
        {
            dp[x][y]=max(dp[x-1][y]-1,max(dp[x][y-1]-1 , dp[x-1][y-1]-2 + 4*(int)(a[x-1] == b[y-1])));
            dp[x][y]=max(dp[x][y],0);
            maks = max(maks,dp[x][y]);
        }

    cout<<maks;
	return 0;
}