#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,pair<int,int>>> v;
int solve1()
{
    long long maks = 0;
    long long sum = 0;
    int where = 0;
    while(v[where].second.second != 1)
        where++;
    int siemako = where;
    maks = max(maks , v[where].first + v[where].second.first);
    where++;
    while(where != v.size())
    {
        if(maks >= v[where].first)
        {
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
        else
        {
            sum += v[where].first - maks;
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
    }
    where = 0;
    maks = v[0].first;
    while(where != siemako + 1)
    {
        if(maks >= v[where].first)
        {
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
        else
        {
            sum += v[where].first - maks;
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
    }
    return sum;
}
int solve2()
{
    long long maks = 0;
    long long sum = 0;
    int where = 0;
    while(v[where].second.second != 1)
    {
        maks = max(maks , v[where].first + v[where].second.first);
        where++;
    }
    int siemako = where;
    where++;
    while(where != v.size())
    {
        if(maks >= v[where].first)
        {
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
        else
        {
            sum += v[where].first - maks;
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
    }
    where = 0;
    maks = v[0].first;
    while(where != siemako + 1)
    {
        if(maks >= v[where].first)
        {
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
        else
        {
            sum += v[where].first - maks;
            maks = max(maks , v[where].first + v[where].second.first);
            where++;
        }
    }
    return sum;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    long long sum = 0;
    for(int x=1;x<=a;x++)
    {
        int c,d;
        cin>>c>>d;
        sum += d;
        v.push_back(make_pair(c,make_pair(d,x)));
    }
    sort(v.begin(),v.end());
    cout<<sum + min(solve1(),solve2());
	return 0;
}