#include <stdio.h>
#define MOD 998244353
int a,b;

long long int check1[200010],check2[200010];
long long int func2(int k);
long long int func1(int k)
{
	if(k==0) return 0;
	if(check1[k]!=-1) return check1[k];
	long long int S = (b-1)*func2(k-1);
	return check1[k] = S%MOD;
}
long long int func2(int k)
{
	if(k==0) return 1;
	if(check2[k]!=-1) return check2[k];
	long long int S = (b-2)*func2(k-1)+func1(k-1);
	return check2[k] = S%MOD;
}

int x[200010];
int main()
{
	for(int i=0;i<=200000;i++) check1[i] = check2[i] = -1;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int p = -1;
	long long int ans1 = 1, ans2 = 1;
	long long int S;
	int t;
	for(int i=1;i<=a+2;i+=2)
	{
		if(x[i]!=-1)
		{
			t = (i-p-2)/2;
			if(p==-1&&i>a)
			{
				S = b;
				for(int j=1;j<t;j++) S*=(b-1),S%=MOD;
				ans1 *=S;
				ans1%=MOD;
			}
			else if(p==-1||i>a)
			{
				if(t==0) goto u;
				S = func1(t-1)+(b-1)*func2(t-1);
				S%=MOD;
				ans1*=S;
				ans1%=MOD;
			}
			else
			{
				if(x[p]==x[i])
				{
					if(t==0)
					{
						printf("0");
						return 0;
					}
					
					S = (b-1)*func2(t-1);
					S%=MOD;
					ans1*=S;
					ans1%=MOD;
				}
				else
				{
					if(t==0) goto u;
					S = func1(t-1)+(b-2)*func2(t-1);
					S%=MOD;
					ans1*=S;
					ans1%=MOD;
				}
			}
			u:;
			p = i;
		}
	}
	
	p = 0;
	for(int i=2;i<=a+2;i+=2)
	{
		if(x[i]!=-1)
		{
			t = (i-p-2)/2;
			if(p==0&&i>a)
			{
				S = b;
				for(int j=1;j<t;j++) S*=(b-1),S%=MOD;
				ans2 *=S;
				ans2%=MOD;
			}
			else if(p==0||i>a)
			{
				if(t==0) goto v;
				S = func1(t-1)+(b-1)*func2(t-1);
				S%=MOD;
				ans2*=S;
				ans2%=MOD;
			}
			else
			{
				if(x[p]==x[i])
				{
					if(t==0)
					{
						printf("0");
						return 0;
					}
					
					S = (b-1)*func2(t-1);
					S%=MOD;
					ans2*=S;
					ans2%=MOD;
				}
				else
				{
					if(t==0) goto v;
					S = func1(t-1)+(b-2)*func2(t-1);
					S%=MOD;
					ans2*=S;
					ans2%=MOD;
				}
			}
			v:;
			p = i;
		}
	}
	
	printf("%lld",(ans1*ans2)%MOD);
}