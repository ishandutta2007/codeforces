#include <stdio.h>
#include <vector>

std::vector<char> x[1000010];
int check[1000010],sum[1000010];
char y[1000010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=0;j<=b;j++) x[i].push_back('.');
	
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		for(int j=1;j<=b;j++) x[i][j] = y[j];
	}
	
	for(int i=2;i<=a;i++) for(int j=1;j<b;j++) if(x[i][j]=='X'&&x[i-1][j+1]=='X') check[j] = 1;
	
	for(int j=1;j<=b;j++) sum[j] = sum[j-1] + check[j];
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		int t = sum[e-1] - sum[d-1];
		if(t==0) printf("YES\n");
		else printf("NO\n");
	}
}