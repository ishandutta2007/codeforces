#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<pair<int,int>> v2;
int dp[100005][105];
int f(int a,pair<int,int> p)
{
    if(a<p.first)
        return p.first-a;
    else if(a>p.second)
        return a-p.second;
    else
        return 0;
}
int f2(int a,pair<int,int> p)
{
    if(a<p.first)
        return a;
    else if(a>p.second)
        return max(1,p.first-(a-p.second));
    else
        return max(p.first,1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    while(a--)
    {
        cin>>c>>d;
        v.push_back(make_pair(max(1,c-d),max(-c-d,-b)));
    }
    sort(v.begin(),v.end());
    int maks=-1e9;
    for(auto x:v)
    {
        if(-x.second>maks)
        {
            maks=-x.second;
            v2.push_back(make_pair(x.first,-x.second));
        }
    }
    v=v2;
    for(int y=1;y<=b;y++)
        dp[y][0]=max(v[0].first-1,y-v[0].second);
    for(int x=1;x<v.size();x++)
    {
        dp[b+1][x]=1e6;
        for(int y=b;y>=0;y--)
            dp[y][x]=min(dp[y][x-1],min(dp[y+1][x],f(y,v[x])+min(dp[max(f2(y,v[x])-1,0)][x-1],max(f2(y,v[x])-1,0))));
    }


    cout<<dp[b][v.size()-1];
	return 0;
}