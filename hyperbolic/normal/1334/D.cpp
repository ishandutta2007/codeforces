#include <stdio.h>
#include <vector>

std::vector<int> V;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		long long int b,c;
		scanf("%d%lld%lld",&a,&b,&c);
		
		long long int sum = 0;
		for(int p=1;p<a;p++)
		{
			if(sum>c) break;
			if(sum+2*(a-1-p)>=b)
			{
				for(int i=p+1;i<=a-1;i++)
				{
					sum++;
					if(b<=sum&&sum<=c) V.push_back(p);
					sum++;
					if(b<=sum&&sum<=c) V.push_back(i);
				}
			}
			else sum += 2*(a-1-p);
			
			sum++;
			if(b<=sum&&sum<=c) V.push_back(p);
			sum++;
			if(b<=sum&&sum<=c) V.push_back(a);
		}
		if(c==(long long int)a*(a-1)+1) V.push_back(1);
		
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
		printf("\n");
	}
}