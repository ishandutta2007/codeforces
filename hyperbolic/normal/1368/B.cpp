#include <stdio.h>

char x[11]={0,'c','o','d','e','f','o','r','c','e','s'};
int count[110];
int main()
{
	long long int a;
	scanf("%lld",&a);
	int p = 1;
	while(1)
	{
		long long int S = 1;
		for(int i=1;i<=10;i++) S *= count[i];
		if(S>=a)
		{
			for(int i=1;i<=10;i++) for(int j=1;j<=count[i];j++) printf("%c",x[i]);
			return 0;
		}
		if(p==11) p = 1;
		count[p]++;
		p++;
	}
}