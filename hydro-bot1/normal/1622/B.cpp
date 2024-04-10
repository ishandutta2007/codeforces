#include<bits/stdc++.h>
using namespace std;
pair<int,int> sr[233333];
int ans[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	string str;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>sr[i].first;
			sr[i].second=i;
		}
		cin>>str;
		for(int i=1;i<=n;i++)
			if(str[i-1]=='1')
				sr[i].first+=n;
		sort(sr+1,sr+n+1);
		for(int i=1;i<=n;i++)
			ans[sr[i].second]=i;
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<" \n"[i==n];
	}
	
	return 0;
}