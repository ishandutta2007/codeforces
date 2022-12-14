#include <stdio.h>
#include <algorithm>
#include <vector>

int x[100010],y[100010];
int check[2010];
std::vector< std::pair<int,int> > z;
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	scanf("%d",&c);
	
	for(int i=0;i<=b;i++) check[i] = 123456789;
	for(int i=1;i<=b;i++)
	{
		int sum = 0;
		for(int j=i;j<=b;j++)
		{
			sum += y[j];
			check[j-i+1] = check[j-i+1] < sum? check[j-i+1] : sum;
		}
	}
	z.push_back(std::make_pair(check[b],b));
	int C = check[b];
	for(int i=b-1;i>=1;i--)
	{
		C = C<check[i]?C:check[i];
		z.push_back(std::make_pair(C,i));
	}
	std::sort(z.begin(),z.end());
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int sum = 0;
		for(int j=i;j<=a;j++)
		{
			sum += x[j];
			
			int d = c/sum;
			std::vector< std::pair<int,int> > ::iterator it = std::lower_bound(z.begin(),z.end(),std::make_pair(d+1,0));
			if(it==z.begin()) continue;
			it--;
			if(it==z.end()) continue;
			int value = (it->second);
			ans = ans>value*(j-i+1)?ans:value*(j-i+1);
		}
	}
	printf("%d",ans);
}