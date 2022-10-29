/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-08 09:10:45
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
const int N=100010;
int n,m,k;
i64 h[N],a[N],p;
struct bamboo
{
	i64 h,id;
	bamboo(i64 H=0,i64 I=0){ h=H; id=I; }
};
int operator<(bamboo x,bamboo y)
{
	return x.h/a[x.id]>y.h/a[y.id];
}
std::priority_queue<bamboo> q;
int check(i64 H)
{
	while(!q.empty()) q.pop();
	fr(i,1,n) if(H-a[i]*m<h[i]) q.push(bamboo(H,i));
	if(q.empty()) return 1;
//	fprintf(stderr, "%I64d %d\n",H,int(q.size()));
	fr(i,1,m)
	{
		bamboo t=q.top();
		if(t.h-i*a[t.id]<0) return 0;
		fr(j,1,k)
		{
			bamboo t=q.top(); q.pop();
			t.h+=p;
			if(t.h-a[t.id]*m<h[t.id]) q.push(t);
			if(q.empty()) return 1;
		}
	}
//	fprintf(stderr, "%I64d %d\n",H,int(q.size()));
	return 0;
}
int main()
{
	n=read(); m=read(); k=read(); p=read();
	fr(i,1,n){ h[i]=read(); a[i]=read(); }
	i64 l=0,r=1ll<<60;
	while(l<r)
	{
		i64 mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%I64d\n",r);
	return 0;
}