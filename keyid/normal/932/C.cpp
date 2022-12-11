#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

void output(int x,int a,int y,int b)
{
	int now=0;
	for (int i=1;i<=x;i++)
	{
		for (int j=2;j<=a;j++)
			printf("%d ",now+j);
		printf("%d ",now+1);
		now+=a;
	}
	for (int i=1;i<=y;i++)
	{
		for (int j=2;j<=b;j++)
			printf("%d ",now+j);
		printf("%d ",now+1);
		now+=b;
	}
}

int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for (int i=0;i*b<=n;i++)
		if ((n-i*b)%a==0)
		{
			output((n-i*b)/a,a,i,b);
			return 0;
		}
	printf("-1");
	return 0;
}