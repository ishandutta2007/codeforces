/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-08 16:29:58
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
#include<bitset>
const int N=160;
int n,m;
std::pair<int,std::pair<int,int> > e[N];
int ans;
struct mat
{
	std::bitset<N> h[N],l[N];
	void clear(){ fr(i,0,N-1){ h[i].reset(); l[i].reset(); } }
	mat(){ clear(); }
	void set(int x,int y,int v=1){ h[x][y]=l[y][x]=v; }
	mat &operator=(mat b)
	{
		clear();
		fr(i,1,n) fr(j,1,n) if(int(b.h[i][j])) set(i,j,int(b.h[i][j]));
		return *this;
	}
	void print()
	{
		fr(i,1,n) fr(j,1,n) printf("%d%c",int(h[i][j]),j==n?'\n':' ');
	}
}A,B;
mat operator*(mat a,mat b)
{
	mat c;
	fr(i,1,n) fr(j,1,n) c.set(i,j,(a.h[i]&b.l[j]).any());
	return c;
}
mat operator|(mat a,mat b)
{
	mat c;
	fr(i,1,n) fr(j,1,n) c.set(i,j,a.h[i][j]||b.h[i][j]);
	return c;
}
mat &operator|=(mat &a,mat b){ return a=a|b; }
mat &operator*=(mat &a,mat b){ return a=a*b; }
mat operator^(mat a,int b)
{
	mat r;
//	a.print(); printf("%d\n",b);
	fr(i,1,n) r.set(i,i,1);
	for(;b;b>>=1,a*=a) if(b&1) r*=a;
//	(r=r*a).print();
	return r;
}
mat operator|(mat a,int b)
{
	mat r;
//	a.print(); printf("%d\n",b);
	fr(i,1,n) r.set(i,i,1);
	for(;b;b>>=1,a|=a*a) if(b&1) r|=r*a;
//	(r=r*a).print();
	return r;
}
mat& operator^=(mat a,int b){ return a=a^b; }
const int inf=2000000000;
int solve(int d)
{
//	printf("%d\n",d);
//	A.print(); B.print();
	mat a=A;
	fr(i,1,n)
	{
		a*=B;
//		a.print();
		if(a.h[1][n]) return i+d;
	}
	return inf;
}
int main()
{
	n=read(); A.set(1,1); m=read();
	fr(i,1,m){ int x=read(),y=read(),z=read(); e[i]=std::make_pair(z,std::make_pair(x,y)); }
	std::sort(e+1,e+m+1);
	ans=inf;
	fr(i,1,m)
	{
		if((A*(B|(e[i].first-e[i-1].first))).h[1][n]){ ans=solve(e[i-1].first); printf("%d\n",ans); return 0; }
		A*=B^(e[i].first-e[i-1].first);
//		printf("%d %d\n",e[i].second.first,e[i].second.second);
		B.set(e[i].second.first,e[i].second.second);
//		printf("%d\n",solve(0));
//		B.print();
	}
	ans=std::min(ans,solve(e[m].first));
	if(ans==inf) printf("Impossible\n");
	else printf("%d\n",ans);
	return 0;
}