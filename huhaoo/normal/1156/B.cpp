/**************************************************************
	File name: 1156B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/5/1 11:05:48
**************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
char s[110];
int n;
int cmp(char a,char b)
{
	a-='a';
	b-='a';
	if(a%2==b%2)
		return a<b;
	else
		return a%2<b%2;
}
int cmp2(char a,char b)
{
	a-='a';
	b-='a';
	if(a%2==b%2)
		return a<b;
	else
		return a%2>b%2;
}
int main()
{
	fr(T,1,read())
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		sort(s+1,s+n+1,cmp);
		int flag=1;
		fr(i,1,n-1)
			if(abs(s[i]-s[i+1])==1)
				flag=0;
		if(flag)
		{
			printf("%s\n",s+1);
		}
		else
		{
//			printf("%s\n",s+1);
			sort(s+1,s+n+1,cmp2);
			flag=1;
			fr(i,1,n-1)
				if(abs(s[i]-s[i+1])==1)
					flag=0;
			if(!flag)
				printf("No answer\n");
			else
			{
				printf("%s\n",s+1);
			}
		}
	}
	return 0;
}