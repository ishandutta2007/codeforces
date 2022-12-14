#include <stdio.h>
#define MAX 1234567890
int a,b,c,d;
char x[1010][1010];
int check[1010][1010];
int func(int s, int t)
{
	if(t==b+1) return func(s+1,1);
	else if(t==b+2) return MAX;
	if(s>a) return 0;
	if(x[s][t]=='*') return func(s,t+1);
	
	if(check[s][t]) return check[s][t];
	
	int s1 = MAX, s2 = MAX;
	s1 = func(s,t+1) + c;
	if(x[s][t+1]=='.') s2 = func(s,t+2) + d;
	return check[s][t] = s1<s2?s1:s2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j] = '*';
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) check[i][j] = 0;
		
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		printf("%d\n",func(1,1));
	}
}