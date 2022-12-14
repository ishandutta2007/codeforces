#include <stdio.h>
#define MAX 1234567890
int a,b,c,d,e;
int check[100010];
char x[100010];
int func(int k)
{
	if(k>a) return 0;
	if(check[k]!=-1) return check[k];
	
	if(x[k]=='1') return check[k] = func(k+c);
	else return check[k] = func(k+c)+d;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",x+1);
		scanf("%d%d",&d,&e);
		
		for(int i=1;i<=a;i++) check[i] = -1;
		int ans = MAX;
		for(int i=b;i<=a;i++)
		{
			int k = func(i) + (i-b)*e;
			ans = ans<k?ans:k;
		}
		printf("%d\n",ans);
	}
}