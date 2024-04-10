#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 100005
char s[MAXN];
int n,i,j,k,a[26];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n<26)
	{
		puts("-1");
		return 0;
	}
	for(i=1,j=26;i<=26;i++)if(s[i]!='?')
	{
		a[s[i]-'A']++;
		if(a[s[i]-'A']==2)j--;
	}
	for(;i<=n;i++)
	{
		if(j==26)break;
		if(s[i]!='?')
		{
			a[s[i]-'A']++;
			if(a[s[i]-'A']==2)j--;
		}
		if(s[i-26]!='?')
		{
			a[s[i-26]-'A']--;
			if(a[s[i-26]-'A']==1)j++;
		}
	}
	if(j==26)
	{
		for(j=i-26,k=0;j<i;j++)if(s[j]=='?')
		{
			for(;a[k];k++);
			s[j]=k+'A';
			a[k]=1;
		}
		for(i=1;i<=n;i++)if(s[i]=='?')s[i]='A';
		puts(s+1);
	}
	else puts("-1");
	return 0;
}