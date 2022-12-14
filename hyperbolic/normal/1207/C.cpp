#include <stdio.h>

long long int MAX = 1;
int a,b,c;
char x[200010];

long long int check[200010][5];

long long int func(int s, int t)
{
	if(s>a)
	{
		if(t==1) return 0;
		else return MAX;
	}
	
	if(check[s][t]!=0) return check[s][t];
	
	if(t==1)
	{
		if(x[s]=='1') return MAX;
		
		long long int s1 = 2*b + 2*c + func(s+1,2);
		long long int s2 = b + c + func(s+1,1);
		return check[s][t] = s1<s2?s1:s2;
	}
	else if(t==2)
	{
		if(x[s]=='1') return b+2*c+func(s+1,2);
		
		long long int s1 = 2*b + c + func(s+1,1);
		long long int s2 = b + 2*c + func(s+1,2);
		return check[s][t] = s1<s2?s1:s2;
	}
}

int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",x+1);
		
		for(int i=0;i<=a;i++) check[i][1] = check[i][2] = 0;
		printf("%lld\n",func(1,1)+c);
	}
}