// Hydro submission #62d29d23b36e4a12382afc4e@1657969956520
#include<bits/stdc++.h>
using namespace std;
set<int> st[100001];
int c[100001];
int main()
{
	int n,m,a,b,mn=100001,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		mn=min(mn,c[i]);
	}
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		if(c[a]!=c[b])
		{
			st[c[a]].insert(c[b]);
			st[c[b]].insert(c[a]);
		}
	}
	for(i=1;i<=n;i++)
	if(st[i].size()>st[mn].size())
	mn=i;
	printf("%d\n",mn);
	return 0;
}