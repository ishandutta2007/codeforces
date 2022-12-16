#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=200005;
const long long inf=1000000000000000000ll;
int n,q,i,j,u,t,g,s,b,p[500005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&p[i]);
		g=s=b=0;
		for(i=1;i<=n;)
		{
			for(j=i;j<=n&&p[i]==p[j];++j);
			g=j-i;
			i=j;
			break;
		}
		for(;i<=n;)
		{
			for(j=i;j<=n&&p[i]==p[j];++j);
			s+=j-i;
			i=j;
			if(s>g)
				break;
		}
		for(;i<=n;)
		{
			for(j=i;j<=n&&p[i]==p[j];++j);
			if(j-1>n/2)
				break;
			b+=j-i;
			i=j;
		}
		if(g<b)
			printf("%d %d %d\n",g,s,b);
		else
			puts("0 0 0");
	}
}