#include <stdio.h>
#include <map>

std::map<long long int,int> check;
int main()
{
	for(int i=1;i<=10000;i++) check[(long long int)i*i*i] = 1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		for(int i=1;i<=10000;i++)
		{
			long long int s = (long long int)i*i*i;
			if(s>a) break;
			if(check.find(a-s)!=check.end())
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}