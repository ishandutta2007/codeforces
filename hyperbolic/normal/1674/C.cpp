#include <stdio.h>
#include <string.h>

long long int power[110];

char x[110],y[110];
int main()
{
	power[0] = 1;
	for(int i=1;i<=50;i++) power[i] = 2*power[i-1];
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x+1,y+1);
		int a = strlen(x+1);
		int b = strlen(y+1);
		
		int c = 0;
		for(int i=1;i<=a;i++) if(x[i]=='a') c++;
		
		if(b==1)
		{
			if(y[1]=='a') printf("1\n");
			else printf("%lld\n",power[c]);
		}
		else
		{
			int d = 0;
			for(int i=1;i<=b;i++) if(y[i]=='a') d++;
			
			if(c==0) printf("1\n");
			else if(d>=1) printf("-1\n");
			else printf("%lld\n",power[c]);
		}
	}
}