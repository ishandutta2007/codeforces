#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n+5),vis(n+5),ans(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(!vis[j] and (i==n or a[i]!=j))
				{
					vis[j]=1;
					ans[i]=j;
					break;
				}
			}
		}
		if(ans[n]==a[n])swap(ans[n],ans[n-1]);
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	
	return 0;
}