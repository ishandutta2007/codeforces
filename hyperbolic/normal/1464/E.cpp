#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 998244353
#define SIZE 512

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

int check[100010];
std::vector<int> V[100010];
int getGrundy(int k)
{
	if(check[k]!=-1) return check[k];
	
	std::vector<int> save;
	for(int i=0;i<V[k].size();i++) save.push_back(getGrundy(V[k][i]));
	
	std::sort(save.begin(),save.end());
	save.erase(std::unique(save.begin(),save.end()),save.end());
	for(int i=0;i<save.size();i++)
	{
		if(save[i]!=i) return check[k] = i;
	}
	return check[k] = save.size();
}

long long int ans[2010];
long long int M[2010][2010],y[2010];
void GaussJordan()
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(M[i][j]!=0)
			{
				long long int I = inv(M[i][j]);
				for(int k=0;k<SIZE;k++)
				{
					if(k==i) continue;
					long long int C = (M[k][j]*I)%MOD;
					for(int l=0;l<SIZE;l++)
					{
						M[k][l] -= (C*M[i][l])%MOD;
						M[k][l] += MOD;
						M[k][l] %= MOD;
					}
					y[k] -= (C*y[i])%MOD;
					y[k] += MOD;
					y[k] %= MOD;
				}
				goto u;
			}
		}
		u:;
	}
	
	for(int i=SIZE-1;i>=0;i--)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(M[i][j]!=0)
			{
				ans[j] = (y[i]*inv(M[i][j]))%MOD;
				for(int k=0;k<SIZE;k++)
				{
					if(i==k) continue;
					y[k] -= (ans[j] * inv(M[k][j]))%MOD;
					y[k] += MOD;
					y[k] %= MOD;
					M[k][j] = 0;
				}
			}
		}
	}
}

int count[2010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
	}
	for(int i=1;i<=a;i++) check[i] = -1;
	for(int i=1;i<=a;i++) count[getGrundy(i)]++;
	
	
	for(int i=0;i<SIZE;i++)
	{
		M[i][i] = (a+1);
		for(int j=0;j<SIZE;j++) M[i][i^j] += (MOD-count[j]);
		for(int j=0;j<SIZE;j++) M[i][j]%=MOD;
		if(i>0) y[i] = 1;
	}
	GaussJordan();
	
	printf("%lld",ans[0]);
}