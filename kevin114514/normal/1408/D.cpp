#include<bits/stdc++.h>
using namespace std;
int rx[2020],ry[2020],sx[2020],sy[2020];
int p;
pair<int,int> pos[4000400];
int mx[1000100];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>rx[i]>>ry[i];
	for(int i=0;i<m;i++)
		cin>>sx[i]>>sy[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(sx[j]>=rx[i]&&sy[j]>=ry[i])
			{
				pos[p].first=sx[j]-rx[i];
				pos[p].second=sy[j]-ry[i];
				p++;
			}
	memset(mx,-1,sizeof(mx));
	sort(pos,pos+p);
	for(int i=0;i<p;i++)
		mx[pos[i].first]=max(mx[pos[i].first],pos[i].second);
	for(int i=1000000;i>=0;i--)
		mx[i]=max(mx[i],mx[i+1]);
	int ans=1e9;
	for(int i=0;i<=1000000;i++)
		ans=min(ans,i+mx[i]+1);
	cout<<ans<<endl;
	return 0;
}