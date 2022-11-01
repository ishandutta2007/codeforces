#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

char s[1000005];
int n,m,i,j,ans,dep;

int main()
{
	scanf("%d",&n);
	scanf(" %s",s);
	for (i=0;s[i];i++)
	{
		dep+=(s[i]=='('?1:-1);
		if (s[i]==')'&&dep<0) ans+=2;
	}
	
	if (dep) puts("-1"); else printf("%d\n",ans);
	
	return 0;
}