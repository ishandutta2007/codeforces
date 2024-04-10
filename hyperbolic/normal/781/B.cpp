#include <stdio.h>
#include <set>
char x[110],y[110];
struct str{
	int x0;
	int y0;
	int x1;
	int y1;
}S[1010];
int check[1010];
std::set<int> Set;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s%s",x+1,y+1);
		S[i].x0 = (x[1]-'A')*10000 + (x[2]-'A')*100 + (x[3]-'A'+1);
		S[i].y0 = (x[1]-'A')*10000 + (x[2]-'A')*100 + (y[1]-'A'+1);
		S[i].x1 = S[i].y1 = 1;
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(S[i].x0==S[j].x0 && S[i].y0==S[j].y0)
			{
				S[i].x1 = S[i].y1 = S[j].x1 = S[j].y1 = 0;
			}
			if(S[i].x0==S[j].x0 && S[i].y0!=S[j].y0)
			{
				S[i].x1 = S[j].x1 = 0;
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(S[i].x1==0 && S[i].y1==0)
		{
			printf("NO");
			return 0;
		}
	}
	for(int i=1;i<=a;i++) if(S[i].x1==0) check[i] = S[i].y0, Set.insert(S[i].y0);
	for(int k=1;k<=a;k++)
	{
		for(int i=1;i<=a;i++)
		{
			if(Set.find(S[i].x0)!=Set.end())
			{
				check[i] = S[i].y0;
				Set.insert(S[i].y0);
			}
		}
	}
	for(int i=1;i<=a;i++) if(check[i]==0) check[i] = S[i].x0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(check[i]==check[j])
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=a;i++)
	{
		printf("%c%c%c\n",check[i]/10000+'A',(check[i]/100)%100+'A',check[i]%100+'A'-1);
	}
}