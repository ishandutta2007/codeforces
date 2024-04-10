#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
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
const int N=100010;
int t,n;
i64 d[N],ans;
int main()
{
	t=read();
	while(t--)
	{
		n=read(); ans=0;
		fr(i,1,n) d[i]=read();
		std::sort(d+1,d+n+1);
		fr(i,1,n) ans-=d[i]*((i-1)-(n-i));
		ans+=d[n]; printf("%I64d\n",ans);
	}
	return 0;
}