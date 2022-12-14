#include <stdio.h>
#include <vector>

std::vector< std::vector<int> > V,V2;
std::vector<int> temp0, temp1;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		temp1.push_back(b);
	}
	V.push_back(temp1);
	
	long long int ans1 = 0, ans2 = 0;
	for(int k=30;k>=0;k--)
	{
		int count0 = 0;
		int count1 = 0;
		long long int sum01 = 0;
		long long int sum10 = 0;
		for(int i=0;i<V.size();i++)
		{
			count0 = 0;
			count1 = 0;
			for(int j=0;j<V[i].size();j++)
			{
				int t = V[i][j];
				if((t&(1<<k))==0) sum10 += count1, count0++;
				else sum01 += count0, count1++;
			}
		}
		
		if(sum10<=sum01) ans1 += sum10;
		else
		{
			ans1 += sum01;
			ans2 += (1<<k);
		}
		
		V2.clear();
		for(int i=0;i<V.size();i++)
		{
			temp0.clear();
			temp1.clear();
			for(int j=0;j<V[i].size();j++)
			{
				int t = V[i][j];
				if((t&(1<<k))==0) temp0.push_back(V[i][j]);
				else temp1.push_back(V[i][j]);
			}
			if(temp0.size()>0) V2.push_back(temp0);
			if(temp1.size()>0) V2.push_back(temp1);
		}
		V = V2;
	}
	printf("%lld %lld",ans1,ans2);
}