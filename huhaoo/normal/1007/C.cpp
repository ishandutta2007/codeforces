#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
i64 read()
{
	i64 r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
std::mt19937 Rand(48961523);
#ifdef huhao
int op=1;
#else
int op=0;
#endif
i64 n,vx,vy,cnt;
int query(i64 x,i64 y)
{
	assert(++cnt<=10000);
	i64 ans;
	if(!op){ printf("%I64d %I64d\n",x,y); fflush(stdout); ans=read(); }
	else
	{
		int a[3]={0,0,0},A=0;
		if(x<vx) a[A++]=1; else if(x>vx) a[A++]=3;
		if(y<vy) a[A++]=2; else if(y>vy) a[A++]=3;
		if(!A) ans=0;
		else ans=a[Rand()%A];
//		printf("%d  %d %d\n",A,a[0],a[1]);
//		printf("%I64d %I64d => %I64d\n",x,y,ans);
	}
	if(!ans)
	{
		fprintf(stderr,"Query %d times.\n",cnt);
		exit(0);
	}
	return ans;
}
void solve(i64,i64,i64,i64);
void solve(i64,i64,i64,i64,i64,i64);
i64 Mid(i64 l,i64 r,i64 a,i64 b){ return l+(r-l)/b*a; }
const i64 a=2,b=10;
void solve(i64 x1,i64 y1,i64 x2,i64 y2)
{
	assert(x1<=x2&&y1<=y2);
	i64 xm=Mid(x1,x2,a,b),ym=Mid(y1,y2,a,b);
	i64 op=query(xm,ym);
	if(op==1) solve(xm+1,y1,x2,y2);
	else if(op==2) solve(x1,ym+1,x2,y2);
	else solve(x1,y1,x2,y2,xm-1,ym-1);
}
void solve(i64 x1,i64 y1,i64 x2,i64 y2,i64 x3,i64 y3)
{
//	printf("%I64d %I64d %I64d %I64d %I64d %I64d\n",x1,y1,x2,y2,x3,y3);
	if(x3<x1){ solve(x1,y1,x2,y3); return ; }
	if(y3<y1){ solve(x1,y1,x3,y2); return ; }
	i64 xm=Mid(x1,x3,b-a,b),ym=Mid(y1,y3,b-a,b);
	i64 op=query(xm,ym);
	if(op==1) solve(xm+1,y1,x2,y2,x3,y3);
	else if(op==2) solve(x1,ym+1,x2,y2,x3,y3);
	else solve(x1,y1,x2,y2,xm-1,ym-1);
}
int main()
{
	n=read(); if(op){ vx=read(); vy=read(); }
	solve(1,1,n,n); assert(0);
	return 0;
}