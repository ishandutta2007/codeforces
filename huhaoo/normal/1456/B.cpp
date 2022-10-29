/***************************************************************
	File name: B.cpp
	Author: huhao
	Create time: Sun 29 Nov 2020 03:14:21 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
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
const int N=110;
int n,a[N],s[N],ans;
int main()
{
	n=read();
	if(n>100){ printf("1\n"); return 0; }
	fr(i,1,n) s[i]=s[i-1]^(a[i]=read());
	ans=1000;
	fr(i,0,n-1) fr(j,i+1,n) fr(k,j+1,n) if((s[k]^s[j])<(s[j]^s[i])) ans=std::min(ans,k-i-2);
	printf("%d\n",ans>n?-1:ans);
	return 0;
}