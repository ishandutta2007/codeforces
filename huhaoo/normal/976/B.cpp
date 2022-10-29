#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(long long i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long t=1,r=0,c=getchar();
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
long long n,m,k;
int main()
{
	n=read();
	m=read();
	k=read()+1;
	if(k<=n)printf("%I64d 1\n",k);
	else
	{
		long long x,y;
		x=n-(k-n-1)/(m-1);
		if(x&1)y=m-(k-n-1)%(m-1);
		else y=(k-n-1)%(m-1)+2;
		printf("%I64d %I64d\n",x,y);
	}
	return 0;
}