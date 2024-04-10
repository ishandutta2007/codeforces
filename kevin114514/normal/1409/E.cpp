#include<bits/stdc++.h>
using namespace std;
pair<int,int> po[200100];
set<int> xp;
int have[200100];
int canget[200100];
int pre[200100];
int xpos[200100];
int maxget[200100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		xp.clear();
		int n,k;
		cin>>n>>k;
		for(int i=0;i<=n+10;i++)
			have[i]=canget[i]=pre[i]=xpos[i]=maxget[i]=0;
		for(int i=0;i<n;i++)
			cin>>po[i].first;
		for(int i=0;i<n;i++)
			cin>>po[i].second;
		xp.clear();
		for(int i=0;i<n;i++)
			xp.insert(po[i].first);
		sort(po,po+n);
		set<int>::iterator it=xp.begin();
		int pp=1;
		for(int i=0;i<n;i++)
		{
			if(po[i].first!=*it)
			{
				pp++;
				it++;
				have[pp]++;
			}
			else
			{
				have[pp]++;
			}
		}
		it=xp.begin();
		int ppp=0;
		while(it!=xp.end())
		{
			xpos[++ppp]=*it;
			it++;
		}
		pre[0]=0;
		for(int i=1;i<=pp;i++)
			pre[i]=pre[i-1]+have[i];
		//cout<<"test:"<<pre[1]<<endl;
		for(int i=1;i<=pp;i++)
//			cout<<xpos[lower_bound(xpos+1,xpos+pp+1,xpos[i]+k+1)-xpos-1]<<" "<<xpos[i]<<endl,
			canget[i]=pre[lower_bound(xpos+1,xpos+pp+1,xpos[i]+k+1)-xpos-1]-pre[i-1];
		for(int i=pp;i;i--)
			maxget[i]=max(maxget[i+1],canget[i]);
		int ans=0;
		for(int i=1;i<=pp;i++)
		{
			int nxt=lower_bound(xpos+1,xpos+pp+1,xpos[i]+k+1)-xpos;
			ans=max(ans,canget[i]+maxget[nxt]);
		}
		cout<<ans<<endl;
	}
	return 0;
}