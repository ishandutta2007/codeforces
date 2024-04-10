#include <stdio.h>
#include <vector>
#define MAX (long long int)1e16

int x[100010];
std::vector<int> V1,V2;
int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) x[i] %= 2;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==1) V1.push_back(i);
			else V2.push_back(i);
		}
		
		long long int ans = MAX;
		long long int sum = 0;
		// type1
		for(int i=1;i<=a;i+=2)
		{
			int p = (i-1)/2;
			if(p>=V1.size()) goto u1;
			sum += abs(i-V1[p]);
		}
		for(int i=2;i<=a;i+=2)
		{
			int p = (i-2)/2;
			if(p>=V2.size()) goto u1;
			sum += abs(i-V2[p]);
		}
		ans = ans<sum?ans:sum;
		u1:;
		
		sum = 0;
		for(int i=1;i<=a;i+=2)
		{
			int p = (i-1)/2;
			if(p>=V2.size()) goto u2;
			sum += abs(i-V2[p]);
		}
		for(int i=2;i<=a;i+=2)
		{
			int p = (i-2)/2;
			if(p>=V1.size()) goto u2;
			sum += abs(i-V1[p]);
		}
		ans = ans<sum?ans:sum;
		u2:;
		
		if(ans==MAX) printf("-1\n");
		else printf("%lld\n",ans/2);
	}
}