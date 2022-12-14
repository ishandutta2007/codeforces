#include <stdio.h>

char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		
		while(b)
		{
			char c;
			int control = 0;
			for(int i=1;i<=a;i++)
			{
				if(x[i]!='a')
				{
					if(control==0)
					{
						control = 1;
						c = x[i];
					}
					if(control==1)
					{
						if(x[i]-'a'>b) break;
						else c = c>x[i]?c:x[i];
					}
				}
			}
			
			if(control==0) break;
			for(int i=1;i<=a;i++) if(x[i]==c) x[i]--;
			b--;
		}
		
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		printf("\n");
	}
}