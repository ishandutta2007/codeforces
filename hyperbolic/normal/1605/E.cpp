#include <stdio.h>
#include <vector>
#include <map>
#define MIN -(long long int)1e18

std::vector<int> divisor[300010];
long long int weight[300010],init[300010];
int x[300010],y[300010];
std::map<long long int,long long int> M1,M2,M3,M4;

long long int abs(long long int k)
{
	return k>0?k:-k;
}

int main()
{
	//printf("%lld??\n",MIN);
	int a;
	scanf("%d",&a);
	
	for(int i=2;i<=a;i++) for(int j=2*i;j<=a;j+=i) divisor[j].push_back(i);
	
	for(int i=2;i<=a;i++)
	{
		weight[i] = 1;
		for(int j=0;j<divisor[i].size();j++) weight[i] -= weight[divisor[i][j]];
	}
	
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	for(int i=2;i<=a;i++)
	{
		init[i] = y[i] - x[i];
		for(int j=0;j<divisor[i].size();j++) init[i] -= init[divisor[i][j]];
	}
	
	for(int i=2;i<=a;i++) if(weight[i]<0) weight[i] *= (-1), init[i] *= (-1);
	
	long long int C = 0;
	for(int i=2;i<=a;i++)
	{
		if(weight[i]==0) C += abs(init[i]);
		else
		{
			if(init[i]>0)
			{
				long long int t = (-init[i]/weight[i]);
				M1[MIN] -= init[i];
				M1[t] += 2*init[i];
				M2[MIN] -= weight[i];
				M2[t] += 2*weight[i];
			}
			else
			{
				long long int t = (-init[i]/weight[i]);
				M1[MIN] -= init[i];
				M1[t+1] += 2*init[i];
				M2[MIN] -= weight[i];
				M2[t+1] += 2*weight[i];
			}
		}
	}
	
	long long int S = 0;
	for(std::map<long long int,long long int> ::iterator it = M1.begin();it!=M1.end();it++)
	{
		S += (it->second);
		M3[it->first] = S;
	}
	
	S = 0;
	for(std::map<long long int,long long int> ::iterator it = M2.begin();it!=M2.end();it++)
	{
		S += (it->second);
		M4[it->first] = S;
	}

	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		long long int c = x[1]-d;
		std::map<long long int,long long int> ::iterator it = M3.lower_bound(c+1);
		if(it!=M3.begin()) it--;
		//printf("%d %d %lld??\n",c,it->first,it->second);
		
		printf("%lld\n",(it->second) + (long long int)c * (M4[it->first]) + C + abs(c));
	}
}