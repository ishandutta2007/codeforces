#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
vector<int> e[100010];
int dfs(int x,int p,int b)
{
	if(x==b)
		return 0;
	for(auto v:e[x])
	{
		if(v==p)
			continue;
		int xd=dfs(v,x,b);
		if(xd!=-1)
			return xd+1;
	}
	return -1;
}
pair<int,int> fur(int x,int p)
{
	pair<int,int> y={-1,x};
	for(auto v:e[x])
	{
		if(v!=p)
			y=max(y,fur(v,x));
	}
	return {y.fi+1,y.se};
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,a,b,da,db,i;
	cin>>q;
	while(q--)
	{
		cin>>n>>a>>b>>da>>db;
		for(i=1;i<=n;i++)
			e[i].clear();
		for(i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int d=fur(fur(1,0).se,0).fi;
		if((2*da>=min(db,d))||(dfs(a,0,b)<=da))
			cout<<"Alice\n";
		else
			cout<<"Bob\n";
	}
	return 0;
}