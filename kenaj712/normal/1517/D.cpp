#include<bits/stdc++.h>
using namespace std;
int dp[505][505][15];
vector<pair<pair<int,int> , int>> pol[505][505];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,k;
    cin>>a>>b>>k;
    if(k%2==1)
    {
        for(int x=1;x<=a;x++)
        {
            for(int y=1;y<=b;y++)
                cout<<-1<<" ";
            cout<<'\n';
        }
        return 0;
    }
    k/=2;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
            for(int z=1;z<=k;z++)
                dp[x][y][z] = 1e9;
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<b;y++)
        {
            int c;
            cin>>c;
            pol[x][y].push_back(make_pair(make_pair(x,y+1) , c));
            pol[x][y+1].push_back(make_pair(make_pair(x,y) , c));
        }
    }
    for(int x=1;x<a;x++)
    {
        for(int y=1;y<=b;y++)
        {
            int c;
            cin>>c;
            pol[x][y].push_back(make_pair(make_pair(x+1,y) , c));
            pol[x+1][y].push_back(make_pair(make_pair(x,y) , c));
        }
    }
    for(int z=1;z<=k;z++)
        for(int x=1;x<=a;x++)
            for(int y=1;y<=b;y++)
                for(auto q:pol[x][y])
                {
                    dp[x][y][z] = min(dp[x][y][z] , dp[q.first.first][q.first.second][z-1] + q.second);
                    dp[x][y][z] = min(dp[x][y][z] , dp[x][y][z-1] + q.second);
                }
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<=b;y++)
            cout<<dp[x][y][k]*2<<" ";
        cout<<'\n';
    }
	return 0;
}