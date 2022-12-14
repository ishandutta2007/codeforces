#include <stdio.h>
#include <map>
#include <vector>
#define MOD 998244353
int a;
std::vector< std::vector<long long int> > V2;
void power(std::vector< std::vector<long long int> > &V, int t)
{
	if(t==1) return;
	
	if(t%2==0)
	{
		power(V,t/2);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) V2[i][j] = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				for(int k=1;k<=a;k++)
				{
					V2[i][j] += V[i][k]*V[k][j];
					V2[i][j] %= (MOD-1);
				}
			}
		}
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) V[i][j] = V2[i][j];
	}
	else
	{
		std::vector< std::vector<long long int> > temp;
		temp.resize(a+1);
		for(int i=0;i<=a;i++) temp[i].resize(a+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) temp[i][j] = V[i][j];
		
		power(V,t/2);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) V2[i][j] = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				for(int k=1;k<=a;k++)
				{
					V2[i][j] += V[i][k]*V[k][j];
					V2[i][j] %= (MOD-1);
				}
			}
		}
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) V[i][j] = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				for(int k=1;k<=a;k++)
				{
					V[i][j] += V2[i][k]*temp[k][j];
					V[i][j] %= (MOD-1);
				}
			}
		}
	}
}

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
std::map<long long int, long long int> M,M2;
std::vector< std::vector<long long int> > V;

int main()
{
	scanf("%d",&a);
	V.resize(a+1);
	for(int i=0;i<=a;i++) V[i].resize(a+1);
	V2.resize(a+1);
	for(int i=0;i<=a;i++) V2[i].resize(a+1);
	
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V[a][a-i+1] = b;
	}
	for(int i=1;i<a;i++) V[i][i+1] = 1;
	int b,c;
	scanf("%d%d",&b,&c);
	power(V,b-1);
	/*for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) printf("%d ",V[i][j]);
		printf("\n");
	}*/
	
	long long int d = -1, ans = -1;
	for(int i=1;i<40000;i++)
	{
		long long int t = power(3,40000*i);
		M[t] = i;
	}
	for(int i=0;i<40000;i++)
	{
		long long int t = power(3,i);
		t *= c, t %= MOD;
		if(M.find(t)!=M.end())
		{
			d = 40000*M[t]-i;
			d %= (MOD-1);
			break;
		}
	}
	
	for(int i=1;i<40000;i++)
	{
		long long int t = (40000*V[1][a]%(MOD-1))*i;
		t %= (MOD-1);
		M2[t] = i;
	}
	for(int i=0;i<40000;i++)
	{
		long long int t = V[1][a]*i + d;
		t %= (MOD-1);
		if(M2.find(t)!=M2.end())
		{
			ans = 40000*M2[t]-i;
			ans %= (MOD-1);
			break;
		}
	}
	
	if(ans!=-1) printf("%lld",power(3,ans));
	else printf("-1");
}