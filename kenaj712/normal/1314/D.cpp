#include<bits/stdc++.h>
using namespace std;
int cost[85][85];
bool blocked[85][85];
int dp[85];
int dp2[85];
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
            cin>>cost[x][y];
    for(int x=1;x<=a;x++)
        v.push_back(x);
    int t=10000;
    int mini=1e9+7;
    while(t--)
    {
        random_shuffle(v.begin(),v.end());
        for(int x=0;x<a/2;x++)
            for(int y=0;y<a/2;y++)
                blocked[v[x]][v[y]]=true;
        for(int x=a/2;x<a;x++)
            for(int y=a/2;y<a;y++)
                blocked[v[x]][v[y]]=true;
        int pom=b-1;
        for(int x=1;x<=a;x++)
        {
            if(!blocked[1][x])
                dp[x]=cost[1][x];
            else
                dp[x]=1e9+1;
        }

        while(pom--)
        {
            for(int x=1;x<=a;x++)
                dp2[x]=1e9+1;
            for(int x=1;x<=a;x++)
                for(int y=1;y<=a;y++)
                    if(!blocked[x][y] && dp[x]!=1e9+1)
                        dp2[y]=min(dp2[y],dp[x]+cost[x][y]);
            for(int x=1;x<=a;x++)
                dp[x]=dp2[x];
        }
        mini=min(mini,dp[1]);
        for(int x=1;x<=a;x++)
            for(int y=1;y<=a;y++)
                blocked[x][y]=false;
    }
    cout<<mini;
	return 0;
}