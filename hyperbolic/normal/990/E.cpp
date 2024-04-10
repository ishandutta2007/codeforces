#include <stdio.h>
#define MAX (long long int)1e16

int check[1000010],T[2000010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		check[d] = 1;
	}
	if(check[0]==1)
	{
		printf("-1");
		return 0;
	}
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0) p = i;
		T[i] = p;
	}
	for(int i=a+1;i<=2*a;i++) T[i] = a;
	
	long long int ans = MAX;
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		
		long long int sum = 0;
		int start = 0;
		while(start<a)
		{
			int t = T[start+i];
			if(t<=start) goto u;
			sum+=d;
			start = t;
		}
		ans = ans<sum?ans:sum;
		u:;
	}
	if(ans==MAX) printf("-1");
	else printf("%lld",ans);
}