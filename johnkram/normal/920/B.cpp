#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
set<pii > s;
set<pii >::iterator it;
vector<pii > a[5005],b[5005];
int t,n,l[5005],r[5005],i,j,ans[5005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=5000;i++)
		{
			a[i].clear();
			b[i].clear();
		}
		memset(ans,0,sizeof(ans));
		s.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",l+i,r+i);
			a[l[i]].pb(mp(l[i],i));
			b[r[i]].pb(mp(l[i],i));
		}
		for(i=1;i<=5000;i++)
		{
			for(j=0;j<a[i].size();j++)s.insert(a[i][j]);
			for(j=0;j<b[i].size();j++)
			{
				it=s.find(b[i][j]);
				if(it!=s.begin()&&it!=s.end())s.erase(it);
			}
			if(!s.empty())
			{
				it=s.begin();
				ans[it->second]=i;
				s.erase(it);
			}
		}
		for(i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}