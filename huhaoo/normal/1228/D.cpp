/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-09-29 22:33:56
****************************************************************/
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
#include<vector>
const int N=100010;
int n,m,c[N],C[N];
vector<int> e[N];
int main()
{
	n=read();
	m=read();
	fr(i,1,m)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	c[1]=1;
	for(auto j:e[1])
	{
		c[j]=2;
		for(auto k:e[j])
			if(c[k]&&k!=1)
			{
				if(c[k]==2)
					c[j]=3;
			}
	}
	fr(i,1,n)
		if(!c[i])
			c[i]=1;
	fr(i,1,n)
	{
		C[c[i]]++;
		for(auto j:e[i])
			if(c[i]==c[j])
			{
				printf("-1\n");
				return 0;
			}
	}
	if((long long)C[1]*C[2]+(long long)C[1]*C[3]+(long long)C[2]*C[3]==m&&C[2]&&C[3])
	{
		fr(i,1,n)
			printf("%d%c",c[i],i==n?'\n':' ');
	}
	else
		printf("-1\n");
	return 0;
}