#include <stdio.h>
#include <string.h>

char temp[1010],x[1010];

char getQuery(int a, int b)
{
	printf("? %d %d\n",a,b);
	fflush(stdout);
	
	scanf("%s",temp+1);
	return temp[1];
}

int main()
{
	while(1)
	{
		scanf("%s",x+1);
		if(x[1]=='e') break;
		
		char t = getQuery(0,1);
		if(t=='x')
		{
			printf("! 1\n");
			fflush(stdout);
			continue;
		}
		
		long long int L = 0, R = 0, start = 0;
		for(int i=0;i<30;i++)
		{
			char t = getQuery(1<<i,1<<(i+1));
			if(t=='x')
			{
				start = (1<<i);
				L = ((1<<i))+1;
				R = (1<<(i+1));
				break;
			}
		}
		
		long long int ans = 0;
		while(L<=R)
		{
			long long int h = (L+R)/2;
			char t = getQuery(start,h);
			if(t=='x')
			{
				ans = h;
				R = h-1;
			}
			else L = h+1;
		}
		printf("! %lld\n",ans);
		fflush(stdout);
	}
}