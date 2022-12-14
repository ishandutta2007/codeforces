#include <stdio.h>
#include <algorithm>

int sum[10][200010];
char p[5];
char x[200010],y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	p[0] = 'a', p[1] = 'b', p[2] = 'c';
	int C = 0;
	do{
		C++;
		for(int i=1;i<=a;i++) y[i] = p[i%3];
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=y[i]) sum[C][i] = 1;
			else sum[C][i] = 0;
		}
		for(int i=1;i<=a;i++) sum[C][i] += sum[C][i-1];
	}while(std::next_permutation(p,p+3));
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		int ans = 12345678;
		for(int j=1;j<=6;j++)
		{
			int t = sum[j][d] - sum[j][c-1];
			ans = ans<t?ans:t;
		}
		printf("%d\n",ans);
	}
}