#include <stdio.h>
#define MOD 1000003

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans *= k, ans %= MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int x[110][110],y[110];
void GaussJordan()
{
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			if(x[i][j]!=0)
			{
				long long int t = inv(x[i][j]);
				for(int k=0;k<11;k++) x[i][k] *= t, x[i][k] %= MOD;
				y[i] *= t, y[i] %= MOD;
				for(int i2=0;i2<11;i2++)
				{
					if(i==i2) continue;
					long long int s = x[i2][j];
					for(int j2=0;j2<11;j2++)
					{
						x[i2][j2] += s*(MOD-x[i][j2]);
						x[i2][j2] %= MOD;
					}
					y[i2] += s*(MOD-y[i]);
					y[i2] %= MOD;
				}
				break;
			}
		}
	}
	
	for(int i=10;i>=0;i--)
	{
		for(int j=0;j<11;j++)
		{
			if(x[i][j]!=0)
			{
				long long int t = inv(x[i][j]);
				for(int k=0;k<11;k++) x[i][k] *= t, x[i][k] %= MOD;
				y[i] *= t, y[i] %= MOD;
				for(int i2=0;i2<11;i2++)
				{
					if(i==i2) continue;
					long long int s = x[i2][j];
					for(int j2=0;j2<11;j2++)
					{
						x[i2][j2] += s*(MOD-x[i][j2]);
						x[i2][j2] %= MOD;
					}
					y[i2] += s*(MOD-y[i]);
					y[i2] %= MOD;
				}
				break;
			}
		}
	}
}

long long int func(long long int k)
{
	long long int ans = 0;
	long long int S = 1;
	for(int i=0;i<11;i++)
	{
		ans += S*y[i];
		ans %= MOD;
		S *= k;
		S %= MOD;
	}
	return ans;
}

int getQuery(int k)
{
	printf("? %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int main()
{
	for(int i=0;i<11;i++)
	{
		y[i] = getQuery(i);
		for(int j=0;j<11;j++) x[i][j] = power(i,j);
	}
	GaussJordan();
	
	for(int i=0;i<MOD;i++)
	{
		long long int t = func(i);
		if(t==0)
		{
			printf("! %d",i);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1");
	fflush(stdout);
}