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
#define N 200010
long long n,q,a[N],s;
int main()
{
	n=read();
	q=read();
	fr(i,1,n)a[i]=a[i-1]+read();
	while(q--)
	{
		s+=read();
		if(s>=a[n])s=0;
		printf("%I64d\n",n-(upper_bound(a+1,a+n+1,s)-a-1));
	}
	return 0;
}