#include <stdio.h>
#include <vector>

long long int sum[100010];
std::vector<int> V[100010];
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

std::vector< std::pair<int,int> > ans;
int main()
{
	for(int i=1;i<=100000;i++) for(int j=i;j<=100000;j+=i) V[j].push_back(i);
	for(int i=1;i<=100000;i++) sum[i] = (sum[i-1]+i-V[i].size()+1);
	
	int a,b;
	scanf("%d%d",&a,&b);
	if(b<a-1)
	{
		printf("Impossible");
		return 0;
	}
	
	for(int i=2;i<=a;i++) ans.push_back({1,i});
	b -= (a-1);
	for(int i=2;i<=a;i++)
	{
		for(int j=2;j<=i;j++)
		{
			if(b==0) goto u;
			if(gcd(i,j)==1)
			{
				ans.push_back({i,j});
				b--;
				if(b==0) goto u;
			}
		}
	}
	printf("Impossible");
	return 0;
	u:;
	
	printf("Possible\n");
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}