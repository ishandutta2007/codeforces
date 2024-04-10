#include <stdio.h>
#include <set>

std::multiset<long long int> S;
int x[1000010];
long long int y[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=(a+1)/2;i++) scanf("%d",&x[i]);
	int b;
	scanf("%d",&b);
	for(int i=(a+1)/2+1;i<=a;i++) x[i] =b;
	
	if(b>0)
	{
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		if(sum>0) printf("%d",a);
		else printf("-1");
	}
	else
	{
		int k = a/2+1;
		long long int sum = 0;
		for(int i=1;i<=k;i++) sum += x[i];
		y[1] = sum;
		for(int i=2;i<=(a+1)/2;i++)
		{
			sum -= x[i-1];
			sum += x[i+k-1];
			y[i] = sum;
		}
		for(int i=1;i<=(a+1)/2;i++) S.insert(y[i]);
		
		for(int i=(a+1)/2;i>=1;i--)
		{
			long long int p = (a+1)/2 - i;
			
			std::multiset<long long int> :: iterator it = S.begin();
			if((*it)>p*(-b))
			{
				printf("%d",k+p);
				return 0;
			}
			it = S.find(y[i]);
			S.erase(it);
		}
		printf("-1");
	}
}