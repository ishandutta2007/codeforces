/**************************************************************
	File name: 1137B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 3/8/2019, 5:35:07 PM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
#define N 500010
int n,m,c1[N],c2[N],nex[N],l;
char s[N],t[N];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	int k=0;
	fr(j,2,m)
	{
		while(k&&t[j]!=t[k+1])
			k=nex[k];
		if(t[j]==t[k+1])
			k++;
		nex[j]=k;
	}
	fr(i,1,n)
		c1[s[i]-48]++;
	fr(i,1,m)
		c1[t[i]-48]--;
	if(c1[1]>=0&&c1[0]>=0)
	{
		printf("%s",t+1);
		fr(i,nex[m]+1,m)
			c2[t[i]-48]++;
		while(c1[1]>=c2[1]&&c1[0]>=c2[0])
		{
			printf("%s",t+nex[m]+1);
			c1[1]-=c2[1];
			c1[0]-=c2[0];
		}
		fr(i,1,c1[1])
			putchar(49);
		fr(i,1,c1[0])
			putchar(48);
	}
	else
	{
		printf("%s",s+1);
		return 0;
	}
	return 0;
}