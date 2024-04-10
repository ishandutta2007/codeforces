#include<bits/stdc++.h>
using namespace std;
int n,m,e,i,j,l,r,s[200005],a[200005],t;
char c[200005],d[200005];
int main()
{
	scanf("%d%d%s",&n,&m,c+1);
	for(i=1;i<=n;i++)if(c[i]=='(')s[++t]=i;
	else a[s[t--]]=i;
	for(l=1,r=n;e<m;)
	{
		for(i=l;i<=r;i=a[i]+1)if(e+a[i]+1-i<=m)for(j=i;j<=a[i];j++)d[++e]=c[j];
		else break;
		l=i+1;
		r=a[i]-1;
	}
	puts(d+1);
	return 0;
}