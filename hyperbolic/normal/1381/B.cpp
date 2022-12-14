#include <stdio.h>

int check[4010],next[4010];
int check2[4010][4010];
int a;
int x[4010];
int func(int s, int t)
{
	int k = s+t+1;
	if(k>2*a)
	{
		if(s==a&&t==a) return 1;
		else return 0;
	}
	if(check2[s][t]!=-1) return check2[s][t];
	
	int d = next[k]-k;
	int s1 = func(s+d,t);
	int s2 = func(s,t+d);
	if(s1==1||s2==1) return check2[s][t] = 1;
	else return check2[s][t] = 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
		
		for(int i=0;i<=2*a+1;i++) for(int j=0;j<=2*a+1;j++) check2[i][j] = -1;
		for(int i=1;i<=2*a+1;i++) check[i] = 0;
		check[2*a+1] = 2*a+1;
		for(int i=2*a;i>=1;i--)
		{
			int k = 2*a+1;
			for(int j=x[i]+1;j<=2*a+1;j++) if(check[j]!=0) k = check[j]<k?check[j]:k;
			
			next[i] = k;
			check[x[i]] = i;
		}
		
		printf("%s\n",func(0,0)==1?"YES":"NO");
	}
}