/***************************************************************
	File name: 1244F.cpp
	Author: huhao
	Create time: Sun 13 Oct 2019 05:51:47 PM CST
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
const int N=2000010;
int n,k,L,R;
char s[N],c[N];
inline int pre(int k)
{
	k--;
	return k==0?k+n:k;
}
inline int nex(int k)
{
	k++;
	return k>n?k-n:k;
}
int main()
{
	n=read();
	k=read();
	scanf("%s",s+1);
	fr(i,1,n)
		if(s[i]=='W')
			s[i]=0;
		else
			s[i]=1;
	fr(i,1,n)
		if(s[i]==s[nex(i)])
		{
			L=i;
			R=nex(i);
			while(s[nex(R)]==s[L]&&R!=L)
				R=nex(R);
			break;
		}
	if(!L)
	{
		fr(i,1,n)
			putchar((s[i]^(k&1))==0?'W':'B');
		putchar(10);
		return 0;
	}
	c[L]=s[L];
	for(int i=nex(L);i!=L;)
		if(s[i]==s[pre(i)]||s[i]==s[nex(i)])
		{
			c[i]=s[i];
			i=nex(i);
		}
		else
		{
			int j=i,l=1;
			while(s[nex(j)]!=s[nex(nex(j))])
			{
				j=nex(j);
				l++;
			}
			int s0=s[pre(i)],s1=s[nex(j)];
			j=i;
			fr(o,1,l)
			{
				int d1=o,d2=l-o+1;
				if(min(d1,d2)<=k)
				{
					if(d1<=d2)
						c[j]=s0;
					else
						c[j]=s1;
				}
				else
					c[j]=s[j]^(k&1);
				j=nex(j);
			}
			i=j;
		}
	fr(i,1,n)
		putchar(c[i]==0?'W':'B');
	putchar(10);
	return 0;
}