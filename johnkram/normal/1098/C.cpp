#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,m,N,a[MAXN],b[MAXN],f[MAXN],d[MAXN],i,j,k,l;
int main()
{
	cin>>n>>m;
	if(m<2*n-1||m>n*(n+1)/2)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(i=1;i<n;i++)
	{
		for(j=1,k=1,l=0;k+l<=n;l+=k,k*=i,j++)a[i]+=j*k;
		a[i]+=j*(n-l);
		if(a[i]<=m)break;
	}
	N=i;
	for(i=1;i<=n;i++)d[i]=i;
	for(i=1;i<=n;i++)a[i]=1;
	for(i=n,j=2,k=n*(n+1)/2;k>m;i--)
	{
		if(a[j]==a[j-1]*N)j++;
		if(k-m<d[i]-j)j=d[i]+m-k;
		a[d[i]]--;
		k-=d[i]-j;
		d[i]=j;
		a[d[i]]++;
	}
	sort(d+1,d+n+1);
	memset(a,0,sizeof(a));
	for(i=2,j=1;i<=n;i++)
	{
		for(;a[j]==N;j++);
		for(;d[j]!=d[i]-1;j++);
		printf("%d ",j);
		a[j]++;
	}
	return 0;
}