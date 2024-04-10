#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,a[10005];
int n,m,N,i,j;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=29,x=m;i>1;i--,x+=m)if(n+1>=(1<<i))
	{
		for(j=N;j<N+i;j++)a[j]=x;
		N+=i;
		n-=(1<<i)-1;
	}
	for(;n;x+=m)
	{
		for(j=N;j<N+i;j++)a[j]=x;
		N+=i;
		n-=(1<<i)-1;
	}
	printf("%d\n",N);
	for(i=0;i<N;i++)cout<<a[i]<<' ';
	return 0;
}