#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n+1),b(n+1),c(n+1),pb(n+1),vis(n+1);
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			pb[b[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(not vis[i])
			{
				int good=1,sz=0;
				for(int j=i;not vis[j];j=pb[a[j]])
				{
					sz++;
					vis[j]=1;
					if(c[j])
						good=0;
				}
				if(good and sz>1)ans=ans*2%MOD;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}