#include <bits/stdc++.h>

using namespace std;

long long n,x,y,m,i,j,ans,b;
char c,lst;

int main()
{
	scanf("%I64d%I64d%I64d\n",&n,&x,&y);
	ans=y-min(y,x);
	
	lst='1';
	for (i=1;i<=n;i++)
	{
		scanf("%c",&c); 
		if (c=='0') b=1;
		if (c=='1'&&lst=='0')
		{
			ans+=min(x,y);
		}
		lst=c;
	}
	if (lst=='0') ans+=min(x,y);
	
	if (b==0) puts("0"); else printf("%I64d\n",ans);
	
	return 0;
	
}