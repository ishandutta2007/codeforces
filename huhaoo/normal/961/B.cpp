#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
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
#define N 100010
int n,k,a[N],w[N],ans,th;
int main()
{
	n=read();
	k=read();
	fr(i,1,n)a[i]=read();
	fr(i,1,n)w[i]=read();
	fr(i,1,k)
		ans=(th+=a[i]*(!w[i]));
	fr(i,2,n-k+1)
	{
		th=th-a[i-1]*(!w[i-1])+a[i+k-1]*(!w[i+k-1]);
		ans=max(ans,th);
	}
	fr(i,1,n)ans+=a[i]*w[i];
	printf("%d\n",ans);
	return 0;
}