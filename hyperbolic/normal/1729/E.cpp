#include <stdio.h>
#include <vector>
#include <algorithm>

long long int getQuery(int s, int t)
{
	printf("? %d %d\n",s,t);
	fflush(stdout);
	
	long long int a;
	scanf("%lld",&a);
	return a;
}

std::vector<long long int> V;
int main()
{
	long long int C = -1;
	for(int i=2;i<=26;i++)
	{
		long long int s = getQuery(1,i);
		long long int t = getQuery(i,1);
		C = s;
		if(s==-1)
		{
			printf("! %d",i-1);
			return 0;
		}
		if(s!=t)
		{
			printf("! %lld",s+t);
			return 0;
		}
	}
	printf("! %lld",2*C);
	return 0;
}