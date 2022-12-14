#include <stdio.h>
#define MAX 1234567890

int a,S1,S2,S3,S4;

int find(int val, int k)
{
	for(int i=1;i<=k-1;i++) val /= 5;
	return val%5;
}
int power(int k)
{
	int ans = 1;
	for(int i=1;i<=k-1;i++) ans *= 5;
	return ans;
}
int max(int a, int b)
{
	return a>b?a:b;
}

char x[10][1010];
int check[10][1010][1010];
int func(int s, int t, int bit)
{
	if(t>a)
	{
		if(bit==0) return 0;
		else return MAX;
	}
	if(s==5) return func(1,t+1,bit);
	if(check[s][t][bit]!=-1) return check[s][t][bit];
	
	int s0 = MAX,s1 = MAX,s2 = MAX,s3 = MAX,s4 = MAX;
	if(x[s][t]=='.' || find(bit,s)>=1) s0 = func(s+1,t,bit - find(bit,s)*power(s) + max(power(s),find(bit,s)*power(s)) - power(s));
	s1 = func(s+1,t,bit - find(bit,s)*power(s) + max(power(s),find(bit,s)*power(s)) - power(s)) + S1;
	if(s+1<=4) s2 = func(s+1,t,bit - find(bit,s)*power(s) - find(bit,s+1)*power(s+1) + max(2*power(s),find(bit,s)*power(s)) - power(s) + max(2*power(s+1),find(bit,s+1)*power(s+1))) + S2;
	if(s+2<=4) s3 = func(s+1,t,bit - find(bit,s)*power(s) - find(bit,s+1)*power(s+1) - find(bit,s+2)*power(s+2) + max(3*power(s),find(bit,s)*power(s)) - power(s) + max(3*power(s+1),find(bit,s+1)*power(s+1)) + max(3*power(s+2),find(bit,s+2)*power(s+2))) + S3;
	if(s+3<=4) s4 = func(s+1,t,bit - find(bit,s)*power(s) - find(bit,s+1)*power(s+1) - find(bit,s+2)*power(s+2) - find(bit,s+3)*power(s+3) + max(4*power(s),find(bit,s)*power(s)) - power(s) + max(4*power(s+1),find(bit,s+1)*power(s+1)) + max(4*power(s+2),find(bit,s+2)*power(s+2)) + max(4*power(s+3),find(bit,s+3)*power(s+3))) + S4;
	
	int ans = s0;
	ans = ans<s1?ans:s1;
	ans = ans<s2?ans:s2;
	ans = ans<s3?ans:s3;
	ans = ans<s4?ans:s4;
	return check[s][t][bit] = ans;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=4;i++) for(int j=1;j<=a;j++) for(int k=0;k<=1000;k++) check[i][j][k] = -1;
	
	scanf("%d%d%d%d",&S1,&S2,&S3,&S4);
	
	for(int i=1;i<=4;i++) scanf("%s",x[i]+1);
	printf("%d",func(1,1,0));
}