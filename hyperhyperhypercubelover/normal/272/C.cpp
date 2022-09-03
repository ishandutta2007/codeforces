#include<cstdio>
#include<algorithm>

long long a[100000];

int main()
{
	long long i,j,n,m;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)scanf("%I64d",&a[i]);
	scanf("%I64d",&m);
	while(m--)
	{
		scanf("%I64d%I64d",&i,&j);
		printf("%I64d\n",std::max(a[0],a[i-1]));
        a[0]=std::max(a[0],a[i-1])+j;
	}
}