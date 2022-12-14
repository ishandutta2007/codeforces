#include <stdio.h>
#include <vector>
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
	return (a/gcd(a,b))*b;
}

char x[210],z[210];
int y[210],check[210];
std::vector<int> V;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		long long int ans = 1;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				V.clear();
				int p = i;
				V.push_back(p);
				check[p] = 1;
				while(y[p]!=i)
				{
					p = y[p];
					V.push_back(p);
					check[p] = 1;
				}
				
				for(int j=0;j<V.size();j++) z[V[j]] = x[V[j]];
				
				int C = 0;
				while(1)
				{
					C++;
					char temp = z[V[0]];
					for(int j=1;j<V.size();j++) z[V[j-1]] = z[V[j]];
					z[V.back()] = temp;
					
					int control = 0;
					for(int j=0;j<V.size();j++) if(z[V[j]]!=x[V[j]]) control = 1;
					if(control==0)
					{
						ans = lcm(ans,C);
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
}