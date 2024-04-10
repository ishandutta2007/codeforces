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
		vector<int> a(n+5);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)a[i]++,ans++;
		}
		vector<int> pa(n+5);
		function<int(int)> find=[&](int x){return pa[x]?pa[x]=find(pa[x]):x;};
		auto check=[&]()
		{
			pa.clear();
			pa.resize(n+35);
			int cnt=n+30;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<30;j++)
				{
					if((a[i]>>j)&1)
					{
						int pu=find(i),pv=find(n+j+1);
						if(pu!=pv)
						{
							pa[pv]=pu;
							cnt--;
						}
					}
				}
			}
			for(int j=0;j<30;j++)
				if(pa[n+j+1]==0)
					cnt--;
			return cnt==1;
		};
		if(not check())
		{
			int ok=0;
			ans++;
			for(int i=1;i<=n and not ok;i++)
			{
				a[i]++;
				ok=check();
				if(not ok)
				{
					a[i]-=2;
					ok=check();
					if(not ok)a[i]++;
				}
			}
			if(not ok)
			{
				int maxlb=0,pos=0;
				for(int i=1;i<=n;i++)
				{
					if((a[i]&-a[i])>maxlb)
					{
						maxlb=a[i]&-a[i];
						pos=i;
					}
				}
				a[pos]--;
				if(not check())
				{
					for(int i=1;i<=n;i++)
					{
						if(a[i]%2==0 and find(i)!=find(pos))
						{
							a[i]++;
							ans++;
							break;
						}
					}
				}
			}
		}
		assert(check());
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}