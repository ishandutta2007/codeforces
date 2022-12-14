#include <stdio.h>

int x[200010],y[200010],count[110];
int check[400010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) count[x[i]]++;
	int max = 0;
	int p = -1;
	for(int i=1;i<=100;i++)
	{
		if(max<count[i])
		{
			max = count[i];
			p = i;
		}
	}
	
	int ans = 0;
	for(int i=1;i<=100;i++)
	{
		if(i==p) continue;
		
		for(int j=0;j<=2*a;j++) check[j] = -1;
		check[a] = 0;
		for(int j=1;j<=a;j++)
		{
			if(x[j]==p) y[j] = 1;
			else if(x[j]==i) y[j] = -1;
			else y[j] = 0;
		}
		
		int s = a;
		for(int j=1;j<=a;j++)
		{
			s += y[j];
			if(check[s]!=-1) ans = ans>j-check[s]?ans:j-check[s];
			if(check[s]==-1) check[s] = j;
		}
	}
	printf("%d",ans);
}