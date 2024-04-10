#include <stdio.h>

char x[1010][1010];
int A[1010],B[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		if(b%2==1)
		{
			printf("YES\n");
			for(int i=1;i<=b;i+=2) printf("1 2 ");
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=i+1;j<=a;j++)
				{
					if(x[i][j]==x[j][i])
					{
						printf("YES\n");
						for(int k=1;k<=b;k+=2) printf("%d %d ",i,j);
						printf("%d\n",i);
						goto u;
					}
				}
			}
			if(a==2)
			{
				printf("NO\n");
				goto u;
			}
			else
			{
				for(int i=1;i<=a;i++) A[i] = B[i] = -1;
				for(int i=1;i<=a;i++)
				{
					for(int j=1;j<=a;j++)
					{
						if(x[i][j]=='a') A[i] = j;
						if(x[i][j]=='b') B[i] = j;
					}
				}
				for(int i=1;i<=a;i++)
				{
					if(A[i]!=-1 && B[i]!=-1)
					{
						printf("YES\n");
						int c = b/2;
						if(c%2==1)
						{
							for(int j=1;j<=c;j+=2) printf("%d %d ",A[i],i);
							for(int j=1;j<c;j+=2) printf("%d %d ",B[i],i);
							printf("%d\n",B[i]);
						}
						else
						{
							for(int j=1;j<c;j+=2) printf("%d %d ",i,A[i]);
							for(int j=1;j<c;j+=2) printf("%d %d ",i,B[i]);
							printf("%d\n",i);
						}
						goto u;
					}
				}
				printf("NO\n");
			}
			printf("NO\n");
			u:;
		}
	}
}