#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		
		for(int i=a;i>=1;i--)
		{
			if(x[i]=='1'&&b >= (a-i))
			{
				b -= (a-i);
				char temp = x[i];
				x[i] = x[a];
				x[a] = temp;
				break;
			}
		}
		
		for(int i=1;i<a;i++)
		{
			if(x[i]=='1'&&b >= (i-1))
			{
				b -= (i-1);
				char temp = x[i];
				x[i] = x[1];
				x[1] = temp;
				break;
			}
		}
		
		int ans = 0;
		for(int i=1;i<a;i++) ans += 10*(x[i]-'0') + (x[i+1]-'0');
		printf("%d\n",ans);
	}
}