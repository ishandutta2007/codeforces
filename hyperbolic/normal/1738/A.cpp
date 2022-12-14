#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V1,V2;
int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++)
		{
			if(x[i]==0) V1.push_back(y[i]);
			else V2.push_back(y[i]);
		}
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		
		if(V1.size()==0)
		{
			long long int sum = 0;
			for(int i=0;i<V2.size();i++) sum += V2[i];
			printf("%lld\n",sum);
			continue;
		}
		if(V2.size()==0)
		{
			long long int sum = 0;
			for(int i=0;i<V1.size();i++) sum += V1[i];
			printf("%lld\n",sum);
			continue;
		}
		
		long long int sum1 = V1[0], sum2 = V2[0];
		int s,t;
		s = V1.size()-1, t = V2.size()-1;
		while(s>=1 && t>=0)
		{
			sum1 += 2*V1[s];
			sum1 += 2*V2[t];
			s--;
			t--;
		}
		if(s>=1)
		{
			while(s>=1) sum1 += V1[s], s--;
		}
		if(t>=0)
		{
			sum1 += 2*V2[t];
			t--;
			while(t>=0) sum1 += V2[t], t--;
		}
		
		s = V1.size()-1, t = V2.size()-1;
		while(s>=0 && t>=1)
		{
			sum2 += 2*V1[s];
			sum2 += 2*V2[t];
			s--;
			t--;
		}
		if(t>=1)
		{
			while(t>=1) sum2 += V2[t], t--;
		}
		if(s>=0)
		{
			sum2 += 2*V1[s];
			s--;
			while(s>=0) sum2 += V1[s], s--;
		}
		
		printf("%lld\n",sum1>sum2?sum1:sum2);
	}
}