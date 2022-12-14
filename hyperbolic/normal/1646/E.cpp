#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> prime;
int check[1000010];
std::vector<int> V[1000010];

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

std::vector<int> V2;
int save[110];
int check2[20000010];
int main()
{
	for(int i=2;i<=1000000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=1000000;j+=i) check[j] = 1;
		}
	}
	
	for(int i=0;i<prime.size();i++) for(int j=prime[i];j<=1000000;j+=prime[i]) V[j].push_back(prime[i]);
	
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=20;i++)
	{
		save[i] = save[i-1];
		for(int j=1;j<=b;j++)
		{
			if(check2[i*j]==0) save[i]++, check2[i*j] = 1;
		}
	}
	
	
	long long int ans = 0;
	for(int i=2;i<=a;i++)
	{
		long long int c = i;
		int g = 0;
		for(int j=0;j<V[i].size();j++)
		{
			int d = 0;
			while(c%V[i][j]==0) d++, c/=V[i][j];
			g = gcd(d,g);
		}
		
		if(g==1)
		{
			int count = 0;
			c = 1;
			V2.clear();
			for(int j=1;;j++)
			{
				c*=i;
				count++;
				if(c>a) break;
			}
			count--;
			ans += save[count];
		}
	}
	printf("%lld\n",ans+1);
}