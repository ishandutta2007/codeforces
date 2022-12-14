#include <stdio.h>

int check[110][110][3];
int func(int s, int t, int target)
{
	if(s==0&&t==0)
	{
		if(target==0) return 1;
		else return 0;
	}
	if(check[s][t][target]!=-1) return check[s][t][target];
	
	int parity = t;
	
	int s1 = 0, s2 = 0;
	if(s>=1)
	{
		if(func(s-1,t,(parity+1+target)%2)) s1 = 0;
		else s1 = 1;
	}
	if(t>=1)
	{
		if(func(s,t-1,(parity+1+target)%2)) s2 = 0;
		else s2 = 1;
	}
	return check[s][t][target] = s1>s2?s1:s2;
}

int count[110];
int main()
{
	for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) for(int k=0;k<=1;k++) check[i][j][k] = -1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count[0] = count[1] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			count[(b%2+10)%2]++;
		}
		
		if(func(count[0],count[1],0)) printf("Alice\n");
		else printf("Bob\n");
	}
}