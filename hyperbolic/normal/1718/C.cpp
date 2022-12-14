#include <stdio.h>
#include <map>
#include <set>
#include <vector>

std::multiset<long long int> S;
int x[200010];
std::vector<int> V,prime;
int check[200010];

long long int M[21][200010];
int main()
{
	for(int i=2;i<=200000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=200000;j+=i) check[j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		S.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=0;j<10;j++) for(int i=0;i<=a;i++) M[j][i] = 0;
		for(int i=0;i<a;i++) scanf("%d",&x[i]);
		
		for(int i=0;i<prime.size();i++)
		{
			if(prime[i]>a) break;
			if(a%prime[i]==0) V.push_back(prime[i]);
		}
		
		for(int j=0;j<V.size();j++)
		{
			int t = a/V[j];
			for(int i=0;i<a;i++) M[j][i%t] += x[i];
			for(int i=0;i<t;i++) S.insert(M[j][i] * t);
		}
		std::multiset<long long int> ::iterator it;
		
		it = S.end();
		it--;
		printf("%lld\n",(*it));
		
		while(b--)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			c--;
			for(int j=0;j<V.size();j++)
			{
				int t = a/V[j];
				it = S.find(M[j][c%t] * t);
				S.erase(it);
				M[j][c%t] -= x[c];
			}
			x[c] = d;
			for(int j=0;j<V.size();j++)
			{
				int t = a/V[j];
				M[j][c%t] += x[c];
				S.insert(M[j][c%t] * t);
			}
			it = S.end();
			it--;
			printf("%lld\n",(*it));
		}
	}
}