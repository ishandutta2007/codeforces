#include <stdio.h>
#include <string.h>

char x[100010],y[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int b,c;
	scanf("%d%d",&b,&c);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='?') y[i] = '0';
		else y[i] = x[i];
	}
	
	long long int S1 = 0, S2 = 0;
	long long int sum = 0;
	for(int i=1;i<=a;i++)
	{
		if(y[i]=='0')
		{
			S1++;
			sum += c*S2;
		}
		else
		{
			S2++;
			sum += b*S1;
		}
	}
	long long int ans = sum;
	long long int S3 = 0, S4 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='?')
		{
			S1--;
			sum = (sum - S4*c - (S2-S4)*b + S3*b + (S1-S3)*c);
			ans = ans<sum?ans:sum;
			S2++;
			S4++;
		}
		if(x[i]=='0') S3++;
		if(x[i]=='1') S4++;
	}
	
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='?') y[i] = '1';
		else y[i] = x[i];
	}
	
	S1 = 0, S2 = 0;
	sum = 0;
	for(int i=1;i<=a;i++)
	{
		if(y[i]=='0')
		{
			S1++;
			sum += c*S2;
		}
		else
		{
			S2++;
			sum += b*S1;
		}
	}
	ans = ans<sum?ans:sum;
	S3 = 0, S4 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='?')
		{
			S2--;
			sum = (sum + S4*c + (S2-S4)*b - S3*b - (S1-S3)*c);
			ans = ans<sum?ans:sum;
			S1++;
			S3++;
		}
		if(x[i]=='0') S3++;
		if(x[i]=='1') S4++;
	}
	printf("%lld",ans);
}