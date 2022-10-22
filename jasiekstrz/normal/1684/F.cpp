#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5;
int t[N+10];
map<int,int> mp;
pair<int,int> seg[N+10];
vector<int> bg[N+10];
vector<int> en[N+10];
multiset<int> op;
int solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		en[i].clear();
		bg[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		cin>>seg[i].fi>>seg[i].se;
		bg[seg[i].fi].push_back(i);
		en[seg[i].se].push_back(i);
	}
	int mxbg=n+1;
	op.clear();
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		for(auto v:bg[i])
			op.insert(i);
		if(mp.find(t[i])!=mp.end())
		{
			if(!op.empty() && (*op.begin())<=mp[t[i]])
			{
				mxbg=i;
				break;
			}
		}
		mp[t[i]]=i;
		for(auto v:en[i])
			op.erase(op.find(seg[v].fi));
	}
	int mnen=0;
	op.clear();
	mp.clear();
	for(int i=n;i>=1;i--)
	{
		for(auto v:en[i])
			op.insert(i);
		if(mp.find(t[i])!=mp.end())
		{
			if(!op.empty() && (*prev(op.end()))>=mp[t[i]])
			{
				mnen=i;
				break;
			}
		}
		mp[t[i]]=i;
		for(auto v:bg[i])
			op.erase(op.find(seg[v].se));
	}
	if(mxbg>n)
		return 0;
	mp.clear();
	int ans=mnen;
	for(int i=1,j=mnen,l=mnen;i<mxbg;i++)
	{
		for(auto v:bg[i])
		{
			int x=seg[v].se;
			while(l<x)
			{
				l++;
				mp[t[l]]=l;
			}
		}
		if(mp.find(t[i])!=mp.end())
			j=max(j,mp[t[i]]);
		ans=min(ans,j-i);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		cout<<solve()<<"\n";
	return 0;
}