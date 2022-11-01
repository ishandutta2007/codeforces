#include <bits\stdc++.h>

using namespace std;

int n,m,i,j,ans;

vector<pair<int,pair<int,int> > > pos;

string st[105];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for (j=1;j<=n;j++)
	{
		cin>>st[j];
		
		string pre=st[j].substr(0,3),mid=st[j].substr(4,4),suf=st[j].substr(9,3);
		
		for (i=0;i<3;i++)
		{
			int bad=0;
			if (i>0&&pre[i-1]=='S') bad++;
			if (i<2&&pre[i+1]=='S') bad++;
			if (pre[i]=='.') pos.push_back(make_pair(bad,make_pair(j,i))); else ans+=bad;
		}
		
		for (i=0;i<4;i++)
		{
			int bad=0;
			if (i>0&&mid[i-1]=='S') bad++;
			if (i<3&&mid[i+1]=='S') bad++;
			if (mid[i]=='.') pos.push_back(make_pair(bad,make_pair(j,i+4))); else ans+=bad;
		}
		
		for (i=0;i<3;i++)
		{
			int bad=0;
			if (i>0&&suf[i-1]=='S') bad++;
			if (i<2&&suf[i+1]=='S') bad++;
			if (suf[i]=='.') pos.push_back(make_pair(bad,make_pair(j,i+9))); else ans+=bad;
		}
	}
	
	sort(pos.begin(),pos.end());
	
	for (i=0;i<m;i++)
	{
		ans+=pos[i].first;
		st[pos[i].second.first][pos[i].second.second]='x';
	}
	
	cout<<ans<<endl;
	for (i=1;i<=n;i++) cout<<st[i]<<endl;
	
	return 0;
}