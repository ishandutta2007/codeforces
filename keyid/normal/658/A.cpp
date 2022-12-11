#include <bits/stdc++.h>
using namespace std;

const int MAXN=55;

int p[MAXN],t[MAXN];

int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);
	int now=0,sum1=0,sum2=0;
	for (int i=1;i<=n;i++)
	{
		now+=t[i];
		sum1+=max(0,p[i]-c*now);
	}
	now=0;
	for (int i=n;i>=1;i--)
	{
		now+=t[i];
		sum2+=max(0,p[i]-c*now);
	}
	if (sum1>sum2) printf("Limak");
	else if (sum1<sum2) printf("Radewoosh");
	else printf("Tie");
	return 0;
}