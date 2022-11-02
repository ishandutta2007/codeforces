#include<bits/stdc++.h>
using namespace std;
int war[205];
vector<int> pol[205];
vector<int> v2;
int spam[205][205];
int dp[205][205];
int b;
void dfs(int a,int parent)
{
    vector<vector<int>> v;
    for(auto x:pol[a])
        if(x!=parent)
        {
            dfs(x,a);
            for(int y=0;y<=b;y++)
                v2.push_back(spam[x][y]);
            v.push_back(v2);
            v2.resize(0);
        }
    for(int x=1;x<=v.size();x++)
        for(int y=0;y<=b;y++)
            dp[x][y]=max(dp[x-1][y]+v[x-1][max(b-y-1,y)],v[x-1][y]+dp[x-1][max(b-y-1,y)]);
    for(int x=0;x<=b;x++)
        spam[a][x+1]=dp[v.size()][x];
    v.resize(0);
    for(int x=0;x<204;x++)
        for(int y=0;y<204;y++)
            dp[x][y]=0;
    int licz=0;
    for(auto x:pol[a])
        if(x!=parent)
        {
            licz+=spam[x][b];
        }
    spam[a][0]=war[a]+licz;
    int maks=0;
    for(int x=b;x>=0;x--)
    {
        spam[a][x]=max(maks,spam[a][x]);
        maks=max(maks,spam[a][x]);
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,c,d;
	cin>>a>>b;
	for(int x=1;x<=a;x++)
        cin>>war[x];
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    dfs(1,-1);
    int maks=0;
    for(int x=0;x<=b;x++)
        maks=max(maks,spam[1][x]);
    cout<<maks;
	return 0;
}