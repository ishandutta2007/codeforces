#include <stdio.h>

int check[110][110];
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=1;i++) for(int j=1;j<=2;j++) check[j][i] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i+=2) check[1][x[i]%2] = 1;
		for(int i=2;i<=a;i+=2) check[2][x[i]%2] = 1;
		int s1 = check[1][0] + check[1][1];
		int s2 = check[2][0] + check[2][1];
		if(s1==1&&s2==1) printf("YES\n");
		else printf("NO\n");
	}
}