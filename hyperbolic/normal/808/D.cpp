#include <stdio.h>
#include <set>

int x[100010];
long long int y[100010],z[100010];
std::set<long long int> S;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = y[i-1]+x[i];
	for(int i=a;i>=1;i--) z[i] = z[i+1]+x[i];
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	if(sum%2==1)
	{
		printf("NO");
		return 0;
	}
	sum/=2;
	
	S.clear();
	for(int i=1;i<=a;i++)
	{
		S.insert(x[i]);
		if(y[i]>=sum && S.find(y[i]-sum)!=S.end())
		{
			printf("YES");
			return 0;
		}
	}
	
	S.clear();
	for(int i=a;i>=1;i--)
	{
		S.insert(x[i]);
		if(z[i]>=sum && S.find(z[i]-sum)!=S.end())
		{
			printf("YES");
			return 0;
		}
	}
	
	printf("NO");
}