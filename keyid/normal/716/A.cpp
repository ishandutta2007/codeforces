#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

int t[MAXN];

int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	t[0]=-c;
	for (int i=n;i>=1;i--)
		if (t[i]-t[i-1]>c)
		{
			printf("%d",n-i+1);
			break;
		}
	return 0;
}