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
#define N 20
long long ans,n=14,a[N],b[N];
int main()
{
	fr(i,1,n)a[i]=read();
	fr(i,1,n)
		if(a[i]&1)
		{
			fr(j,1,n)b[j]=a[j];
			b[i]=0;
			fr(j,1,a[i]%n)b[(i+j-1)%n+1]++;
			fr(j,1,n)b[j]+=a[i]/n;
//			fr(i,1,n)printf("%d%c",b[i],i==n?'\n':' ');
			long long th=0;
			fr(i,1,n)th+=((b[i]^1)&1)*b[i];
			ans=max(ans,th);
		}
	printf("%I64d\n",ans);
	return 0;
}