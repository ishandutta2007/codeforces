#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> pocz[1000005];
vector<pair<int,int>> kon[1000005];
long long dp[100009][205];
pair<int,int> opt[100005];
multiset<pair<int,int>> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d,e,f,g;
    cin>>a>>b>>c;
    while(c--)
    {
        cin>>d>>e>>f>>g;
        pocz[d].push_back(make_pair(f+1,g));
        kon[e+1].push_back(make_pair(f+1,g));
    }
    for(int x=1;x<=a+1;x++)
    {
        for(int y=0;y<pocz[x].size();y++)
            s.insert(make_pair(-pocz[x][y].second,-pocz[x][y].first));
        for(int y=0;y<kon[x].size();y++)
            s.erase(s.lower_bound(make_pair(-kon[x][y].second,-kon[x][y].first)));
        if(s.empty()==true)
            opt[x]=make_pair(x+1,0);
        else
        {
            int pom1=-(*s.begin()).first,pom2=-(*s.begin()).second;
            opt[x]=make_pair(pom2,pom1);
        }
    }
    for(int x=2;x<=a+1;x++)
        for(int y=0;y<=b;y++)
            dp[x][y]=1e18;
    for(int x=1;x<=a;x++)
    {
        int pom1=opt[x].first,pom2=opt[x].second;
        for(int y=0;y<=b;y++)
        {
            dp[pom1][y]=min(dp[x][y]+pom2,dp[pom1][y]);
            dp[x+1][y+1]=min(dp[x][y],dp[x+1][y+1]);
        }
    }
    long long mini=1e18;
    for(int y=0;y<=b;y++)
        mini=min(mini,dp[a+1][y]);
    cout<<mini;


	return 0;
}