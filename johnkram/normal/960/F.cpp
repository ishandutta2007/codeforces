#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
struct edge
{
	int x,y,z;
}e[100005];
pair<int,int> p;
set<pair<int,int> > s[100005];
set<pair<int,int> >::iterator it;
int n,m,i,ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)s[i].insert(mp(-1,0));
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		it=s[e[i].x].lower_bound(mp(e[i].z,0));
		if(it==s[e[i].x].begin())continue;
		it--;
		p.first=e[i].z;
		p.second=it->second+1;
		for(;;)
		{
			it=s[e[i].y].lower_bound(p);
			if(it==s[e[i].y].end()||it->second>p.second)break;
			s[e[i].y].erase(it);
		}
		if(it!=s[e[i].y].begin())
		{
			it--;
			if(it->second>=p.second)continue;
		}
		s[e[i].y].insert(p);
	}
	for(i=1;i<=n;i++)for(it=s[i].begin();it!=s[i].end();it++)ans=max(ans,it->second);
	cout<<ans<<endl;
	return 0;
}