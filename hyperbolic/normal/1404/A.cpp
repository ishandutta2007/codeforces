#include <stdio.h>

char x[300010],y[300010];
int count[3];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count[0] = count[1] = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		
		for(int i=1;i<=b;i++) y[i] = 0;
		for(int i=1;i<=b;i++)
		{
			for(int j=i;j<=a;j+=b)
			{
				if(x[j]!='?')
				{
					if(y[i]!=0 && y[i]!=x[j])
					{
						printf("NO\n");
						goto u;
					}
					y[i] = x[j];
				}
			}
		}
		
		for(int i=1;i<=b;i++) if(y[i]!=0) count[y[i]-'0']++;
		if(count[0]<=(b/2) && count[1]<=(b/2)) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}