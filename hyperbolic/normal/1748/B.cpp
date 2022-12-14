#include <stdio.h>

int check[110];
char x[100010];
int func(int L, int R)
{
	for(int i=0;i<=9;i++) check[i] = 0;
	for(int i=L;i<=R;i++) check[x[i]-'0']++;
	int C = 0;
	for(int i=0;i<=9;i++) if(check[i]>0) C++;
	for(int i=0;i<=9;i++) if(check[i]>C) return 0;
	return 1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int ans = 0;
		for(int j=1;j<=100;j++)
		{
			for(int i=1;i+j-1<=a;i++)
			{
				int L = i, R = i+j-1;
				ans += func(L,R);
			}
		}
		printf("%d\n",ans);
	}
}