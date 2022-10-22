#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,i,j,a[MAXN],b[MAXN],s[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		for(i=1;i<=n;i++)scanf("%d",b+i);
		fill(s+1,s+n+1,0);
		for(i=j=1;i<=n;i++)if(j<=n&&b[i]==a[j])j++;
		else if(i>1&&b[i-1]==b[i]&&s[b[i]])s[b[i]]--;
		else
		{
			for(;j<=n&&b[i]!=a[j];j++)s[a[j]]++;
			if(j>n)break;
			else j++;
		}
		if(i<=n)puts("NO");
		else puts("YES");
	}
	return 0;
}