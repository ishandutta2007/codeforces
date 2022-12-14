#include <stdio.h>
#define MIN -12345678

int a,b;
int check[210][210][210];
char x[210],y[3];
int func(int s, int t, int k)
{
	if(k>b) return MIN;
	if(s>a) return 0;
	if(check[s][t][k]!=-1) return check[s][t][k];
	
	if(y[1]==y[2])
	{
		int s1=0,s2=0;
		if(x[s]==y[1]) s1 = func(s+1,t+1,k)+t;
		else s1 = func(s+1,t+1,k+1)+t;
		if(x[s]==y[1]) s2 = func(s+1,t+1,k)+t;
		else s2 = func(s+1,t,k);
		return check[s][t][k] = s1>s2?s1:s2;
	}
	else
	{
		int s1=0,s2=0,s3=0;
		if(x[s]==y[1]) s1 = func(s+1,t+1,k);
		else s1 = func(s+1,t+1,k+1);
		if(x[s]==y[2]) s2 = func(s+1,t,k)+t;
		else s2 = func(s+1,t,k+1)+t;
		if(x[s]==y[1]) s3 = func(s+1,t+1,k);
		else if(x[s]==y[2]) s3 = func(s+1,t,k)+t;
		else s3 = func(s+1,t,k);
		return check[s][t][k] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
	}
}
int main()
{
	for(int i=0;i<=200;i++) for(int j=0;j<=200;j++) for(int k=0;k<=200;k++) check[i][j][k] = -1;
	scanf("%d%d",&a,&b);
	scanf("%s%s",x+1,y+1);
	printf("%d",func(1,0,0));
}