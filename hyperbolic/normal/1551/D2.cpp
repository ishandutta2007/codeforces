#include <stdio.h>

char ans[110][110];
int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=100;i++) x[i] = 0;
		for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) ans[i][j] = 0;
		
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		c = (a*b/2) - c;
		
		int reverse = 0;
		if(a%2==1)
		{
			reverse = 1;
			int temp = b;
			b = a;
			a = temp;
			c = (a*b/2) - c;
		}
		
		int b2 = b, c2 = c,t;
		if(b%2==1)
		{
			if(c<a/2)
			{
				printf("NO\n");
				goto u;
			}
			for(int i=1;i<=a/2;i++) x[i]++;
			b2 --;
			c2 -= (a/2);
		}
		
		t = c2;
		for(int i=1;i<=a/2;i++)
		{
			int s = t<b2?t:b2;
			x[i] += s, t -= s;
		}
		
		if(t>0)
		{
			printf("NO\n");
			goto u;
		}
		for(int i=1;i<=a/2;i++)
		{
			if((b-x[i])%2==1)
			{
				printf("NO\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a/2;i++)
		{
			for(int j=1;j<=x[i];j++)
			{
				ans[2*i-1][j] = 'a' + (i+j)%2;
				ans[2*i][j] = 'a' + (i+j)%2;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=b-1;j>=1;j-=2)
			{
				if(ans[i][j]==0)
				{
					ans[i][j] = 'z' - (i+(j/2))%2;
					ans[i][j+1] = 'z' - (i+(j/2))%2;
				}
			}
		}
		
		printf("YES\n");
		if(reverse==0)
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=b;j++) printf("%c",ans[i][j]);
				printf("\n");
			}
		}
		else
		{
			for(int j=1;j<=b;j++)
			{
				for(int i=1;i<=a;i++) printf("%c",ans[i][j]);
				printf("\n");
			}
		}
		u:;
	}
}