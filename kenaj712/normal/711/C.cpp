#include<bits/stdc++.h>
using namespace std;
long long dp[105][105][105];
long long cost[105][105];
long long war[105];
long long xd=1e18;
void pre()
{
    for(int x=0;x<=103;x++)
        for(int y=0;y<=103;y++)
            for(int z=0;z<=103;z++)
                dp[x][y][z]=1e18;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
    int a,b,c;
    cin>>a>>b>>c;
    for(int x=1;x<=a;x++)
        cin>>war[x];
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
            cin>>cost[x][y];
    if(war[1]==0)
    {
         for(int y=1;y<=b;y++)
            dp[1][y][1]=cost[1][y];
    }
    if(war[1]!=0)
        for(int y=1;y<=b;y++)
        {
            if(y==war[1])
                dp[1][y][1]=0;
            else
                dp[1][y][1]=1e18;
        }
    for(int x=2;x<=a;x++)
    {
        if(war[x]==0)
        {
            for(int y=1;y<=b;y++)
                for(int z=1;z<=c;z++)
                {
                    dp[x][y][z]=dp[x-1][y][z]+cost[x][y];
                    long long mini=1e18;
                    for(int q=1;q<=b;q++)
                        if(q!=y)
                            mini=min(mini,dp[x-1][q][z-1]);
                    dp[x][y][z]=min(dp[x][y][z],mini+cost[x][y]);
                    dp[x][y][z]=min(dp[x][y][z],xd);
                }
        }
        else
        {
            for(int y=1;y<=b;y++)
                for(int z=1;z<=c;z++)
                {
                    if(y!=war[x])
                        continue;
                    dp[x][y][z]=dp[x-1][y][z];
                    long long mini=xd;
                    for(int q=1;q<=b;q++)
                        if(q!=y)
                            mini=min(mini,dp[x-1][q][z-1]);
                    dp[x][y][z]=min(dp[x][y][z],mini);
                    dp[x][y][z]=min(dp[x][y][z],xd);
                }
        }
    }
    long long mini=1e18;
    for(int y=1;y<=b;y++)
        mini=min(mini,dp[a][y][c]);
    if(mini==xd)
        cout<<-1;
    else
        cout<<mini;
	return 0;
}