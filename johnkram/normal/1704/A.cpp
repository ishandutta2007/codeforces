#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
int t,n,m,i;
bool d[2];
char a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s%s",&n,&m,a+1,b+1);
		for(i=2;i<=m;i++)if(a[n-m+i]!=b[i])break;
		if(i<=m)
		{
			puts("NO");
			continue;
		}
		memset(d,0,sizeof(d));
		for(i=1;i<=n-m+1;i++)d[a[i]^'0']=1;
		if(d[b[1]^'0'])puts("YES");
		else puts("NO");
	}
	return 0;
}