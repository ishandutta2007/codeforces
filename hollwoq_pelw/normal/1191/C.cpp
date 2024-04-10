#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int curpage=1;
	int erased=0;
	int ans=0;
	int n,m,k;
	cin>>n>>m>>k;
	cin>>ans;
	curpage=(ans-1)/k+1;
	ans=0;
	for(int i=2; i<=m; i++)
	{
		int cac;
		cin>>cac;
		if((cac-erased-1)/k+1>curpage)
		{
			erased=i-1;
			curpage=(cac-erased-1)/k+1;
			ans++;
		}
	}
	cout<<ans+1;
	return 0;
}