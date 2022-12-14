#include <stdio.h>
#define MAX 12345

int a,b;
char x[10010],y[10010];
short check[5010][5010][3];
short func(int s, int t, int type)
{
	if(t>b)
	{
		if(type==0) return 0;
		else if(type==2) return (a-s)+1;
		else return MAX;
	}
	if(s>a) return MAX;
	if(check[s][t][type]!=-1) return check[s][t][type];
	
	short s1 = MAX, s2 = MAX, s3 = MAX;
	if(type==1)
	{
		s1 = func(s,t,2);
		s2 = func(s+1,t,1) + 2;
		if(x[s]==y[t]) s3 = func(s+1,t+1,1)+1;
	}
	else if(type==2)
	{
		s1 = func(s,t,0) + (a-s)+1;
		if(x[s]==y[t]) s2 = func(s+1,t+1,2);
	}
	else
	{
		s1 = func(s+1,t,0);
		if(x[s]==y[t]) s2 = func(s+1,t+1,0);
	}
	
	short ans = MAX;
	ans = ans<s1?ans:s1;
	ans = ans<s2?ans:s2;
	ans = ans<s3?ans:s3;
	return check[s][t][type] = ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) for(int k=0;k<=2;k++) check[i][j][k] = -1;
		
		scanf("%s%s",x+1,y+1);
		
		int ans = func(1,1,1)+1;
		int val = func(1,1,2);
		ans = ans<val?ans:val;
		
		if(ans>=MAX) printf("-1\n");
		else printf("%d\n",ans);
	}
}