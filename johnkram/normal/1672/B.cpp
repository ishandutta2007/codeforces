#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,i,j;
char c[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		n=strlen(c+1);
		if(c[n]!='B')
		{
			puts("NO");
			continue;
		}
		for(i=1,j=0;i<=n;i++)if(c[i]=='A')j++;
		else if(j)j--;
		else break;
		if(i>n)puts("YES");
		else puts("NO");
	}
	return 0;
}