#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	vector<long long> f(55);
	f[0]=f[1]=1;
	for(int i=2;i<=50;i++)f[i]=f[i-1]+f[i-2];
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<long long> a(n+5);
//		long long s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
//			s+=a[i];
		}
		auto check=[&](vector<long long> a,int pos)
		{
			a[pos]--;
			vector<int> vis(55);
			int mx=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=50;j>=0;j--)
				{
					if(a[i]>=f[j])
					{
						if(vis[j])return false;
						vis[j]=i;
						a[i]-=f[j];
						mx=max(mx,j);
					}
				}
			}
			if(vis[1]==pos)return false;
			for(int j=1;j<=mx;j++)
				if(not vis[j])
					return false;
			return true;
		};
		int ok=0;
		for(int sp=1;sp<=n;sp++)
		{
			if(check(a,sp))
			{
				ok=1;
				break;
			}
		}
		if(ok)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}