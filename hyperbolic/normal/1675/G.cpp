#include <stdio.h>
#define MAX 123456789
int a,b;
int x[1010];
int check[260][260][510];
int abs(int k)
{
	return k>0?k:-k;
}

int func(int s, int t, int k)
{
	if(-b<=k&&k<=b);
	else return MAX;
	
	if((s-1)*t > b) return MAX;
	if(check[s][t][k+250]!=-1) return check[s][t][k+250];
	if(s>a)
	{
		if(k==0) return 0;
		else return MAX;
	}
	
	int v = x[s] + k;
	int ans = MAX;
	for(int i=0;i<=t;i++)
	{
		int val = func(s+1,i,v-i)+abs(v-i);
		ans = ans<val?ans:val;
	}
	return check[s][t][k+250] = ans;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a+1;i++) for(int j=0;j<=b;j++) for(int k=0;k<=500;k++) check[i][j][k] = -1;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = MAX;
	for(int i=0;i<=b;i++)
	{
		int val = func(2,i,x[1]-i) + abs(x[1]-i);
		ans = ans<val?ans:val;
	}
	printf("%d",ans);
}