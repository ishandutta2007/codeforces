#include <stdio.h>
#include <algorithm>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		if(x[a]==1)
		{
			printf("1\n");
			continue;
		}
		
		if(x[a]%3==0)
		{
			int ans = x[a]/3;
			int control = 0;
			for(int i=1;i<a;i++) if((x[i+1]-x[i])%3!=0) control = 1;
			printf("%d\n",ans+control);
		}
		else if(x[a]%3==1)
		{
			int ans = x[a]/3;
			int control = 0;
			for(int i=1;i<a;i++) if((x[i])%3==2) control = 1;
			if(control==0) printf("%d\n",ans+1);
			else
			{
				if(x[1]==1) printf("%d\n",ans+2);
				else
				{
					control = 0;
					for(int i=1;i<=a;i++) if(x[i]==x[a]-1) control = 1;
					printf("%d\n",ans+1+control);
				}
			}
		}
		else if(x[a]%3==2)
		{
			int ans = x[a]/3;
			int control = 0;
			for(int i=1;i<a;i++) if((x[i])%3==1) control = 1;
			if(control==0) printf("%d\n",ans+1);
			else printf("%d\n",ans+2);
		}
	}
}