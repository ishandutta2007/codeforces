#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

const int MAXN=100005;

bitset <MAXN> dp[27];
int cnt,d[MAXN];

void output(int i,int n)
{
	if (i==0) return;
	for (int j=0;j<cnt&&d[j]<=n;j++)
		if (dp[i-1].test(n-d[j]))
		{
			output(i-1,n-d[j]);
			for (int k=0;k<j+2;k++)
				putchar('a'+i-1);
			break;
		}
}

int main()
{
	int n;
	scanf("%d",&n);
	if (n==0)
	{
		printf("a");
		return 0;
	}
	for (int i=2;i*(i-1)/2<=100000;i++)
		d[cnt++]=i*(i-1)/2;
	dp[0].set(0);
	for (int i=1;i<=26;i++)
	{
		for (int j=0;j<cnt;j++)
			dp[i]=dp[i]|(dp[i-1]<<d[j]);
		if (dp[i].test(n))
		{
			output(i,n);
			break;
		}
	}
	return 0;
}