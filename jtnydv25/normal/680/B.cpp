#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,n,x;
	cin>>n>>a;
	int t[201];
	memset(t,0,sizeof t);
	for(int i = 1;i<=n;i++)
	{
		cin>>t[i];
	}
	int tot = 0;
	int ans = 0;
	for(int d = 0;d<=max(n-a,a-1);d++)
	{
		int dist = d;
		if(d == 0)
		{
			if(t[a]){
				ans++;
			}
			continue;
		}
		int ind1 = a-d;
		int ind2 = a+d;
		int cnt = 0;
		int crim  =0;
		if(ind1 >= 1)
		{
			cnt++;
			if(t[ind1])
				crim++;
		}
		if(ind2<=n)
		{
			cnt++;
			if(t[ind2])
				crim++;
		}
		if(crim==cnt)
			ans+=crim;
	}
	cout<<ans<<endl;
}