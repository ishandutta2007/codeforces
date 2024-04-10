#include <stdio.h>
#define MIN -1234567890

int a,b,c;
int x[100010];
int check[100010][10];

int func(int k, int s, int t)
{
	if(t>b) return 0;
	if(s>c) return MIN;
	if(check[k][s]) return check[k][s];
	
	if(k==a) return check[k][s] = func(k-1,s+1,t+1)+x[k];
	else if(k==1) return check[k][s] = func(k+1,s,t+1)+x[k];
	else
	{
		int s1 = func(k-1,s+1,t+1)+x[k];
		int s2 = func(k+1,s,t+1)+x[k];
		return check[k][s] = s1>s2?s1:s2;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) for(int j=0;j<=6;j++) check[i][j] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		printf("%d\n",func(1,0,0));
	}
}