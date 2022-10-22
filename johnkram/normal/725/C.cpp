#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define MAXN 200005
char s[30],ans[2][30];
int i,j,k,l,a[300];
int main()
{
	scanf("%s",s+1);
	for(i=1;i<28;i++)if(a[s[i]])break;
	else a[s[i]]=i;
	if(a[s[i]]+1==i)
	{
		puts("Impossible");
		return 0;
	}
	ans[0][i-a[s[i]]-1>>1]=s[i];
	for(j=i-a[s[i]]-3>>1,k=i-1;~j;j--,k--)ans[0][j]=s[k];
	for(j=0;k>a[s[i]];j++,k--)ans[1][j]=s[k];
	for(j=i-a[s[i]]-1>>1,l=0,k=i+1;k<28;k++)
	{
		if(l)j--;
		else j++;
		if(j==13)
		{
			j=12;
			l=1;
		}
		ans[l][j]=s[k];
	}
	for(k=1;k<a[s[i]];k++)
	{
		if(l)j--;
		else j++;
		if(j==13)
		{
			j=12;
			l=1;
		}
		ans[l][j]=s[k];
	}
	puts(ans[0]);
	puts(ans[1]);
	return 0;
}