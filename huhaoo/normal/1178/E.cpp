/***************************************************************
	File name: 1178E.cpp
	Author: huhao
	Create time: Wed 16 Oct 2019 08:30:55 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=1000010;
int n,l1,l2;
char s[N],s1[N],s2[N];
void add(int l,int r)
{
	s1[++l1]=s[l];
	if(l!=r)
		s2[++l2]=s[r];
}
void dfs(int l,int r)
{
	if(l>r)
		return;
	if(s[l]==s[r])
	{
		add(l,r);
		dfs(l+1,r-1);
		return;
	}
	if(s[l+1]==s[r])
	{
		add(l+1,r);
		dfs(l+2,r-1);
		return;
	}
	if(s[l]==s[r-1])
	{
		add(l,r-1);
		dfs(l+1,r-2);
		return;
	}
	if(s[l+1]==s[r-1])
	{
		add(l+1,r-1);
		dfs(l+2,r-2);
		return;
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	dfs(1,n);
	reverse(s2+1,s2+l2+1);
	printf("%s%s\n",s1+1,s2+1);
	return 0;
}