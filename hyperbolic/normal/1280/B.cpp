#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		int L = b+1, R = 0, U = a+1, D = 0;
		int control;
		//case 1
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='A') goto u1;
		
		printf("MORTAL\n");
		goto v;
		u1:;
		//case 2
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='P')
				{
					L = L<j?L:j;
					R = R>j?R:j;
					U = U<i?U:i;
					D = D>i?D:i;
				}
			}
		}
		if(L>R)
		{
			printf("0\n");
			goto v;
		}
		
		control = 1;
		for(int j=L;j<=R;j++) if(x[1][j]=='P') control = 0;
		if(control)
		{
			printf("1\n");
			goto v;
		}
		control = 1;
		for(int j=L;j<=R;j++) if(x[a][j]=='P') control = 0;
		if(control)
		{
			printf("1\n");
			goto v;
		}
		control = 1;
		for(int i=U;i<=D;i++) if(x[i][1]=='P') control = 0;
		if(control)
		{
			printf("1\n");
			goto v;
		}
		control = 1;
		for(int i=U;i<=D;i++) if(x[i][b]=='P') control = 0;
		if(control)
		{
			printf("1\n");
			goto v;
		}
		
		//case 3
		if(x[1][1]=='A' || x[1][b]=='A' || x[a][1]=='A' || x[a][b]=='A')
		{
			printf("2\n");
			goto v;
		}
		//case 3.5
		
		for(int i=1;i<=a;i++)
		{
			control = 1;
			for(int j=1;j<=b;j++) if(x[i][j]=='P') control = 0;
			if(control==1)
			{
				printf("2\n");
				goto v;
			}
		}
		
		for(int j=1;j<=b;j++)
		{
			control = 1;
			for(int i=1;i<=a;i++) if(x[i][j]=='P') control = 0;
			if(control==1)
			{
				printf("2\n");
				goto v;
			}
		}
		
		//case 4
		control = 0;
		for(int i=1;i<=a;i++) if(x[i][1]=='A') control = 1;
		for(int i=1;i<=a;i++) if(x[i][b]=='A') control = 1;
		for(int j=1;j<=b;j++) if(x[1][j]=='A') control = 1;
		for(int j=1;j<=b;j++) if(x[a][j]=='A') control = 1;
		if(control)
		{
			printf("3\n");
			goto v;
		}
		
		//case 5
		printf("4\n");
		v:;
	}
}