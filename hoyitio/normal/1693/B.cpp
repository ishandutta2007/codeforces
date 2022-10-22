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
		vector<int> p(n+5),l(n+5),r(n+5);
		vector<vector<int>> son(n+5);
		for(int i=2;i<=n;i++)
		{
			cin>>p[i];
			son[p[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{
			cin>>l[i]>>r[i];
		}
		int ans=0;
		vector<long long> maxx(n+5);
		for(int i=n;i>=1;i--)
		{
			for(auto z:son[i])
			{
				maxx[i]+=maxx[z];
			}
			maxx[i]=min(maxx[i],(long long)r[i]);
			if(son[i].empty() or maxx[i]<l[i])ans++,maxx[i]=r[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}