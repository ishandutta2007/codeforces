#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int n,m,p;
 	cin>>n>>m;
 	bool flag;
 	int a[n];
 	for(int i=0;i<n;i++)
 	{
 		cin>>a[i];
	}
	int l=0,r=m,mid;
	while (l<r)
	{
		mid=(l+r>>1);
		if(m-a[0]<=mid)p=0;
		else p=a[0];
		flag=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]>p)
			{
				if(m-a[i]+p>mid)p=a[i];
			}
			else
			{
				if(p-a[i]>mid){flag=0;break;}
			}
		}
		if(flag)r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}