#include <bits/stdc++.h>
using namespace std;

int n,i,j;
int a[2222];
set<int> s;

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int ans=0;
	for (i=0;i<=n;i++)
	{
		s.clear();
		for (j=1;j<=i;j++)
		{
			if (s.count(a[j])) break;
			s.insert(a[j]);
		}
		if(j<=i) break;
		
		int ss=i;
		for (j=n;j>i;j--)
		{
			if (s.count(a[j])) break;
			s.insert(a[j]);
			ss++;
		}
		
		ans=max(ans,ss);
	}
	
	cout<<n-ans<<endl;
	return 0;
}