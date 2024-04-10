#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll a[MAXN];
int n,b[MAXN],i,j;
ll get(ll x,ll y)
{
	ll p=x%y;
	if(p<0)p+=y;
	return (x-p)/y;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	b[0]=b[n];
	for(i=1;i<=n;i++)if(b[i]>b[i-1])break;
	if(i>n)
	{
		if(b[0])puts("NO");
		else for(puts("YES"),i=0;i<n;i++)printf("1 ");
		return 0;
	}
	puts("YES");
	for(a[i]=b[i],j=(i+n-2)%n+1;j!=i;j=(j+n-2)%n+1)a[j]=max(0LL,get(b[j-1]-b[j],a[j%n+1])+1)*a[j%n+1]+b[j];
	for(i=1;i<=n;i++)printf("%I64d ",a[i]);
	return 0;
}