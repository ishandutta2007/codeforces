#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 500005
int t,n,i,j,s,f[MAXN];
bool b[MAXN];
char c[MAXN];
int main()
{
	scanf("%d",&t);
	for(i=2;i<=86;i++)
	{
		fill(b,b+i,0);
		for(j=0;j+2<=i;j++)b[f[j]^f[i-2-j]]=1;
		for(j=0;b[j];j++);
		f[i]=j;
	}
	for(i=87;i<MAXN;i++)f[i]=f[i-34];
	while(t--)
	{
		scanf("%d%s",&n,c+1);
		for(i=1,j=0;i<=n;i++)if(c[i]=='R')j++;
		else j--;
		if(j)
		{
			if(j>0)puts("Alice");
			else puts("Bob");
			continue;
		}
		for(i=1,s=0;i<n;i++)if(c[i]!=c[i+1])
		{
			for(j=i+1;j<n&&c[j]!=c[j+1];j++);
			s^=f[j-i+1];
			i=j;
		}
		if(s)puts("Alice");
		else puts("Bob");
	}
	return 0;
}