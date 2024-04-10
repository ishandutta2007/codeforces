#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
std::pair<int,int> P[300010];
bool cmp(std::pair<int,int> a, std::pair<int,int> b)
{
	return a.second<b.second;
}

int a,b;
long long int sum = 0;
std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
long long int insert(int k)
{
	sum += k;
	Q.push(k);
	if(Q.size()==b+1)
	{
		sum -= Q.top();
		Q.pop();
	}
	return sum;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i]=std::make_pair(c,d);
	}
	std::sort(P+1,P+a+1,cmp);
	long long int ans = 0;
	for(int i=a;i>=1;i--)
	{
		long long int S = insert(P[i].first);
		ans = ans>S*P[i].second?ans:S*P[i].second;
	}
	printf("%lld",ans);
}