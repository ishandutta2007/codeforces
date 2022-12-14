#include <stdio.h>
#define MOD 1000000007
int a;
long long int check[200010][5];
long long int count[5];
long long int func(int s, int t)
{
	if(s>a)
	{
		if(t==0) return 1;
		else return 0;
	}
	
	if(check[s][t]!=-1) return check[s][t];
	long long int s1 = func(s+1,(t+0)%3) * count[0];
	long long int s2 = func(s+1,(t+1)%3) * count[1];
	long long int s3 = func(s+1,(t+2)%3) * count[2];
	s1%=MOD, s2%=MOD, s3%=MOD;
	return check[s][t] = (s1+s2+s3)%MOD;
}
int main()
{
	int b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=0;j<=2;j++) check[i][j] = -1;
	if(c-b<=100) for(int i=b;i<=c;i++) count[i%3]++;
	else
	{
		while(b%3!=0)
		{
			count[b%3]++;
			b++;
		}
		while(c%3!=0)
		{
			count[c%3]++;
			c--;
		}
		count[0] += (c-b)/3 + 1;
		count[1] += (c-b)/3;
		count[2] += (c-b)/3;
	}
	printf("%lld",func(1,0));
}