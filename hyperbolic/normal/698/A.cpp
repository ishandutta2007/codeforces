#include <stdio.h>
int x[110];
int check[110][5];
int a;
int max(int a, int b)
{
	return a>b?a:b;
}
int func(int s, int t)
{
	if(s==a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	//0 rest 1 write 2 gym
	if(t==0)
	{
		int s1,s2,s3;
		s1 = func(s+1,0);
		if(x[s+1]%2==1) s2 = func(s+1,1)+1;
		else s2 = 0;
		if(x[s+1]/2==1) s3 = func(s+1,2)+1;
		else s3 = 0;
		return check[s][t] = max( max(s1,s2) , s3);
	}
	if(t==1)
	{
		int s1,s2;
		s1 = func(s+1,0);
		if(x[s+1]/2==1) s2 = func(s+1,2)+1;
		else s2 = 0;
		return check[s][t] = max(s1,s2);
	}
	if(t==2)
	{
		int s1,s2;
		s1 = func(s+1,0);
		if(x[s+1]%2==1) s2 = func(s+1,1)+1;
		else s2 = 0;
		return check[s][t] = max(s1,s2);
	}
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=0;i<=a;i++)
	{
		check[i][0] = check[i][1] = check[i][2] = -1;
	}
	printf("%d",a-func(0,0));
}