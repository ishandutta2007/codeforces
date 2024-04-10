#include <stdio.h>
#include <vector>
#include <algorithm>

long long int abs(long long int k)
{
	return k>0?k:-k;
}

std::vector<int> V[5];
long long int sum[10];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	long long int sum1=0, sum2=0, sum3=0;
	for(int i=1;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		V[1].push_back(d);
	}
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		V[2].push_back(d);
	}
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		V[3].push_back(d);
	}
	for(int i=1;i<=3;i++) std::sort(V[i].begin(),V[i].end());
	long long int ans = 0;
	for(int j=1;j<=3;j++) for(int i=0;i<V[j].size();i++) ans += V[j][i];
	long long int s = V[1][0]+V[2][0];
	long long int t = V[1][0]+V[3][0];
	s = s<t?s:t;
	t = V[2][0]+V[3][0];
	s = s<t?s:t;
	ans = ans-2*s;
	
	for(int j=1;j<=3;j++) for(int i=0;i<V[j].size();i++) sum[j] += V[j][i];
	ans = ans>sum[1]+sum[2]-sum[3]?ans:sum[1]+sum[2]-sum[3];
	ans = ans>sum[1]+sum[3]-sum[2]?ans:sum[1]+sum[3]-sum[2];
	ans = ans>sum[3]+sum[2]-sum[1]?ans:sum[3]+sum[2]-sum[1];
	printf("%lld",ans);
}