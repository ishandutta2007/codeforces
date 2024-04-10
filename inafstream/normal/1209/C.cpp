#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

int t,n,ans[200005];
char ss[200005];

bool check(int x)
{
	int i,l1=0,l2=x;
	rep(i,n)
	{
		int t=ss[i]-'0';
		if (t<x)
		{
			if (l1>t) return 0;
			l1=t;ans[i]=1;
		}
		else if (t==x)
		{
			if (l2<=t) l2=t,ans[i]=2; else l1=t,ans[i]=1;
		}
		else
		{
			if (l2>t) return 0;
			l2=t;ans[i]=2;
		}
	}
	
	rep(i,n) putchar(ans[i]+'0');
	puts("");
	return 1;
}

int main()
{
	int i;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf(" %s",ss+1);
		
		for (i=0;i<=9;i++)
		{
			if (check(i)) break;
		}
		
		if (i==10) puts("-");
	}
	
	return 0;
}