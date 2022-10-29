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
#define N 1000010
int n,a[N],m[N];
long long ans;
int main()
{
	n=read();
	fr(i,1,n)a[i]=read();
	fr(i,1,n)m[i]=a[i]+1;
	fd(i,n-1,1)m[i]=max(m[i],m[i+1]-1);
	fr(i,2,n)m[i]=max(m[i],m[i-1]);
	fr(i,1,n)ans=ans+m[i]-a[i]-1;
	printf("%I64d\n",ans);
	return 0;
}