#include<bits/stdc++.h>
using namespace std;
int n,m,i,j;
char s[200005],t[200005];
int main()
{
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	for(i=1;i<=n;i++)if(s[i]=='*')break;
	if(i>n)
	{
		if(n!=m)puts("NO");
		else
		{
			for(i=1;i<=n;i++)if(s[i]!=t[i])break;
			if(i>n)puts("YES");
			else puts("NO");
		}
		return 0;
	}
	if(n-1>m)
	{
		puts("NO");
		return 0;
	}
	for(j=1;j<i;j++)if(s[j]!=t[j])break;
	if(j<i)
	{
		puts("NO");
		return 0;
	}
	for(j=0;j<n-i;j++)if(s[n-j]!=t[m-j])break;
	if(j<n-i)puts("NO");
	else puts("YES");
	return 0;
}