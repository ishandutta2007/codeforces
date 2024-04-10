/**********************************************************
	File:CF916B.cpp
	Author:huhao
	Email:826538400@qq.com
	Created time:2018-1-29 14:49:45
**********************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long r=0,t=1,c=getchar();
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
#define K 500010
#define P 100
long long n,k,t[P<<3],s;
int main()
{
	n=read();
	k=read();
	int m=0;
	fr(i,0,62)
		if(n&(1ll<<i))
		{
			s++;
			m=i+P;
			t[i+P]=1;
		}
	if(s>k){printf("No\n");return 0;}
	s=k-s;
	int d=0;
	while(s>=t[m])
	{
		s-=t[m];
		t[m-1]+=t[m]<<1;
		t[m]=0;
		m--;
	}
	fr(i,0,m)if(t[i]){t[i]--;d=i;break;}
	printf("Yes\n");
	fd(i,m,0)
		fr(j,1,t[i])
			printf("%d ",i-P);
	d--;
	if(!s){printf("%d\n",d-P+1);return 0;}
	while(s)
	{
		printf("%d ",d-P);
		s--;
		if(!s)printf("%d\n",d-P);
		d--;
	}
	return 0;
}