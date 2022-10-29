/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-09-17 09:59:39
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
#include<queue>
#define i64 long long
#define pii std::pair<i64,i64>
std::priority_queue<pii> q;
const int N=1000010;
i64 n,a[N],p[N],m;
i64 Query(i64 a,i64 b)
{
	i64 x=a/b,y=a-(a/b)*b,z=b-y;
	return y*(x+1)*(x+1)+z*x*x;
}
i64 query(i64 a,i64 b)
{
	if(a==b) return -1ll<<60;
	return Query(a,b)-Query(a,b+1);
}
int main()
{
	n=read(); m=read();
	fr(i,1,n) a[i]=read();
	i64 ans=0;
	fr(i,1,n){ p[i]=1; ans+=a[i]*a[i]; q.push(pii(query(a[i],p[i]),i)); }
	fr(i,1,m-n)
	{
		pii t=q.top();
		ans-=t.first;
		int j=t.second;
		p[j]++; q.pop(); q.push(pii(query(a[j],p[j]),j));
	}
	printf("%I64d\n",ans);
	return 0;
}