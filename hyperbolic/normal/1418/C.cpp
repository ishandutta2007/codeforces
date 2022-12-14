#include <stdio.h>

int check[200010][3];
int x[200010],a;
int func(int s, int t)
{
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	if(t==1)
	{
		int C = 0;
		if(x[s]==1) C++;
		int s1 = func(s+1,2)+C;
		if(x[s+1]==1) C++;
		int s2 = func(s+2,2)+C;
		return check[s][t] = s1<s2?s1:s2;
	}
	if(t==2)
	{
		int s1 = func(s+1,1);
		int s2 = func(s+2,1);
		return check[s][t] = s1<s2?s1:s2;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i][1] = check[i][2] = -1;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		x[a+1] = 0;
		printf("%d\n",func(1,1));
	}
}