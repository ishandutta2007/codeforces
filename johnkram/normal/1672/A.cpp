#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int t,n,m,i,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			m+=a[i]-1;
		}
		if(m&1)puts("errorgorn");
		else puts("maomao90");
	}
	return 0;
}