#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int a,b,c;
char x[3][2010];
long long int count[2010][2010];
int power[2010];

long long int check[2010][3][2010];
long long int func(int k, int type, int C)
{
	if(k>c)
	{
		if(C==0) return 1;
		else return 0;
	}
	if(check[k][type][C]!=-1) return check[k][type][C];
	
	if(k%2==0)
	{
		if(x[type][k]-'0'<b) return check[k][type][C] = 0;
		else if(x[type][k]-'0'>b) return check[k][type][C] = count[k+1][(a-((10*C+b)*power[k])%a)%a];
		else return check[k][type][C] = func(k+1,type,(10*C+b)%a);
	}
	else
	{
		int t = x[type][k]-'0';
		long long int ans = 0;
		for(int i=0;i<t;i++)
		{
			if(i==b) continue;
			ans += count[k+1][(a-((10*C+i)*power[k])%a)%a];
			ans %= MOD;
		}
		if(t!=b) ans += func(k+1,type,(10*C+t)%a);
		return check[k][type][C] = ans%MOD;
	}
}

int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s%s",x[1]+1,x[2]+1);
	c = strlen(x[1]+1);
	
	for(int i=1;i<=c;i++) for(int j=1;j<=2;j++) for(int k=0;k<a;k++) check[i][j][k] = -1;
	
	int C = 1;
	count[c+1][0] = 1;
	for(int i=c;i>=1;i--)
	{
		if(i%2==0)
		{
			for(int j=0;j<a;j++)
			{
				count[i][(j+C*b)%a] += count[i+1][j];
				count[i][(j+C*b)%a] %= MOD;
			}
		}
		else
		{
			for(int k=0;k<=9;k++)
			{
				if(k==b) continue;
				for(int j=0;j<a;j++)
				{
					count[i][(j+C*k)%a] += count[i+1][j];
					count[i][(j+C*k)%a] %= MOD;
				}
			}
		}
		C*=10, C%=a;
	}
	
	power[c] = 1;
	for(int i=c-1;i>=1;i--) power[i] = (power[i+1]*10)%a;
	
	long long int s1 = func(1,1,0);
	long long int s2 = func(1,2,0);
	long long int ans = s2-s1;
	int sum = 0;
	
	for(int i=1;i<=c;i++)
	{
		if(i%2==0&&x[1][i]-'0'!=b) goto u;
		if(i%2==1&&x[1][i]-'0'==b) goto u;
	}
	
	for(int i=1;i<=c;i++)
	{
		sum*=10;
		sum+=(x[1][i]-'0');
		sum%=a;
	}
	if(sum==0) ans++;
	u:;
	
	printf("%lld",(ans+MOD)%MOD);
}