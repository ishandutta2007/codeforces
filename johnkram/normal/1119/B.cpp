#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define ll long long
int n,m,i,l,r,mid,a[MAXN],b[MAXN];
ll s;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	l=1;
	r=n+1;
	while(l+1<r)
	{
		mid=l+r>>1;
		for(i=1;i<=mid;i++)b[i]=a[i];
		sort(b+1,b+mid+1);
		for(i=mid,s=0;i>0;i-=2)s+=b[i];
		if(s<=m)l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}