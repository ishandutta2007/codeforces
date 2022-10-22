#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
int t,n,m,i,j,s[26];
char c[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&m,c);
		memset(s,0,sizeof(s));
		for(i=0;i<n;i++)s[c[i]-'a']++;
		for(i=0;i<m;i++)
		{
			for(j=0;s[j]&&j<n/m;j++)s[j]--;
			putchar(j+'a');
		}
		putchar('\n');
	}
	return 0;
}