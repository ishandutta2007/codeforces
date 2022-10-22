#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
vector<int> pos[300010];
int ans[300010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,i;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			pos[i].clear();
			pos[i]={0};
			ans[i]=n+1;
		}
		for(i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			pos[a].push_back(i);
		}
		for(i=1;i<=n;i++)
			pos[i].push_back(n+1);
		for(i=1;i<=n;i++)
		{
			int xd=1;
			for(size_t j=1;j<pos[i].size();j++)
			{
				xd=max(xd,pos[i][j]-pos[i][j-1]);
			}
			ans[xd]=min(ans[xd],i);
		}
		ans[0]=n+1;
		for(i=1;i<=n;i++)
		{
			ans[i]=min(ans[i-1],ans[i]);
			if(ans[i]==n+1)
				cout<<"-1 ";
			else
				cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}