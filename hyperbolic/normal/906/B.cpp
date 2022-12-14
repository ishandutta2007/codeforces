#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<=3&&b<=3)
	{
		if(a==3&&b==3)
		{
			printf("YES\n");
			printf("2 9 4\n");
			printf("7 5 3\n");
			printf("6 1 8\n");
		}
		else if(a==1&&b==1)
		{
			printf("YES\n");
			printf("1");
		}
		else printf("NO");
	}
	else
	{
		if(a==1)
		{
			printf("YES\n");
			if(b==4) printf("3 1 4 2");
			else
			{
				for(int i=1;i<=b;i+=2) printf("%d ",i);
				for(int i=2;i<=b;i+=2) printf("%d ",i);
			}
			return 0;
		}
		if(b==1)
		{
			printf("YES\n");
			if(a==4) printf("3\n1\n4\n2\n");
			else
			{
				for(int i=1;i<=a;i+=2) printf("%d\n",i);
				for(int i=2;i<=a;i+=2) printf("%d\n",i);
			}
			return 0;
		}
		printf("YES\n");
		for(int i=1;i<=a;i++)
		{
			V[i].push_back(0);
			for(int j=1;j<=b;j++) V[i].push_back((i-1)*b+j);
		}
		if(a>=4)
		{
			for(int j=1;j<=b;j++)
			{
				if(j%2==0)
				{
					int s1 = V[1][j];
					int s2 = V[2][j];
					for(int i=1;i<=a-2;i++) V[i][j] = V[i+2][j];
					V[a-1][j] = s1;
					V[a][j] = s2;
				}
			}
			for(int i=1;i<=a;i++)
			{
				if(i%2==0)
				{
					int t1 = V[i][1];
					for(int j=1;j<=b-1;j++) V[i][j] = V[i][j+1];
					V[i][b] = t1;
				}
			}
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				if(i%2==0)
				{
					int s1 = V[i][1];
					int s2 = V[i][2];
					for(int j=1;j<=b-2;j++) V[i][j] = V[i][j+2];
					V[i][b-1] = s1;
					V[i][b] = s2;
				}
			}
			for(int j=1;j<=b;j++)
			{
				if(j%2==0)
				{
					int t1 = V[1][j];
					for(int i=1;i<=a-1;i++) V[i][j] = V[i+1][j];
					V[a][j] = t1;
				}
			}
		}
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) printf("%d ",V[i][j]);
			printf("\n");
		}
	}
}