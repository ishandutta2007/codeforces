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
#include<map>
long long n,a,b,ans;
map<long long,long long>sum;
map<long long,long long>sum2;
int main()
{
	n=read();
	a=read();
	read();
	fr(i,1,n)
	{
		read();
		long long x=read(),y=read();
		long long k=a*x-y,kk=(x<<30)+y;
		ans+=sum[k]-sum2[kk];
		sum[k]++;
		sum2[kk]++;
	}
	printf("%I64d\n",ans+ans);
	return 0;
}
/*

*/